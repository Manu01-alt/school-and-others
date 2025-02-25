;GIZZI MANUEL 3CINF 6/12/24
 
;Leggi una sequenza di caratteri da tastiera (terminata da INVIO) 
;e forzala tutta in minuscolo senza usare ADDIZIONI
org 100h

ciclo:

    mov ah, 7 ;leggo il carattere in input senza mostrarlo a schermo
    int 21h
    
    cmp al,13h ;controllo se l'input e' invio (Carriage Return), nel caso il programma finisce
    je fine
    
    cmp al,'a'
    jl maiuscole   ;controllo se il carattere in input rientra tra l'elenco delle lettere minuscole
    cmp al, 'z'
    jl minuscole
    
maiuscole:
    mov bh, al
    or bh,00100000b  ;la differenza tra le lettere maiuscole e minuscole in decimale e' di "32"
    mov al,bh        ;quindi uso l'or per aggiungere al valore binario cio' che serve per convertirlo in minuscolo
    mov ah,2
    mov dl,al
    int 21h 

    loop ciclo

minuscole:
mov ah,2
mov dl,al
int 21h
loop ciclo
    
fine:
ret




