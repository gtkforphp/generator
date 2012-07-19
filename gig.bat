@echo off
SET GIG_PATH=%~dp0

REM if you need to change your PHP location, change this variable e.g.
REM SET PHP=C:\Program Files\php-5.4\php.exe
SET PHP=php.exe

%PHP% %GIG_PATH%\gig.php %*