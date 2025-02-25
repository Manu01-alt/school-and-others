;Gizzi Manuel 3CINF 
;Implementare un programma con le seguenti procedure con EMU
;1. srand -> iniziallizza la variabile seed con il timer di sistema
;2. rand -> gera un nuovo casuale, lo ritorna (stack)e lo aggiorna nel seed
;3. casuale_tra -> riceve min e max dallo stack e ritorna un casuale compreso (min <= R < max)
;Il programma consente di generare un numero N di numeri casuali tra min e max
    
    data segment
        seed dw 0  
        min dw 1        ;valore minimo
        max dw 4000     ;valore massimo
        memory dw 1000 dup(0) ;array per salvare i numeri
        N dw 20 ;numero di numeri da generare
        
    ends
    
    stack segment
        dw   128  dup(0)
    ends
    
    code segment
    start:
    
        mov ax, data
        mov ds, ax
        mov es, ax
    
        lea si, memory ;carico l'offset dell'array "memory" in SI
        
        call sRand ;chiamo la procedura sRand
        pop seed ;inserisco nella variabile seed il valore dallo stack
        
    genera:    
        push seed  ;sposto il seed nello stack
        call Rand  ;chiamo la procedura Rand
        pop seed   ;inserisco nella variabile il valore dallo stack
        
        
        push max   ;sposto max nello stack
        push min   ;sposto min nello stack
        push seed  ;sposto il seed nello stack
        call casuale_tra ;chiamo la procedura casuale_tra
        
        cmp N, 0
        je fine2
        cmp [si], 0
        je genera
        
fine2:      
        mov ax, 4c00h ; exit to operating system.
        int 21h    
    
   ends                          
     
sRAND proc
    pop bx   ;faccio un pop in bx per salvare l'indirizzo di ritorno
    
    mov ah, 00
    int 1Ah    ;uso l'interrupt per avere il timer di sistema
    
    add dx, 1  ;aggiungo a dx 1
    
    ;sposto nello stack dx (seed) e l'indirizzo di ritorno
    push dx  
    push bx
           
    ret       
sRAND endp
;-----------------    
Rand proc
    
    pop cx ;salvo l'indirizzo di ritorno
    pop ax ;metto in ax il seed
    
    mov bx, 25173 ;imposto bx come moltiplicatore
    mul bx ;seed * 25173  
    
    add ax,dx ;aggiungo la parte alta
    
    add ax, 13849 
    mov bx, 32768 ;imposto bx come divisore
    div bx 
                  
    mov seed, dx ;salvo il resto da DX
    
    ;sposto nello stack dx (seed) e l'indirizzo di ritorno
    push dx
    push cx 
    
    ret
    
Rand endp
;---------------   
casuale_tra proc 
    pop cx   ;salvo l'indirizzo di ritorno
    pop dx   ;imposto in dx seed
    pop ax   ;imposto in ax min
    pop bx   ;imposto in bx max
    
    ;controllo se il valore rientra, in caso salto a fine
    cmp dx, ax 
    jl fine
    cmp dx, bx
    jg fine 
     
    mov [si], dx ;se il valore rientra lo salvo nell'array
    add si, 2 ;incremento 2 volte SI 
     
    dec N     ;decremento il contatore N
    cmp N,0   ;controllo se e' 0, in caso finisce il programma
    je fine2
    
    
    
    fine:
    push bx    ;sposto nello stack il valore max
    push ax    ;sposto nello stack il valore min
    push dx    ;sposto nello stack il seed
    push cx    ;reimposto l'indirizzo di ritorno
    ret
     
casuale_tra endp
    

end start 