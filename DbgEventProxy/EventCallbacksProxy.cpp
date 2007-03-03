// EventCallbacksProxy.cpp : Implementation of CEventCallbacksProxy
#include "stdafx.h"
#include "DbgEventProxy.h"
#include "EventCallbacksProxy.h"
#include "DbgEng.h"

/////////////////////////////////////////////////////////////////////////////
class EventCallbacksEventCanon : public IDebugEventCallbacks
{
private:
	CEventCallbacksProxy* _self;
	ULONG _interest_mask;
	long _ref_count;

public:
	/////////////////////////////////////////////////////////////////////////////
	EventCallbacksEventCanon(CEventCallbacksProxy* self, ULONG interest_mask) :
	  _self(self),
	  _interest_mask(interest_mask),
	  _ref_count(0)
	{
		AddRef();
	}

	/////////////////////////////////////////////////////////////////////////////
    virtual ~EventCallbacksEventCanon()
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
    // IDebugEventCallbacks.

	// The engine calls GetInterestMask once when
    // the event callbacks are set for a client.
    STDMETHOD(GetInterestMask)(
        THIS_
        __out PULONG Mask
        )
	{
		*Mask = _interest_mask;
		return S_OK;
	}

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(Breakpoint)(
        THIS_
        __in PDEBUG_BREAKPOINT Bp
        )
    {
		__try
		{
			DEBUG_BREAKPOINT_PARAMETERS bp_params;
			HRESULT hr = Bp->GetParameters(&bp_params);
			if (FAILED(hr))
				return DEBUG_STATUS_NO_CHANGE;

			return _self->Fire_Breakpoint(	bp_params.Offset, 
											bp_params.Id, 
											bp_params.BreakType, 
											bp_params.ProcType, 
											bp_params.Flags, 
											bp_params.DataSize, 
											bp_params.DataAccessType, 
											bp_params.PassCount, 
											bp_params.CurrentPassCount, 
											bp_params.MatchThread, 
											bp_params.CommandSize, 
											bp_params.OffsetExpressionSize);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(Exception)(
        THIS_
        __in PEXCEPTION_RECORD64 Exception,
        __in ULONG FirstChance
        )
    {
		__try
		{
			return _self->Fire_Exception(	Exception->ExceptionCode, 
											Exception->ExceptionFlags, 
											Exception->ExceptionRecord, 
											Exception->ExceptionAddress, 
											Exception->NumberParameters, 
											Exception->ExceptionInformation[0], 
											Exception->ExceptionInformation[1], 
											Exception->ExceptionInformation[2], 
											Exception->ExceptionInformation[3], 
											Exception->ExceptionInformation[4], 
											Exception->ExceptionInformation[5], 
											Exception->ExceptionInformation[6], 
											Exception->ExceptionInformation[7], 
											Exception->ExceptionInformation[8], 
											Exception->ExceptionInformation[9], 
											Exception->ExceptionInformation[10], 
											Exception->ExceptionInformation[11], 
											Exception->ExceptionInformation[12], 
											Exception->ExceptionInformation[13], 
											Exception->ExceptionInformation[14], 
											FirstChance);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(CreateThread)(
        THIS_
        __in ULONG64 Handle,
        __in ULONG64 DataOffset,
        __in ULONG64 StartOffset
        )
    {
		__try
		{
			return _self->Fire_CreateThread(Handle, DataOffset, StartOffset);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(ExitThread)(
        THIS_
        __in ULONG ExitCode
        )
    {
		__try
		{
			return _self->Fire_ExitThread(ExitCode);
   		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(CreateProcess)(
        THIS_
        __in ULONG64 ImageFileHandle,
        __in ULONG64 Handle,
        __in ULONG64 BaseOffset,
        __in ULONG ModuleSize,
        __in PCSTR ModuleName,
        __in PCSTR ImageName,
        __in ULONG CheckSum,
        __in ULONG TimeDateStamp,
        __in ULONG64 InitialThreadHandle,
        __in ULONG64 ThreadDataOffset,
        __in ULONG64 StartOffset
        )
    {
		__try
		{
			return _self->Fire_CreateProcess(	ImageFileHandle, 
												Handle, 
												BaseOffset, 
												ModuleSize, 
												ModuleName, 
												ImageName, 
												CheckSum, 
												TimeDateStamp, 
												InitialThreadHandle, 
												ThreadDataOffset, 
												StartOffset);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(ExitProcess)(
        THIS_
        __in ULONG ExitCode
        )
    {
		__try
		{
			return _self->Fire_ExitProcess(ExitCode);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(LoadModule)(
        THIS_
        __in ULONG64 ImageFileHandle,
        __in ULONG64 BaseOffset,
        __in ULONG ModuleSize,
        __in PCSTR ModuleName,
        __in PCSTR ImageName,
        __in ULONG CheckSum,
        __in ULONG TimeDateStamp
        )
    {
		__try
		{
			return _self->Fire_LoadModule(	ImageFileHandle, 
											BaseOffset, 
											ModuleSize, 
											ModuleName, 
											ImageName, 
											CheckSum, 
											TimeDateStamp);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(UnloadModule)(
        THIS_
        __in PCSTR ImageBaseName,
        __in ULONG64 BaseOffset
        )
    {
		__try
		{
			return _self->Fire_UnloadModule(ImageBaseName, BaseOffset);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(SystemError)(
        THIS_
        __in ULONG Error,
        __in ULONG Level
        )
    {
		__try
		{
			return _self->Fire_SystemError(Error, Level);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(SessionStatus)(
        THIS_
        __in ULONG Status
        )
    {
		__try
		{
			return _self->Fire_SessionStatus(Status);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(ChangeDebuggeeState)(
        THIS_
        __in ULONG Flags,
        __in ULONG64 Argument
        )
    {
		__try
		{
			return _self->Fire_ChangeDebuggeeState(Flags, Argument);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(ChangeEngineState)(
        THIS_
        __in ULONG Flags,
        __in ULONG64 Argument
        )
    {
		__try
		{
			return _self->Fire_ChangeEngineState(Flags, Argument);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }

	/////////////////////////////////////////////////////////////////////////////
    STDMETHOD(ChangeSymbolState)(
        THIS_
        __in ULONG Flags,
        __in ULONG64 Argument
        )
    {
		__try
		{
			return _self->Fire_ChangeSymbolState(Flags, Argument);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			return E_UNEXPECTED;
		}
    }
};

/////////////////////////////////////////////////////////////////////////////
// CEventCallbacksProxy

STDMETHODIMP CEventCallbacksProxy::CreateIDebugEventCallbacks(ULONG InterestMask, IUnknown **IDebugEventCallbacksPtr)
{
	*IDebugEventCallbacksPtr = new EventCallbacksEventCanon(this, InterestMask);
	return S_OK;
}
