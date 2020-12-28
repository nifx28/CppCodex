@echo off
title 載入中...
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64 > nul
title Visual Studio 2019 %__VSCMD_BANNER_SHELL_NAME% v%VSCMD_VER%
set CL=/nologo /std:c++latest /Wall /WX /I"Include" /Fo"Obj/" /EHsc /Ox /errorReport:none /Fp"Obj/"
set PCH=/c /Yc"Precompiled.h"
set LINK=/WX /ERRORREPORT:none
if not exist "%~dp0Bin" md "%~dp0Bin" || goto error
if not exist "%~dp0Obj" md "%~dp0Obj" || goto error
cls
set _CL_=Src/Precompiled.cpp
echo cl %PCH% %_CL_%
echo.
cl.exe %PCH% || goto error
:repeat
cls
set _CL_=Src/GreatPyramid.cpp Src/PyramidToolset.cpp
set _CL_=%_CL_% /Yu"Precompiled.h" Obj/Precompiled.obj /Fe"Bin/GreatPyramid"
echo cl %CL% %_CL_%
echo.
cl.exe || goto error
cls
rem PyramidTester.txt 需要使用 UTF-16LE 編碼。
Bin\GreatPyramid.exe < PyramidTester.txt
:error
pause
goto repeat
endlocal
exit /b
