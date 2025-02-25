data segment
; add your data here!
num DB 35 ; Numero a due cifre da stampare
ends
stack segment
dw 128 dup(0)
ends
code segment
start: ; Imposta il data segment:
MOV AX, data
MOV DS, AX
; Carica il numero da stampare
XOR AH,AH ; Resetta la parte alta di AX
MOV AL, num ; Carica il valore della variabile num in AL
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
MOV AX, 4c00h ; exit to operating system.
INT 21H
ends
end start ; set entry point and stop the assembler.


    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
