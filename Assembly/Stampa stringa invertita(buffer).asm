;GIZZI MANUEL 3CINF 13/01/2025
;data una stringa inserita da tastiera, la stampa invertita. 
;E' un esercizio sull'uso dello stack, ma suggerisco di implementare anche una versione B 
;che faccia ricorso ad un buffer (gia' svolta in classe).

data segment
    richiesta db 'Inserisci una stringa: $'
    fine db 0Dh, 0Ah, 'Stringa invertita: $'
    buffer db 100,?,100 dup(0)
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

    ; Stampo la richiesta
    mov ah, 09h
    lea dx, richiesta
    int 21h
    
     ; Legge la stringa da tastiera nel buffer
    lea dx, buffer
    mov ah, 0Ah         
    int 21h 
    
    lea si,[buffer+2]  ;carico l'offset del buffer in SI (primo carattere)
    mov cl, [buffer+1] ; carico in cl la lunghezza del buffer
             
push_loop:

    mov ax, [si]  ;sposto in ax il carattere presente in SI
    push ax       ;salvo nello stack il carattere
    inc si        ;passo al prossimo carattere
    dec cl        
    cmp cl, 0     ;controllo se i caratteri presenti nel buffer sono finiti
    jne push_loop
                   
  ; Stampa il messaggio di fine
    mov ah, 09h
    lea dx, fine
    int 21h
 
    mov cl, [buffer+1]
    
print_loop:
    pop ax              ; estraggo il carattere dallo stack
    mov dl, al          
    mov ah, 02h        
    int 21h
    dec cl             ;utilizzo un contatore pari al numero di caratteri
    cmp cl, 0
    jne print_loop
              
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
