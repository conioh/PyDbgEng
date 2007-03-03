python comtypes_gen.py "..\DbgEngTlb\out\DbgEng.tlb" "..\DbgEventProxy\DbgEventProxy.tlb"
python comtypes_copy.py ..\Support\comtypes\automation.py automation
python comtypes_copy.py ..\Support\comtypes\client\__init__.py  client\__init__
regsvr32 /c "..\DbgEventProxy\Release\DbgEventProxy.dll"
pause
