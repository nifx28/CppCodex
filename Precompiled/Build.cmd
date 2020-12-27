@echo off
title ¸ü¤J¤¤...
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64 > nul
title Visual Studio 2019 %__VSCMD_BANNER_SHELL_NAME% v%VSCMD_VER%
set CL=/nologo /std:c++latest /Wall /WX /EHsc /Ox /errorReport:none
set PCH=/c /Yc"Precompiled.h"
set LINK=/WX /ERRORREPORT:none
cls
set _CL_=Precompiled.cpp
echo cl %PCH% %_CL_%
echo.
cl.exe %PCH% || goto error
:repeat
cls
set _CL_=GreatPyramid.cpp PyramidToolset.cpp
set _CL_=%_CL_% /Yu"Precompiled.h" Precompiled.obj
echo cl %CL% %_CL_%
echo.
cl.exe || goto error
cls
GreatPyramid.exe
rem < PyramidTester.txt
:error
pause
goto repeat
endlocal
exit /b
