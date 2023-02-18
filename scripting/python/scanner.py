#!/bin/python3

import sys
import socket
from datetime import datetime

# Define our target

if len(sys.argv) == 2:
    target = socket.gethostbyname(sys.argv[1]) # Get IPv4 from hostname
else:
    print("Invalid amount of args")
    print("Syntax: python3 scanner.py <ip>")
    sys.exit(1)


print("-" * 50)
print("Scanning target " + target)
print("Time start: " + str(datetime.now()))
print("-" * 50)

try:
    for port in range(50, 85):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        socket.setdefaulttimeout(1)
        result = s.connect_ex((target, port))
        print("Checking port {}".format(port))
        if result = 0:
            print("Port {} is open".format(port))
        s.close()

except KeyboardInterrupt:
    print("\nExiting Program.")
    sys.exit(1)

except socket.gaierror:
    print("Hostname could not be resolved")
    sys.exit(1)

except socket.error:
    print("Couldn't connect to server.")
    sys.exit(1)
