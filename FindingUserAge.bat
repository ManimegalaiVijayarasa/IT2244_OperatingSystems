@echo off

set /p birthyear=Enter your birth year:
set /a age=%date:~10,4% - %birthyear%
echo Your age is %age% years

pause