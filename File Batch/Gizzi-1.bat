@echo off

set desktop=%USERPROFILE%\Desktop
echo Creo la cartella
mkdir %desktop%\Cartella


set /p nomefile=Inserisci il nome del file: 


for /L %%i in (1,1,10) do (
echo > %desktop%\Cartella\%nomefile%%%i.txt
)

echo I file sono stati creati con successo!
pause
