# Appendix A: Mutex callbacks

The mutexes are designed such that a call to **ZPS\_u8GrabMutexLock\(\)** must be followed by a call to **ZPS\_u8ReleaseMutexLock\(\)**. In addition, the call must not be followed by another call to **ZPS\_u8GrabMutexLock\(\)**, which means the mutexes are binary rather than counting. This can cause problems if the ZCL takes a mutex via the callback function and then the application wants to lock the mutex to access the shared device structures. Some ZCL clusters also invoke the callback function with E\_ZCL\_CBET\_LOCK\_MUTEX multiple times. The counting mutex code below should be used in the application code. When the application wants to access the shared structure, it should call the **vLockZCLMutex\(\)** function \(shown in the code extract below\), rather than **ZPS\_u8GrabMutexLock\(\)**, so that it also participates in the counting mutex rather than directly taking the binary ZPS mutex-protection. Similarly, the shared structure should be released using **vUnlockZCLMutex\(\)**.

The code below uses a single resource for all endpoints and the general callback function. It defines a file scope counter that is the mutex count related to the resource.

At the top of the application source file, create the count and lock/unlock mutex function prototypes \(these prototypes may be placed in a header file, if desired\):

```
uint32  u32ZCLMutexCount  =  0;
void  vLockZCLMutex(void);
void  vUnlockZCLMutex(void);
                

```

In both **cbZCL\_GeneralCallback\(\)** and **cbZCL\_EndpointCallback\(\)**, make the calls:

```
switch(psEvent->eEventType)
 {
 case  E_ZCL_CBET_LOCK_MUTEX:
              vLockZCLMutex();
            break;
      case  E_ZCL_CBET_UNLOCK_MUTEX:
        vUnlockZCLMutex();
            break;

```

Define the lock/unlock mutex functions and call them from the application when accessing any ZCL shared structure:

```
void  vLockZCLMutex(void)
{
        if  (u32ZCLMutexCount  ==  0)
        {
                ZPS_u8GrabMutexLock(mutexZCL,0);
        }
        u32ZCLMutexCount++;
}
void  vUnlockZCLMutex(void)
{
        u32ZCLMutexCount--;
        if  (u32ZCLMutexCount  ==  0)
        {
                ZPS_u8ReleaseMutexLock(mutexZCL,0);
        }
}

```

