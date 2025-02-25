;GIZZI MANUEL 21/01/25

;Partendo dal sorgente allegato, seguire le indicazione nei commenti e:

;completare il chiamante
;implementare la procedura getInt per l'input di un numero intero a piu' cifre
;implementare la procedura rand per generare un numero casuale. Nota: per farlo potrete cercare tra le procedure di interrupt, oppure cercare online, studiare il sorgente della rand() di stdlib.h e implementare una vostra versione.
;implementare la procedura printNum per l'output di un numero intero a piu' cifre

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
   
   lea dx, buffer ;inserisco  il numero come stringa
   mov ah, 0Ah
   int 21h   
   ;getInt
   call getInt
   
   mov cx, N  ;imposto N come contatore
   
   ciclo:
    
    call rand
    pop randNum ;prendo dallo stack il numero casuale
   
   loop ciclo 
    
    ; stampo
    
    push randNum
    call printNum
                            
 
               
; ==========================================================
; Funzione che legge un intero da tastiera e lo ritorna in AX

                 
getInt     PROC
; Setup ciclo
   lea si , buffer+2 ;carico in si l'offset del buffer partendo dalla prima cifra
   xor ah , ah
   mov bx , 10  ;imposto il moltiplicatore
   
   convert_loop:
      xor ah , ah
      mov al, [si]          ; carico il carattere in al
      cmp al, 13            ; controllo se e' 13 (Carriage Return)
      je done               ; se si' esco dal ciclo
      
      sub al, '0'           ; converto da ascii a numero
      mov cx, ax            ; salvo il numero corrente in cx
      mov ax, N             ; carico il risultato semi definitivo in ax
      mul bx                ; ax = ax * 10 (sposta a sinistra le cifre)
      add ax, cx            ; sommo il nuovo numero
      mov N, ax             ; salvo il nuovo risultato

      inc si                ; passo al prossimo carattere
      jmp convert_loop      ; continuo il ciclo
      
done:
RET                   ; return to caller.
getInt     ENDP
; ==========================================================                           

                           
; ==========================================================
; Funzione che genera un numero casuale a 16 bit e 
; lo ritorna mediante stack

rand     PROC
    push cx ;salvo il contatore N nello stack      
    
    ;vado a capo
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13 
    int 21h

    
    mov ah,2ch ;interrupt per prendere il timer del pc
    int 21h 
    
    mov dh, 0 ;azzero la parte alta di dx
    pop cx    ;reimposto il contatore
    push dx   ;salvo nello stack dl (secondi)
    
    
                       
 

RET                   ; return to caller.
rand     ENDP
; ==========================================================                           
                           
                           
; ==========================================================
; Funzione che stampa il numero a 16 bit passato sullo stack

printNum PROC
    pop ax ;dallo stack inserisco in ax il numero    
    xor dx,dx ; resetto dx
    xor cx,cx ; resetto cx - contatore cifre
    mov bx, 10 ; divisore per ottenere le cifre

divide_loop:
    div bx ; divido AX per 10
    push dx ; salvo il resto sullo stack
    xor dx,dx ; resetto DX per la prossima divisione
    inc cx
    or ax, ax ; controllo se il quoziente e' 0
    jz print_digits ; se si', passo alla stampa
    jmp divide_loop ; altrimenti continua a dividere

print_digits
    mov ah, 2 
    
    mov dx, 13
    int 21h  
    mov dx, 10
    int 21h

    pop dx ; recupero la cifra dallo stack
    add dl, '0' ; converto la cifra in carattere ASCII
    int 21h
    loop PRINT_DIGITS 
  
    RET
PrintNum ENDP
 