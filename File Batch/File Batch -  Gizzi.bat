@echo off
set /p CARTELLA=Inserisci la cartella da cui copiare i file:
if not exist "%CARTELLA%" (
	echo ERRORE: La cartella non esiste. Procedo a crearla.
	mkdir "%CARTELLA%"
	echo Cartella creata con successo.
)

set /p DESTINAZIONE=Inserisci la cartella di destinazione per i file copiati:
if not exist "%DESTINAZIONE%" (
	echo La cartella di destinazione non esiste. Procedo a crearla.
	mkdir "%DESTINAZIONE%"
	echo Cartella di destinazione creata con successo.
)

echo Procedo a copiare i file
copy "%CARTELLA%\*.txt" "%DESTINAZIONE%"