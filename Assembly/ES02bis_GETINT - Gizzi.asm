;GIZZI MANUEL 3CINF
;partendo dall'esempio1, estendere la logica del programma in modo che
;supporti numeri fino a 255 (ancora meglio sarebbe fino a 65535).


data segment
    ; add your data here!
    str DB 4, 0 ; Stringa di input
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

lea dx, str
mov ah, 10
int 21h

MOV SI, OFFSET str ; Carica l'indirizzo della stringa in SI 
MOV AL, [SI] ; Carica il primo carattere (decine) in AL
SUB AL, '0' ; Converti il carattere da ASCII a intero
MOV AH, 0 ; Azzera AH per lavorare con un numero 16-bit
MOV BL, 100 ; Moltiplicatore per il posto delle centinaia
INC SI ;passo al prossimo carattere
MOV CL, [SI] ; Carica il primo carattere (decine) in CL
SUB CL, '0' ; Converti il carattere da ASCII a intero
MOV AH, 0 ; Azzera AH per lavorare con un numero 16-bit
MOV BL, 10 ; Moltiplicatore per il posto delle decine
MUL BL ; AX = decina * 10
INC SI ; Passa al carattere successivo (unità)
MOV DL, [SI] ; Carica il secondo carattere in DL
SUB DL, '0' ; Converti da ASCII a intero
ADD CL, AL
ADD CL, DL ; Somma le unità al totale
; AX ora contiene il numero convertito


    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
