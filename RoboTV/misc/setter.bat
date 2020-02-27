@echo off

set targetdir=%~1
set origindir=%~2
set resdir=%~3

xcopy "%origindir%" "%targetdir%" /E /Y /S
xcopy "%resdir%" "%targetdir%\res\assets\" /E /Y /S