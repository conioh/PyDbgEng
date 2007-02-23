
DbgEventProxyps.dll: dlldata.obj DbgEventProxy_p.obj DbgEventProxy_i.obj
	link /dll /out:DbgEventProxyps.dll /def:DbgEventProxyps.def /entry:DllMain dlldata.obj DbgEventProxy_p.obj DbgEventProxy_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del DbgEventProxyps.dll
	@del DbgEventProxyps.lib
	@del DbgEventProxyps.exp
	@del dlldata.obj
	@del DbgEventProxy_p.obj
	@del DbgEventProxy_i.obj
