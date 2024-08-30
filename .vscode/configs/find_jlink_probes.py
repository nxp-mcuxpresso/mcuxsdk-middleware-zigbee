import re
import subprocess
import os

if __name__ == '__main__':
    if os.name == 'nt':
        jlink_executable = 'JLink.exe'
    else:
        jlink_executable = 'JLinkExe'
    f = open("jlink_setup.cfg", "w")
    res = subprocess.run([jlink_executable, '-commandfile', 'get_serial_numbers.jlink'], stdout=subprocess.PIPE)
    output = res.stdout.decode('utf-8')
    print(output)
    matches = re.findall(".*J-Link\[\d\].*Serial number: (.*\d), ProductName: (.*[^\r\n])", output, re.MULTILINE)
    for match in matches:
        serial_number = match[0]
        name = match[1]
        f.write(name + "=" + serial_number + '\n')
    f.close()
    f = open("jlink_setup.cfg", "r")
    print("J-Link probes found:")
    print(f.read())
