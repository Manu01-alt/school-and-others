
;Tramite procedura implementa un programma che stampa N numeri casuali
    
                           
 .model small
 
 .stack 256   
 
 
 .data 
    strReq db 0Ah,0Dh,"Inserire il numero di casuali da generare: $"
    randNum dw ?
    N dw 0 
    buffer dw 6, 0    ; Buffer per l'input, 6 byte di spazio (massimo 5 cifre e terminatore null)
    
    
    
 .code
   mov ax, data
   mov ds,ax
   mov ss,ax
   
   ;Prompt Input
   lea dx, strReq 
   mov ah,09h
   int 21h   
   ;getInt
   call getInt
   mov N,ax
   
   ;ciclo N volte
    
    
    ;genero num casuale 
    call rand
    pop randNum
    
    
    ; stampo
    
    push randNum
    call printNum
                            
                           
                           
; ==========================================================
; Funzione che legge un intero da tastiera e lo ritorna in AX

                 
getInt     PROC

   read_number:
    push dx           ; Salvare DX sullo stack
    push bx           ; Salvare BX sullo stack
    push cx           ; Salvare CX sullo stack
    
    mov ah, 0Ah       ; Funzione DOS per input string
    lea dx, [buffer]  ; Caricare l'indirizzo del buffer
    int 0x21          ; Chiamare interrupt 21h

    ; Calcolo del valore numerico dalla stringa
    xor ax, ax        ; Pulire AX (dove metteremo il risultato)
    lea si, [buffer+2] ; Puntatore alla stringa (salta lunghezza e terminatore)
    mov cx, [buffer+1]  ; Lunghezza stringa (prima posizione del buffer)
    xor bx, bx        ; BX sarà usato per accumulare il valore
    xor dx, dx        ; Pulire DX

convert_loop:
    mov dl, [si]      ; Prendere il prossimo carattere
    sub dl, '0'       ; Convertire il carattere in valore numerico
    cmp dl, 9
    ja invalid_input  ; Se il carattere non è valido, errore
    mul bx            ; Moltiplicare AX per 10
    add ax, dx        ; Aggiungere il nuovo valore numerico
    inc si            ; Avanzare al prossimo carattere
    loop convert_loop ; Ripetere fino alla fine della stringa

    jmp end_read_number

invalid_input:
    xor ax, ax        ; In caso di errore, restituire 0

end_read_number:
    pop cx            ; Ripristinare CX
    pop bx            ; Ripristinare BX
    pop dx            ; Ripristinare DX
    ret               ; Tornare al chiamante                           
                             
          
 
    
 

RET                   ; return to caller.
getInt     ENDP
; ==========================================================                           

                           
; ==========================================================
; Funzione che genera un numero casuale a 16 bit e 
; lo ritorna mediante stack

rand     PROC
        
 
    
 

RET                   ; return to caller.
rand     ENDP
; ==========================================================                           
                           
                           
; ==========================================================
; Funzione che stampa il numero a 16 bit passato sullo stack

printNum PROC
    XOR DX, DX ; Resetta DX
    XOR CX, CX ; Resetta CX - contatore cifre
    MOV BX, 10 ; Divisore per ottenere le cifre

DIVIDE_LOOP:
    DIV BX ; Divide AX per 10
    PUSH DX ; Salva il resto sullo stack
    XOR DX,DX ; Resetta DX per la prossima divisione
    INC CX
    OR AX, AX ; Controlla se il quoziente e' 0
    JZ PRINT_DIGITS ; Se si', passa alla stampa
    JMP DIVIDE_LOOP ; Altrimenti continua a dividere

PRINT_DIGITS:
    POP DX ; Recupera la cifra dallo stack
    ADD DL, '0' ; Converte la cifra in carattere ASCII
    MOV AH, 02H ; Funzione DOS: stampa carattere
    INT 21H
    LOOP PRINT_DIGITS ; Se si', continua a stampare
    MOV DX, 0DH
    INT 21H  
    MOV DX, 0AH
    INT 21H

    RET
PrintNum ENDP

   
   