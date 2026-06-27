import ColyPythonSync
import sys
argv=sys.argv
if not ColyPythonSync.InitColySyncService(argv):
    exit()
for i in range(128):
    ColyPythonSync.ColySyncString("ASCII["+str(i)+"]",str(chr(i)))