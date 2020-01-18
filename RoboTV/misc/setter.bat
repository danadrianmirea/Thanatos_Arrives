@echo off

set targetdir=%~1
set origindir=%~2

xcopy "%origindir%" "%targetdir%" /E /Y /S