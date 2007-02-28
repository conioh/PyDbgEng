// EventCallbacksProxy.h : Declaration of the CEventCallbacksProxy

#ifndef __EVENTCALLBACKSPROXY_H_
#define __EVENTCALLBACKSPROXY_H_

#include "resource.h"       // main symbols
#include "DbgEventProxyCP.h"

/////////////////////////////////////////////////////////////////////////////
// CEventCallbacksProxy
class ATL_NO_VTABLE CEventCallbacksProxy : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEventCallbacksProxy, &CLSID_EventCallbacksProxy>,
	public IConnectionPointContainerImpl<CEventCallbacksProxy>,
	public IDispatchImpl<IEventCallbacksProxy, &IID_IEventCallbacksProxy, &LIBID_DBGEVENTPROXYLib>,
	public CProxy_IEventCallbacksProxyEvents< CEventCallbacksProxy >
{
public:
	CEventCallbacksProxy()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_EVENTCALLBACKSPROXY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CEventCallbacksProxy)
	COM_INTERFACE_ENTRY(IEventCallbacksProxy)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CEventCallbacksProxy)
CONNECTION_POINT_ENTRY(DIID__IEventCallbacksProxyEvents)
END_CONNECTION_POINT_MAP()


// IEventCallbacksProxy
public:
	STDMETHOD(CreateIDebugEventCallbacks)(/*[in]*/ ULONG InterestMask, /*[out, retval]*/ IUnknown** IDebugEventCallbacksPtr);
};

#endif //__EVENTCALLBACKSPROXY_H_
