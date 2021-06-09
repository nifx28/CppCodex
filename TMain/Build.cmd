@echo off
title 載入中...
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64 > nul
title Visual Studio 2019 %__VSCMD_BANNER_SHELL_NAME% v%VSCMD_VER%
set MACRO=/D_CONSOLE /D_UNICODE /D__STDC_WANT_SECURE_LIB__
rem 禁止使用 _CRT_SECURE_NO_WARNINGS
set MACRO=%MACRO% /D _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES#1
set MACRO=%MACRO% /D _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT#1
set CL=/nologo /std:c++latest /MTd %MACRO% /Wv:18 /Wall /WX /EHsc /Ox /errorReport:none
set _CL_=TMain.cpp /Fe"Test TMain"
set _CL_=%_CL_% /link /WX /ERRORREPORT:none
set INVOKE="Test TMain.exe" "123 " 456 789
:repeat
cls
cl.exe
if not "%errorlevel%"=="0" pause & goto repeat
(cls & echo cl %CL% %_CL_%& echo.& echo %INVOKE%& %INVOKE%)
goto repeat
endlocal
exit /b
