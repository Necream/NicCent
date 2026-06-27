import ColyPythonSync
import time
from datetime import datetime
import sys
argv=sys.argv
if not ColyPythonSync.InitColySyncService(argv) :
    print("Can not link to Server")
    exit()
while True:
    if ColyPythonSync.ReadColyVar("NicCent:MainCloseSign").data == "true":
        exit()
    if ColyPythonSync.ReadColyVar("NicCentFramework:Logger:OutputReady").data == "true":
        print("[",datetime.now(),"] ",ColyPythonSync.ReadColyVar("NicCentFramework:Logger:Content"),sep='',flush=True)
        ColyPythonSync.RegColyVar("NicCentFramework:Logger:OutputReady")
    time.sleep(0.1)