;Richiedere l'immissione di una stringa con caratteri qualsiasi
;a capo, stampare la stringa in caratteri maiuscoli.

;GIZZI MANUEL 3CINF 16/12/24

org 100h
buffer db 100, ?, 100 dup(' ') ; dichiaro il buffer per l'input (100 caratteri)


jmp start

start:
    ; Scrivo il messaggio "Inserisci una stringa:"
    mov dx, offset richiesta   
    mov ah, 9                
    int 21h                  

    ; Lettura dell'input
    mov dx, offset buffer
    mov ah, 0ah
    int 21h

    ; Nuova riga e ritorno a capo
    mov ah, 2
    mov dl, 10
    int 21h
    mov ah, 2
    mov dl, 13
    int 21h

    ; Conversione a maiuscolo
    xor cx, cx               ; Azzero il contatore
    mov cl, buffer[1]        ; inserisco il numero di caratteri
    lea si, buffer + 2       ; con SI punto al primo carattere dell'input 

maiuscolo:
    mov al, [si]             ; Carico il carattere
    sub al, 20h              ; Sottraggo 20 per ottenere il maiuscolo
    mov [si], al             
    inc si                   ; Passo al carattere successivo
    loop maiuscolo           

    ; Aggiungere '$' alla fine della stringa
    xor bx, bx
    mov bl, buffer[1]       
    mov buffer[bx+2], '$'    

    ; Stampare la stringa
    mov dx, offset buffer + 2 
    mov ah, 9                 
    int 21h

ret


richiesta db "Inserisci una stringa:$" ; Messaggio da stampare



