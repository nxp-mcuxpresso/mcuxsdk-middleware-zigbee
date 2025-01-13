/*
 * Copyright 2019, 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <errno/errno.h>
#include <toolchain.h>
#include <porting.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>
#include <bluetooth/services/wu.h>
#include <fsl_debug_console.h>

#include "board.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define DEVICE_NAME    CONFIG_BT_DEVICE_NAME
#define DEVICE_NAME_LEN    (sizeof(DEVICE_NAME) - 1)

#ifndef WIRELESS_UART_TASK_PRIORITY
#define WIRELESS_UART_TASK_PRIORITY 6
#endif

#ifndef WIRELESS_UART_TASK_STACK_SIZE
#define WIRELESS_UART_TASK_STACK_SIZE 2048
#endif

#undef PRINTF
#define PRINTF(...)
#define WIRELESS_UART_SENDING_BUFFER_LENGTH 64

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef struct _wireless_uart_peer_state
{
    struct bt_conn *conn;
    uint8_t* wait4SendingBuffer;
    volatile uint32_t wait4SendingLength;
} wireless_uart_peer_state_t;

typedef struct _wireless_uart_state
{
    serial_manager_callback_t serialManagerTxCb;
    void * serialManagerTxCbParam;
    serial_manager_callback_t serialManagerRxCb;
    void * serialManagerRxCbParam;
    uint8_t* orignialBuffer;
    volatile uint32_t orignialBufferLength;
    wireless_uart_peer_state_t peerCentral[CONFIG_BT_MAX_CONN];
    uint8_t peerCentralConnCount;
} wireless_uart_state_t;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
extern bool APP_IsZigbeeReady(void);

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
static void connected(struct bt_conn *conn, uint8_t err);
static void disconnected(struct bt_conn *conn, uint8_t reason);
static void wireless_uart_rx_callback(void *callbackParam,
                                               serial_manager_callback_message_t *message,
                                               serial_manager_status_t status);
#if CONFIG_BT_SMP
static void security_changed(struct bt_conn *conn, bt_security_t level, enum bt_security_err err);

static void auth_passkey_display(struct bt_conn *conn, unsigned int passkey);
static void auth_cancel(struct bt_conn *conn);
#endif

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
static const struct bt_data ad[] = {
    BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
    BT_DATA_BYTES(BT_DATA_UUID128_SOME, WIRELESS_UART_SERIVCE_UUID),
};

static const struct bt_data sd[] = {
    BT_DATA(BT_DATA_NAME_COMPLETE, DEVICE_NAME, DEVICE_NAME_LEN),
};

static struct bt_conn_cb conn_callbacks = {
    .connected = connected,
    .disconnected = disconnected,
#if CONFIG_BT_SMP
    .security_changed = security_changed,
#endif
};

#if CONFIG_BT_SMP
static struct bt_conn_auth_cb auth_cb_display = {
/*    .passkey_display = auth_passkey_display,*/
    .passkey_display = NULL,
    .passkey_entry = NULL,
    .cancel = auth_cancel,
};
#endif

wireless_uart_state_t g_WirelessUartState;

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
static void connected(struct bt_conn *conn, uint8_t err)
{
    char addr[BT_ADDR_LE_STR_LEN];
    struct bt_conn_info info;

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    if (err)
    {
        PRINTF("Failed to connect %s (err %u)\n", addr, err);
    }
    else
    {
        uint32_t i;
        int index = -1;

        err = bt_conn_get_info(conn, &info);
        if (err) {
            PRINTF("Failed to get info");
            return;
        }

        switch (info.role) {
        case BT_HCI_ROLE_PERIPHERAL:
            for (i = 0;i < CONFIG_BT_MAX_CONN;i++)
            {
                if (conn == g_WirelessUartState.peerCentral[i].conn)
                {
                    PRINTF("the connection 0x08X is attached\r\n", conn);
                    return;
                }
                else if (NULL == g_WirelessUartState.peerCentral[i].conn)
                {
                    if (-1 == index)
                    {
                        OSA_SR_ALLOC();

                        index = (int)i;

                        OSA_ENTER_CRITICAL();
                        g_WirelessUartState.peerCentral[index].conn = conn;
                        g_WirelessUartState.peerCentralConnCount++;
                        g_WirelessUartState.peerCentral[index].wait4SendingBuffer = g_WirelessUartState.orignialBuffer;
                        g_WirelessUartState.peerCentral[index].wait4SendingLength = g_WirelessUartState.orignialBufferLength;
                        OSA_EXIT_CRITICAL();
                    }
                }
                else
                {
                }
            }
            break;
        }

        if (-1 == index)
        {
            PRINTF("All connection slots are used\r\n");
            return;
        }
        bt_gatt_wu_connected(conn);
        PRINTF("Connected to %s\n", addr);
#if CONFIG_BT_SMP
        if(BT_HCI_ROLE_PERIPHERAL == info.role)
        {
            if (bt_conn_set_security(conn, BT_SECURITY_L2))
            {
                PRINTF("Failed to set security\n");
            }
        }
#endif
    }
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
    char addr[BT_ADDR_LE_STR_LEN];
    uint32_t i;
    uint8_t found = 0;

    for (i = 0;i < CONFIG_BT_MAX_CONN;i++)
    {
        if (conn == g_WirelessUartState.peerCentral[i].conn)
        {
            g_WirelessUartState.peerCentral[i].conn = NULL;
            g_WirelessUartState.peerCentralConnCount--;
            found = 1;
            break;
        }
        else
        {
        }
    }

    if (0 == found)
    {
        PRINTF("The connection 0x%08X is not found.\r\n", conn);
        return;
    }
    bt_gatt_wu_disconnected(conn);

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    PRINTF("Disconnected from %s (reason %u)\n", addr, reason);
}

#if CONFIG_BT_SMP
static void security_changed(struct bt_conn *conn, bt_security_t level, enum bt_security_err err)
{
    char addr[BT_ADDR_LE_STR_LEN];

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    PRINTF("Security changed: %s level %u (error %d)\n", addr, level, err);
}

static void auth_passkey_display(struct bt_conn *conn, unsigned int passkey)
{
    char addr[BT_ADDR_LE_STR_LEN];

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    PRINTF("Passkey for %s: %06u\n", addr, passkey);
}

static void auth_cancel(struct bt_conn *conn)
{
    char addr[BT_ADDR_LE_STR_LEN];

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    PRINTF("Pairing cancelled: %s\n", addr);
}
#endif

static int wireless_uart_data_received(struct bt_conn *conn, uint8_t* buffer, ssize_t length)
{
    serial_manager_callback_message_t message;
    serial_manager_status_t status = kStatus_SerialManager_Success;

    if (NULL != g_WirelessUartState.serialManagerRxCb)
    {
        message.buffer = buffer;
        message.length = length;
        g_WirelessUartState.serialManagerRxCb(g_WirelessUartState.serialManagerRxCbParam, &message, status);
    }

    return 0;
}

static int wireless_uart_read(struct bt_conn *conn, bt_gatt_wu_read_response_t response, void *param)
{
    uint32_t index;
    serial_manager_callback_message_t message;
    uint8_t* buffer;
    ssize_t length;
    int ret = -1;
    uint8_t txDone = 1U;
    OSA_SR_ALLOC();

    for (index = 0U;index < CONFIG_BT_MAX_CONN;index++)
    {
        if (conn == g_WirelessUartState.peerCentral[index].conn)
        {
            if (g_WirelessUartState.peerCentral[index].wait4SendingLength > 0U)
            {
                OSA_ENTER_CRITICAL();
                buffer = &g_WirelessUartState.peerCentral[index].wait4SendingBuffer[0];
                length = g_WirelessUartState.peerCentral[index].wait4SendingLength;
                if ((NULL != response))
                {
                    ret = response(param, buffer, length);
                    if (ret >= 0)
                    {
                        g_WirelessUartState.peerCentral[index].wait4SendingLength -= ret;
                        g_WirelessUartState.peerCentral[index].wait4SendingBuffer += ret;
                    }
                }
                OSA_EXIT_CRITICAL();
            }
            break;
        }
    }

    for (index = 0U;index < CONFIG_BT_MAX_CONN;index++)
    {
        if (NULL != g_WirelessUartState.peerCentral[index].conn)
        {
            if (g_WirelessUartState.peerCentral[index].wait4SendingLength > 0U)
            {
                txDone = 0U;
            }
        }
    }

    if (txDone > 0U)
    {
        message.buffer = g_WirelessUartState.orignialBuffer;
        message.length = g_WirelessUartState.orignialBufferLength;
        g_WirelessUartState.orignialBuffer = NULL;
        g_WirelessUartState.orignialBufferLength = 0U;
        for (index = 0U;index < CONFIG_BT_MAX_CONN;index++)
        {
            g_WirelessUartState.peerCentral[index].wait4SendingBuffer = NULL;
            g_WirelessUartState.peerCentral[index].wait4SendingLength = 0U;
        }
        if (NULL != g_WirelessUartState.serialManagerTxCb)
        {
            serial_manager_status_t status = kStatus_SerialManager_Success;
            g_WirelessUartState.serialManagerTxCb(g_WirelessUartState.serialManagerTxCbParam, &message, status);
        }
    }
    return ret;
}

static void bt_ready(int error)
{
    bt_gatt_wu_config_t wuConfig;
    if (error)
    {
        PRINTF("Bluetooth init failed (error %d)\n", error);
        return;
    }

#if (defined(CONFIG_BT_SETTINGS) && (CONFIG_BT_SETTINGS > 0))
    settings_load();
#endif /* CONFIG_BT_SETTINGS */

    PRINTF("Bluetooth initialized\n");

    wuConfig.data_received = wireless_uart_data_received;
    wuConfig.read = wireless_uart_read;

    bt_gatt_wu_init("Wireless Uart Demo", "WU1234567890", &wuConfig);

    bt_conn_cb_register(&conn_callbacks);
#if CONFIG_BT_SMP
    bt_conn_auth_cb_register(&auth_cb_display);
#endif

    error = bt_le_adv_start(BT_LE_ADV_CONN, ad, ARRAY_SIZE(ad), sd, ARRAY_SIZE(sd));
    if (error)
    {
        PRINTF("Advertising failed to start (error %d)\n", error);
        return;
    }
    PRINTF("Advertising successfully started\n");
}

/*
 * @brief   Application entry point.
 */
void wireless_uart_task(void *argument)
{
    uint32_t index;
    int err;

    for (index = 0;index < CONFIG_BT_MAX_CONN;index++)
    {
        g_WirelessUartState.peerCentral[index].wait4SendingBuffer = NULL;
        g_WirelessUartState.peerCentral[index].wait4SendingLength = 0;
    }

    g_WirelessUartState.orignialBuffer = NULL;
    g_WirelessUartState.orignialBufferLength = 0;
    while (true)
    {
        if(APP_IsZigbeeReady())
        {
            break;
        }
        else
        {
            vTaskDelay(10);
        }
    }
    err = bt_enable(bt_ready);
    if (err)
    {
        PRINTF("Bluetooth init failed (err %d)\n", err);
        while (1)
        {
            vTaskDelay(2000);
        }
    }

    while (USE_RTOS)
    {
        vTaskDelay(10);
        /* Wireless Uart notification thread */
        bt_gatt_wu_notify(NULL);
    }
}

/****************************************************************************/
/***        Public functions                                              ***/
/****************************************************************************/
status_t BLE_WuInit(void);
status_t BLE_WuInit(void)
{
    status_t ret = kStatus_Success;
    if (xTaskCreate(wireless_uart_task, "wu_task", configMINIMAL_STACK_SIZE * 8, NULL, tskIDLE_PRIORITY + 2, NULL) != pdPASS)
    {
        ret = kStatus_Fail;
    }

    return ret;
}

status_t BLE_WuDeinit(void);
status_t BLE_WuDeinit(void)
{
    return kStatus_Success;
}

status_t BLE_WuWrite(uint8_t *buffer, uint32_t length);
status_t BLE_WuWrite(uint8_t *buffer, uint32_t length)
{
    OSA_SR_ALLOC();

    OSA_ENTER_CRITICAL();
    for (int index = 0;index < CONFIG_BT_MAX_CONN;index++)
    {
        if (NULL != g_WirelessUartState.peerCentral[index].conn)
        {
            g_WirelessUartState.peerCentral[index].wait4SendingBuffer = buffer;
            g_WirelessUartState.peerCentral[index].wait4SendingLength = length;
        }
    }
    g_WirelessUartState.orignialBuffer = buffer;
    g_WirelessUartState.orignialBufferLength = length;
    OSA_EXIT_CRITICAL();
    return kStatus_Success;
}

status_t BLE_WuRead(uint8_t *buffer, uint32_t length);
status_t BLE_WuRead(uint8_t *buffer, uint32_t length)
{
    return kStatus_Fail;
}

status_t BLE_WuInstallTxCallback(serial_manager_callback_t callback,
                                                     void *callbackParam);
status_t BLE_WuInstallTxCallback(serial_manager_callback_t callback,
                                                     void *callbackParam)
{
    g_WirelessUartState.serialManagerTxCb = callback;
    g_WirelessUartState.serialManagerTxCbParam = callbackParam;
    return kStatus_Success;
}

status_t BLE_WuInstallRxCallback(serial_manager_callback_t callback,
                                                     void *callbackParam);
status_t BLE_WuInstallRxCallback(serial_manager_callback_t callback,
                                                     void *callbackParam)
{
    g_WirelessUartState.serialManagerRxCb = callback;
    g_WirelessUartState.serialManagerRxCbParam = callbackParam;
    return kStatus_Success;
}
