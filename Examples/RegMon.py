import sys
sys.path.append("..")

import PyDbgEng
import threading
import struct
import getopt

###########################################################
# defines
###########################################################

USAGE = "USAGE: RegMon.py <-l|--load filename>"

ERROR = lambda msg: sys.stderr.write("ERROR> " + msg + "\n") or sys.exit(1)

###########################################################
# NtOpenKey
###########################################################
def NtOpenKey_at_entry(dbg, args):
    (root_handle, key_name) = dbg.read_object_attributes( args[2] )
    try:
        root_key_name = dbg.get_handle_data( root_handle )
        key_name = root_key_name + "\\" + key_name
    except:
        pass
    sys.stdout.write( "NtOpenKey(): key_name: \"%s\"\n" % key_name )

###########################################################
# NtQueryValueKey
###########################################################
def NtQueryValueKey_at_entry(dbg, args):
    key_name = dbg.get_handle_data(args[0])
    value_name = dbg.read_unicode_string(args[1])
    sys.stdout.write( "NtQueryValueKey(): reading \"%s\" from \"%s\"\n" % (value_name, key_name) )
    
###########################################################
# PyDbgEng Event Handler
###########################################################
class DbgEventHandler(PyDbgEng.IDebugOutputCallbacksSink, PyDbgEng.IDebugEventCallbacksSink):

    ###########################################################
    # IDebugOutputCallbacksSink
    ###########################################################
    def Output(self, this, Mask, Text):
        sys.stdout.write(Text)

    ###########################################################
    # IDebugEventCallbacksSink
    ###########################################################
    def GetInterestMask(self):
        return PyDbgEng.DbgEng.DEBUG_EVENT_LOAD_MODULE

    def LoadModule(self, dbg, ImageFileHandle, BaseOffset, ModuleSize, ModuleName, ImageName, CheckSum, TimeDateStamp):
        if (ImageName.lower() == "ntdll.dll"):
            hooks.add( dbg, "ntdll!NtOpenKey",          3, NtOpenKey_at_entry,          None)
            hooks.add( dbg, "ntdll!NtQueryValueKey",    6, NtQueryValueKey_at_entry,    None)
        
        return PyDbgEng.DbgEng.DEBUG_STATUS_NO_CHANGE


###########################################################
# main
###########################################################
try:
    opts, args = getopt.getopt(sys.argv[1:], "l:", [])
except getopt.GetoptError:
    ERROR(USAGE)

filename = None
hooks    = PyDbgEng.Hooking.hook_container()

for opt, arg in opts:
    if opt in ("-l", "--load"):  filename = arg

if not filename:
    ERROR(USAGE)

event_handler = DbgEventHandler()
dbg = PyDbgEng.ProcessCreator(  command_line = filename, \
                                follow_forks = True, \
                                event_callbacks_sink = event_handler, \
                                output_callbacks_sink = event_handler, \
                                symbols_path = "SRV*http://msdl.microsoft.com/download/symbols")

quit_event = threading.Event()
dbg.event_loop_with_quit_event(quit_event)


