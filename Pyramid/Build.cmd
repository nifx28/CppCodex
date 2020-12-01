@echo off
title ¸ü¤J¤¤...
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64 > nul
title Visual Studio 2019 %__VSCMD_BANNER_SHELL_NAME% v%VSCMD_VER%
set CL=/nologo /std:c++latest /Wall /WX /EHsc /Ox /errorReport:none
set _CL_=Pyramid.cpp
set _CL_=%_CL_% /link /WX /ERRORREPORT:none
:repeat
cls
cl.exe && (cls & echo cl %CL% %_CL_%& echo.& Pyramid.exe)
pause
goto repeat
endlocal
exit /b
