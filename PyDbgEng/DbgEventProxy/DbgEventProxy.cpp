// DbgEventProxy.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f DbgEventProxyps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "DbgEventProxy.h"

#include "DbgEventProxy_i.c"
#include "EventCallbacksProxy.h"
#include "OutputCallbacksProxy.h"


CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_EventCallbacksProxy, CEventCallbacksProxy)
OBJECT_ENTRY(CLSID_OutputCallbacksProxy, COutputCallbacksProxy)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
		/////////////////////////////////////////////////////////////////////////////
		// hack hack ////////////////////////////////////////////////////////////////
		// Prevent our dll from unloading by increasing its reference count.
		// This is required because ctypes always keeps a pointer to our event
		// proxy canon, located inside our code section
		// We can fix that by calling IdebugClient.SetEventCallbacks() with the previous
		// value it had (use IdebugClient.GetEventCallbacks()). Still, this work-around is 
		// safer.
		char me[MAX_PATH];
		me[0] = '\0';
		if (GetModuleFileName(hInstance, me, sizeof(me)))
		{
			LoadLibrary(me);
		}
		// hack hack ////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////

        _Module.Init(ObjectMap, hInstance, &LIBID_DBGEVENTPROXYLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}


