// OutputCallbacksProxy.cpp : Implementation of COutputCallbacksProxy
#include "stdafx.h"
#include "DbgEventProxy.h"
#include "OutputCallbacksProxy.h"
#include "DbgEng.h"

/////////////////////////////////////////////////////////////////////////////
class OutputCallbacksEventCanon : public IDebugOutputCallbacks
{
private:
	COutputCallbacksProxy* _self;
	long _ref_count;

public:
	/////////////////////////////////////////////////////////////////////////////
	OutputCallbacksEventCanon(COutputCallbacksProxy* self) :
	  _self(self),
	  _ref_count(0)
	{
		AddRef();
	}

	/////////////////////////////////////////////////////////////////////////////
    virtual ~OutputCallbacksEventCanon()
	{
	}

public:
	/////////////////////////////////////////////////////////////////////////////
    // IUnknown.
    STDMETHOD_(ULONG, AddRef)(
        THIS
        )
	{
		InterlockedIncrement(&_ref_count);
		return _ref_count;
	}

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD_(ULONG, Release)(
        THIS
        )
	{
		InterlockedDecrement(&_ref_count);
		if (_ref_count == 0)
		{
			delete this;
			return 0;
		}
		return _ref_count;
	}

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(QueryInterface)(
        THIS_
        __in REFIID InterfaceId,
        __out PVOID* Interface
        )
    {
        *Interface = NULL;

#if _MSC_VER >= 1100
        if (IsEqualIID(InterfaceId, __uuidof(IUnknown)) ||
            IsEqualIID(InterfaceId, __uuidof(IDebugEventCallbacks)))
#else
        if (IsEqualIID(InterfaceId, IID_IUnknown) ||
            IsEqualIID(InterfaceId, IID_IDebugEventCallbacks))
#endif
        {
            *Interface = (IDebugEventCallbacks *)this;
            AddRef();
            return S_OK;
        }
        else
        {
            return E_NOINTERFACE;
        }
    }

	/////////////////////////////////////////////////////////////////////////////
    // IDebugOutputCallbacks.

    // This method is only called if the supplied mask
    // is allowed by the clients output control.
    // The return value is ignored.
    STDMETHOD(Output)(
        THIS_
        __in ULONG Mask,
        __in PCSTR Text
        )
	{
		__try
		{
			return _self->Fire_Output(Mask, Text);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
	}
};

/////////////////////////////////////////////////////////////////////////////
// COutputCallbacksProxy

STDMETHODIMP COutputCallbacksProxy::CreateIDebugOutputCallbacks(IUnknown **IDebugOutputCallbacksPtr)
{
	*IDebugOutputCallbacksPtr = new OutputCallbacksEventCanon(this);
	return S_OK;
}
