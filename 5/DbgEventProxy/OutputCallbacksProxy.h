// OutputCallbacksProxy.h : Declaration of the COutputCallbacksProxy

#ifndef __OUTPUTCALLBACKSPROXY_H_
#define __OUTPUTCALLBACKSPROXY_H_

#include "resource.h"       // main symbols
#include "DbgEventProxyCP.h"

/////////////////////////////////////////////////////////////////////////////
// COutputCallbacksProxy
class ATL_NO_VTABLE COutputCallbacksProxy : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COutputCallbacksProxy, &CLSID_OutputCallbacksProxy>,
	public IConnectionPointContainerImpl<COutputCallbacksProxy>,
	public IDispatchImpl<IOutputCallbacksProxy, &IID_IOutputCallbacksProxy, &LIBID_DBGEVENTPROXYLib>,
	public CProxy_IOutputCallbacksProxyEvents< COutputCallbacksProxy >
{
public:
	COutputCallbacksProxy()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_OUTPUTCALLBACKSPROXY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COutputCallbacksProxy)
	COM_INTERFACE_ENTRY(IOutputCallbacksProxy)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(COutputCallbacksProxy)
CONNECTION_POINT_ENTRY(DIID__IOutputCallbacksProxyEvents)
END_CONNECTION_POINT_MAP()


// IOutputCallbacksProxy
public:
	STDMETHOD(CreateIDebugOutputCallbacks)(/*[out, retval]*/ IUnknown** IDebugOutputCallbacksPtr);
};

#endif //__OUTPUTCALLBACKSPROXY_H_
