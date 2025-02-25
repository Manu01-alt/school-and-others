;GIZZI MANUEL 3CINF 13/01/2025
;data una stringa inserita da tastiera, la stampa invertita. 
;E' un esercizio sull'uso dello stack, ma suggerisco di implementare anche una versione B 
;che faccia ricorso ad un buffer (gia' svolta in classe).

data segment
     richiesta db 'Inserisci una stringa: $'
    fine db 0Dh, 0Ah, 'Stringa invertita: $'
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
      
      
    ;stampo a schermo la stringa con la richiesta  
    mov ah, 09h
    lea dx, richiesta
    int 21h

    ; Legge i caratteri da tastiera e li mette nello stack
read_loop:
    mov ah, 01h         ; Inserisco il carattere
    int 21h 
    inc bx              ; Utilizzo un contatore per i caratteri
    cmp al, 13          ; Controllo se e' "Invio" 
    je print_inverted   
    push ax             ; Salvo il carattere nello stack
    jmp read_loop

print_inverted:
    ; Stampo la stringa con il messaggio finale
    mov ah, 09h
    lea dx, fine
    int 21h

    ; Stampo i caratteri dallo stack in ordine inverso
    xor cx,cx
    mov cx,bx
print_loop:
    pop ax              ; Estraggo un carattere dallo stack
    mov dl, al          
    mov ah, 02h         ; stampo il carattere
    int 21h
    loop print_loop
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
