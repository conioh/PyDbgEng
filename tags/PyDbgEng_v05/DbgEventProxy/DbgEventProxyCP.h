#ifndef _DBGEVENTPROXYCP_H_
#define _DBGEVENTPROXYCP_H_

template <class T>
class CProxy_IEventCallbacksProxyEvents : public IConnectionPointImpl<T, &DIID__IEventCallbacksProxyEvents, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:
	HRESULT Fire_Breakpoint(unsigned __int64 Offset, ULONG Id, ULONG BreakType, ULONG ProcType, ULONG Flags, ULONG DataSize, ULONG DataAccessType, ULONG PassCount, ULONG CurrentPassCount, ULONG MatchThread, ULONG CommandSize, ULONG OffsetExpressionSize)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[12];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[11] = Offset;
				pvars[10] = Id;
				pvars[9] = BreakType;
				pvars[8] = ProcType;
				pvars[7] = Flags;
				pvars[6] = DataSize;
				pvars[5] = DataAccessType;
				pvars[4] = PassCount;
				pvars[3] = CurrentPassCount;
				pvars[2] = MatchThread;
				pvars[1] = CommandSize;
				pvars[0] = OffsetExpressionSize;
				DISPPARAMS disp = { pvars, NULL, 12, 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_Exception(ULONG ExceptionCode, ULONG ExceptionFlags, unsigned __int64 ExceptionRecord, unsigned __int64 ExceptionAddress, ULONG NumberParameters, unsigned __int64 ExceptionInformation0, unsigned __int64 ExceptionInformation1, unsigned __int64 ExceptionInformation2, unsigned __int64 ExceptionInformation3, unsigned __int64 ExceptionInformation4, unsigned __int64 ExceptionInformation5, unsigned __int64 ExceptionInformation6, unsigned __int64 ExceptionInformation7, unsigned __int64 ExceptionInformation8, unsigned __int64 ExceptionInformation9, unsigned __int64 ExceptionInformation10, unsigned __int64 ExceptionInformation11, unsigned __int64 ExceptionInformation12, unsigned __int64 ExceptionInformation13, unsigned __int64 ExceptionInformation14, ULONG FirstChance)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[21];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[20] = ExceptionCode;
				pvars[19] = ExceptionFlags;
				pvars[18] = ExceptionRecord;
				pvars[17] = ExceptionAddress;
				pvars[16] = NumberParameters;
				pvars[15] = ExceptionInformation0;
				pvars[14] = ExceptionInformation1;
				pvars[13] = ExceptionInformation2;
				pvars[12] = ExceptionInformation3;
				pvars[11] = ExceptionInformation4;
				pvars[10] = ExceptionInformation5;
				pvars[9] = ExceptionInformation6;
				pvars[8] = ExceptionInformation7;
				pvars[7] = ExceptionInformation8;
				pvars[6] = ExceptionInformation9;
				pvars[5] = ExceptionInformation10;
				pvars[4] = ExceptionInformation11;
				pvars[3] = ExceptionInformation12;
				pvars[2] = ExceptionInformation13;
				pvars[1] = ExceptionInformation14;
				pvars[0] = FirstChance;
				DISPPARAMS disp = { pvars, NULL, 21, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_CreateThread(unsigned __int64 Handle, unsigned __int64 DataOffset, unsigned __int64 StartOffset)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[2] = Handle;
				pvars[1] = DataOffset;
				pvars[0] = StartOffset;
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_ExitThread(ULONG ExitCode)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[1];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[0] = ExitCode;
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x4, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_CreateProcess(unsigned __int64 ImageFileHandle, unsigned __int64 Handle, unsigned __int64 BaseOffset, ULONG ModuleSize, const char * ModuleName, const char * ImageName, ULONG CheckSum, ULONG TimeDateStamp, unsigned __int64 InitialThreadHandle, unsigned __int64 ThreadDataOffset, unsigned __int64 StartOffset)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[11];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[10] = ImageFileHandle;
				pvars[9] = Handle;
				pvars[8] = BaseOffset;
				pvars[7] = ModuleSize;
				pvars[6] = ModuleName;
				pvars[5] = ImageName;
				pvars[4] = CheckSum;
				pvars[3] = TimeDateStamp;
				pvars[2] = InitialThreadHandle;
				pvars[1] = ThreadDataOffset;
				pvars[0] = StartOffset;
				DISPPARAMS disp = { pvars, NULL, 11, 0 };
				pDispatch->Invoke(0x5, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_ExitProcess(ULONG ExitCode)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[1];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[0] = ExitCode;
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x6, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_LoadModule(unsigned __int64 ImageFileHandle, unsigned __int64 BaseOffset, ULONG ModuleSize, const char * ModuleName, const char * ImageName, ULONG CheckSum, ULONG TimeDateStamp)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[7];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[6] = ImageFileHandle;
				pvars[5] = BaseOffset;
				pvars[4] = ModuleSize;
				pvars[3] = ModuleName;
				pvars[2] = ImageName;
				pvars[1] = CheckSum;
				pvars[0] = TimeDateStamp;
				DISPPARAMS disp = { pvars, NULL, 7, 0 };
				pDispatch->Invoke(0x7, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_UnloadModule(const char * ImageBaseName, unsigned __int64 BaseOffset)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[1] = ImageBaseName;
				pvars[0] = BaseOffset;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x8, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_SystemError(ULONG Error, ULONG Level)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[1] = Error;
				pvars[0] = Level;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x9, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_SessionStatus(ULONG Status)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[1];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[0] = Status;
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0xa, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_ChangeDebuggeeState(ULONG Flags, unsigned __int64 Argument)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[1] = Flags;
				pvars[0] = Argument;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0xb, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_ChangeEngineState(ULONG Flags, unsigned __int64 Argument)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[1] = Flags;
				pvars[0] = Argument;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0xc, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
	HRESULT Fire_ChangeSymbolState(ULONG Flags, unsigned __int64 Argument)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[1] = Flags;
				pvars[0] = Argument;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0xd, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
};

template <class T>
class CProxy_IOutputCallbacksProxyEvents : public IConnectionPointImpl<T, &DIID__IOutputCallbacksProxyEvents, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:
	HRESULT Fire_Output(ULONG Mask, const char * Text)
	{
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[1] = Mask;
				pvars[0] = Text;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	
	}
};
#endif