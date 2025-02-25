;GIZZI MANUEL 3CINF 18/02/2025
;Problema con il programma: il msg1 viene stampato nel ciclo e sovrascrive la scritta ciao


;Programma che richiede una parola in input
; e un intero N tra 0 e 100
; Il programma cancella lo schermo e scrive N volte la
; parola in posizioni casuali



;*************************************************************
;*        DATA SECTION
;*************************************************************

data segment
    ; add your data here!
    str db 10, ?, 10 dup(?)   
    msg1 db "$"
    msg2 db 10,13, "Inserire il numero intero: $" 
    N db 10  
    seed dw ?  
    righe dw 25
    colonne dw 80 
    x dw 0
    y dw 0
    
ends                                    

;*************************************************************
;*        STACK SECTION
;*************************************************************
stack segment
    dw  128  dup(0)
ends

;*************************************************************
;*        DATA SECTION
;*************************************************************
code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax

;Input della stringa 
    lea dx, msg1
    mov ah, 09h
    int 21h

    lea dx, str
    mov ah, 0Ah
    int 21h 

                 
;input di N 
; Mostra msg2 e richiede input
lea dx, msg2
mov ah, 09h
int 21h

mov cl, 3     ; Lunghezza massima dell'input
mov bh, 10    ; utilizzo 10 come moltiplicatore     

;converto da intero a stringa
conversione:
    mov ah, 01h  ;prendo un carattere da tastiera  
    int 21h
    dec cl       ;decremento cl
    
    cmp al, 0Dh              ;controllo se e' un invio, nel caso salvo il risultato a 1 o 2 cifre
    je risultato_meno_3
    
    sub al, '0'  
                             
    add al,bl                ;aggiungo ad al la prima cifra (o niente)
    mov ch,al                ;salvo il risultato in ch
    
    cmp al,100               ;controllo se e' piu' grande o uguale a 100, nel caso vado al risultato
    jg risultato
    cmp al,100
    je risultato
    
moltiplico:                  
    mul bh                   ;moltiplico per 10
                             ;((cifra1*10+cifra2)*10+cifra3)

;nel caso fossero meno di 3 cifre prendo il risultato prima che venga moltiplicato per 10
risultato_meno_3:
    mov bl, ch                  
    
    cmp al, 0Dh
    je fin

risultato:   
    mov bl,al
    
    cmp cl, 0
    jne conversione

  

fin:    
mov N, bl    ; Memorizzo il risultato finale in N
    
      
    call cls
    call srand  
       
; DL = casuale.tra(0,80)    
    xor ax,ax 
     
    push ax   
    push colonne    
    call casuale_tra 
    pop x

; DH = casuale.tra(0,25)   
    xor  ax,ax
    push ax   
    push righe    
    call casuale_tra 
    pop y
    
    mov DX, x
    mov AX, y
    mov DH, AL    
            
            
    lea si, str
    inc si         
    mov CL, [si] 
     
; ciclare N volte la stampa 
ciclo:
    
    ;Stampo parola  a x,y usando mov ah, 13h int 10h
    mov ah, 2  ;imposto il cursore su una determinata riga e colonna
    mov dh, byte ptr [x]  ; imposto la riga  specificando che sia un byte
    mov dl, byte ptr [y]  ; imposto la colonna specificando che sia un byte
    mov bh, 0
    int 10h

    ;stampo la stringa
    mov ah, 09h
    lea dx,str+2
    int 21h
    

    ; DL = casuale.tra(0,25) --> genero nuovamente la colonna
    xor ax,ax
    push ax
    push colonne
    call casuale_tra
    pop x

    ; DH = casuale.tra(0,80) --> genero nuovamente la riga
    xor ax,ax
    push ax
    push righe
    call casuale_tra
    pop y
    
    ;reimposto le variabili
    mov DX, x
    mov AX, y
    mov DH, AL

    dec N
    cmp N, 0
    jne ciclo

    mov ax, 4c00h ;finisce il programma
    int 21h    
ends


;*************************************************************
;*       PROCEDURES SECTION
;*************************************************************


;*************************************************************
;* Procedura:   srand 
;* description: initialize 'seed' variable (must be declare as dw)
;* input:       none
;* return:      none
;*************************************************************
srand PROC
    MOV AH, 00h   ; Funzione per leggere il timer 
    INT 1Ah       
    MOV seed, DX  ; Salva il valore del timer in seed
    RET
srand ENDP  

;*************************************************************
;* Procedura:   rand 
;* description: generate a new pseudocasual integer between 0 e 2^16-1 
;* input:       none
;* return:      pseudocasual integer between  0 e 2^16-1 passed by stack
;*************************************************************

rand PROC
    ; Incrementa il seed 
    POP BP
    
    MOV AX, seed
    ADD AX, 1
    MOV seed, AX
    
    ;LCG psudocasual
    MOV BX, 1035h
    MUL BX   ; DX AX
    ADD AX, 12345       ; N % 65536
    MOV seed, AX
    
    ; Ritorna il numero casuale nello stack
    PUSH AX
    PUSH BP
    RET
rand ENDP


;*************************************************************
;* Procedura:   casuale_tra 
;* description: generate a pseudocasual integer between min e max passed by stack
;* input:       min ean maxnone
;* return:      pseudocasual integer througth stack
;*************************************************************

casuale_tra PROC
    ; Riceve min e max dallo stack 
    pop BP 
    
;LCG algorithm    
    MOV AX, seed
    ADD AX, 1
    MOV seed, AX
    MOV BX, 1035h
    MUL BX
    ADD AX, 12345
    MOV seed, AX
    
    
    
    POP BX       ; max
    POP CX       ; min
    
    ; Genera un numero casuale
    ; CALL rand   ; NON POSSO fare CALL ricorsive!!!!!!!!!!!!!!!!
    ; POP AX       ; Ottiene il numero casuale
    

    ; Calcola il numero casuale tra min e max
    SUB BX, CX   ; max - min 
    XOR DX, DX
    DIV BX       ; (numero casuale % (max - min))
    ADD DX, CX   ; + min
    
    ; Ritorna il numero casuale nello stack
    PUSH DX 
    PUSH BP
    RET
casuale_tra ENDP

cls PROC
    MOV AH, 06h  ; Funzione di scroll
    MOV AL, 0    ; Scrolla l'intero schermo  (00h = clear entire window)
    MOV BH, 07h  ; Attributo (sfondo nero, testo bianco)
    MOV CX, 0    ; Coordinata superiore sinistra (riga 0, colonna 0)
    MOV DX, 184Fh ; Coordinata inferiore destra (riga 24, colonna 79) per schermi 80x25
    INT 10h      ; Chiamata all'interrupt video      
    RET
cls ENDP    
end start ; set entry point and stop the assembler.