@echo off
cls

set pari=0
set dispari=0

:input
set /p numero=Inserisci un numero:

if %numero%==0 goto fine

set /a mod=%numero% %% 2

if %mod%==0 (
	set /a pari+=1
	) else (
	set /a dispari+=1
	)
	
goto input

:fine
echo Hai inserito %pari% numeri pari e %dispari% numeri dispari
pause
