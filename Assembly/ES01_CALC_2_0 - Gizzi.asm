;GIZZI MANUEL 3CINF
;Implementa una calcolatrice che richieda l’operazione da eseguire e a
;seguire i due operandi (mono cifra). Calcola il risultato e lo stampa. Il programma deve
;supportare le 4 operazioni: +, -, x, :

acapo macro
    mov ah,2 
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    
endm

data segment
    ; add your data here!
    str_richiesta db "inserire operazione, operando1 e operando due: $"
    str_somma db "la somma e': $"
    str_differenza db "la differenza e': $"
    str_prodotto db "il prodotto e': $"
    str_quoziente db "il quoziente e': $"
    str_resto db "e il resto e': $"
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
    
    ;leggo in input operazione e i due operatori
    lea dx, str_richiesta
    mov ah, 9
    int 21h
    
    mov ah, 1
    int 21h
    mov ch,al
    
    int 21h
    mov bh,al
    sub bh, '0'
    
    int 21h
    mov bl,al  
    sub bl, '0'
    
    cmp ch, '+'
    je addizione
    cmp ch, '-'
    je sottrazione
    cmp ch, 'x'
    je moltiplicazione
    cmp ch, '/'
    je divisione 
    
    mov ax, 4c00h ; exit to operating system.
    int 21h
    
addizione:

acapo
;mostro a schermo la stringa
lea dx, str_somma
mov ah, 9
int 21h

;faccio l'addizione
add bh, bl
cmp bh, 10
jge due_cifre ;controllo se il risultato e' a due cifre
mov ah, 2
add bh, '0'
mov dl, bh
int 21h

mov ax, 4c00h ; exit to operating system.
    int 21h 

due_cifre:
XOR AH,AH ; Resetta la parte alta di AX
MOV AL, bh ; Carica il valore di bh in AL
MOV BL, 10 ; Divisore a 8 bit per separare decine e unita'
DIV BL ; AL -> quoziente (decine), AH -> resto (unita')
MOV BL, AH ; Salva in BL il resto
; Stampa la decina
ADD AL, '0' ; Converte la decina in carattere ASCII
MOV DL, AL ; Carica il carattere nel registro DL per la stampa
MOV AH, 02H ; Funzione DOS per stampare un carattere
INT 21H ; Interruzione per eseguire la stampa
; Stampa l'unita'
MOV AL, BL ; Carica il resto (unita') in AL
ADD AL, '0' ; Converte l'unità in carattere ASCII
MOV DL, AL ; Carica il carattere nel registro DL per la stampa
MOV AH, 02H ; Funzione DOS per stampare un carattere
INT 21H ; Interruzione per eseguire la stampa

mov ax, 4c00h ; exit to operating system.
    int 21h 

sottrazione:

acapo

lea dx, str_differenza
mov ah, 9
int 21h

sub bh, bl
mov ah, 2 
add bh, '0'
mov dl, bh
int 21h  

mov ax, 4c00h ; exit to operating system.
    int 21h 

moltiplicazione: 

acapo

lea dx, str_prodotto
mov ah, 9
int 21h

mov al,bh
mul bl
cmp al, 10
jge due_cifre
add al, '0'
mov dl, al
mov ah, 2
int 21h

mov ax, 4c00h ; exit to operating system.
    int 21h

divisione:

acapo

lea dx, str_quoziente
mov ah, 9
int 21h

mov al,bh
div bl
add al, '0'
mov dl, al
mov ah, 2
int 21h

lea dx, str_resto
mov ah, 9 
int 21h
mov ah,2
mov dl, ah
int 21h

mov ax, 4c00h ; exit to operating system.
    int 21h    
    
ends

end start ; set entry point and stop the assembler.

