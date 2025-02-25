; multi-segment executable file template.

data segment
    ; add your data here!
    richiesta DB "inserisci un numero: $" ; Stringa di input
    input db 3, 0
    conversione db "il numero e' stato convertito: $" 
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax
                 
lea dx, richiesta
mov ah, 9
int 21h

lea dx, input
mov ah, 10
int 21h



MOV SI, OFFSET input ; Carica l'indirizzo della stringa in SI
MOV AL, [SI] ; Carica il primo carattere (decine) in AL
SUB AL, '0' ; Converti il carattere da ASCII a intero
MOV AH, 0 ; Azzera AH per lavorare con un numero 16-bit
MOV BL, 10 ; Moltiplicatore per il posto delle decine
MUL BL ; AX = decina * 10
INC SI ; Passa al carattere successivo (unita')
MOV DL, [SI] ; Carica il secondo carattere in DL
SUB DL, '0' ; Converti da ASCII a intero
ADD AL, DL ; Somma le unità al totale
; AX ora contiene il numero convertito

    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
