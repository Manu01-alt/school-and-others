@echo off
cls

:: Chiedi il nome della cartella da creare
set /p cartella=Inserire nome cartella:

:: Imposta il percorso di destinazione per la cartella
set destinazione=%USERPROFILE%\Desktop\%cartella%

:: Crea la cartella se non esiste
mkdir "%destinazione%"

:: Chiedi i nomi dei file da creare
set /p File1=Inserire nome del primo file (es. file1.txt):
set /p File2=Inserire nome del secondo file (es. file2.txt):
set /p File3=Inserire nome del terzo file (es. file3.txt):

:: Crea i file e aggiungi contenuto
echo Questo è il contenuto del %File1% > "%destinazione%\%File1%"
echo Questo è il contenuto del %File2% > "%destinazione%\%File2%"
echo Questo è il contenuto del %File3% > "%destinazione%\%File3%"

:: Chiedi la cartella finale per la copia
set /p cartella_finale=Inserire cartella di destinazione:

:: Verifica se la cartella di destinazione esiste, altrimenti la crea
if not exist "%cartella_finale%" (
    echo La cartella non esiste, la creo ora...
    mkdir "%cartella_finale%"
)

:: Copia i file nella cartella di destinazione
copy "%destinazione%\%File1%" "%cartella_finale%"
copy "%destinazione%\%File2%" "%cartella_finale%"
copy "%destinazione%\%File3%" "%cartella_finale%"

:: Conferma che i file sono stati copiati
echo I file sono stati copiati correttamente nella cartella "%cartella_finale%"
pause
