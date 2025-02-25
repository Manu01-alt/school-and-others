; multi-segment executable file template.

data segment
    
    
    array dw 4 dup(?) 
    input db "Inserire operando, operazione e secondo operando: $"
    str db 10,?,10 dup(?) 
    
    op1 db 4,?,4 dup(?)
    op2 db 4,?,4 dup(?)
    segno db 2,?,2 dup(?)
    appoggio db 4 dup(?)
    
    error_op db "ERRORE! Operanzione non riconosciuta. $"
    error_zero db "ERRORE! I due operandi devono essere diversi da 0 per la divisione. $" 
    
    somm db "La somma e' : $"
    dif db "La differenza e' $"
    prod db "Il prodotto e' $" 
    quoz db "Il quoziente e' $"
    FATTORIALE db "fattoriale$"
    AND_AND db "and$"
    OR_OR db "or$"
    potenza db "potenza$"
    result dw 4 dup(?)
    
    resto db " Con un resto di $"
    cont_rest db 4,?,4 dup(?) 
    
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
    mov ah ,0Ah
    int 21h
    
    lea si,str
    inc si
    lea di,array
    inc di
     

ciclo1:
    mov [di],dx    
    inc si
    cmp [si],"0"
    jb fuori1
    cmp [si],"9"
    ja fuori1 
    mov dl,[si]
    inc di
    
    jmp ciclo1
fuori1: 
    cmp [si]," "
    je cilo2
    mov bp,si
    call getInt  
    mov op1,al
    mov si,bp
    call getoperand
    lea di,array
    inc di
    
ciclo2:    
    mov [di],dx    
    inc si
    cmp [si],"0"
    jb fuori2
    cmp [si],"9"
    ja fuori2 
    mov dl,[si]
    inc di    
    
    jmp ciclo2
fuori2:
    cmp [si]," "
    je cilo2
    call getInt
    mov op2,al 
    
    
    mov al,segno
    
    cmp al,"+"
    je call addizione 
    cmp al,"-"
    je call sottrazione
    cmp al,"*"
    je call moltiplicazione
    cmp al,"/"
    je call divisione  
    cmp al,"!"
    je call fattoriale1
    cmp al,"&"
    je call and_and1
    cmp al,"|"
    je call or_or1
    cmp al,"^"   
    je call potenza1
    ;cmp al,
    
    mov ax, 4c00h ; exit to operating system.
    int 21h            
ends 

getint proc
      mov result, 00h
      mov bx , 10
      lea ax, [array+2]
      mov si , ax
      convert_loop:
         xor ah , ah
         mov al , [si]                  ; Carica il carattere in al
         cmp al , 00                   ; Controllo con terminatore a capo
         je done                        ; Uscita dal ciclo
         
         sub al , '0'                   ; Converte da ascii a numero
         mov cx , ax                    ; Salva il numero corrente in cx
         mov ax , result                ; Carico il risultato definitivo in ax
         mul bx                         ; ax = ax * 10 (sposta a sinistra le cifre)
         add ax , cx                    ; Somma il nuovo numero come unità
         mov result , ax                ; Salva il nuovo risultato
         
         inc si                         ; Passo al prossimo carattere
         jmp convert_loop               ; Continuo il ciclo

   done:
      mov ax , result  
      
      ret

getint endp

getoperand proc 

prima:    
    mov ah,[si]
    cmp ah," "
    je  dopo
    mov segno,ah
    
dopo:
    inc si
    jmp     
     
    ret 
getoperand endp    

addizione:
    
    ;stampa a schermo la stringa SOMMA    
    lea dx,somm
    mov ah,9
    int 21h
    
    cifre:
    ;esegue l'addizione tra i due operandi
    add al,dl
    mov bx,10
    xor cx,cx
    xor dx,dx

sottrazione:
    
    ;stampa a schermo la stringa DIFFERENZA    
    lea dx,dif
    mov ah,9
    int 21h
    
    cifre1:
    ;esegue la sottrazione tra i 2 operandi 
    sub al,dl
    mov bx,10
    xor cx,cx
    xor dx,dx
    ;jmp salva   
    
moltiplicazione:
     
    ;stampa a schermo la stringa PRODOTTO    
    lea dx,prod
    mov ah,9
    int 21h
    
    cifre2:
    
    mul dl
    mov bx,10
    xor cx,cx
    xor dx,dx
    ;jmp salva    


fattoriale1:
    
    ;stampa a schermo la stringa FATTORIALE
    lea dx,FATTORIALE
    mov ah,9
    int 21h
    
    mov al,cl
    dec al
    mul cl
    
    ;jmp salva
    
    
potenza1:
    
    ;stampa a schermo la stringa FATTORIALE
    lea dx,POTENZA
    int 21h 
             

and_and1:
    
    ;stampa a schermo la stringa AND_AND
    lea dx,AND_AND
    mov ah,9
    int 21h

    AND ax,bx

or_or1:
    
    ;stampa a schermo la stringa OR_OR
    lea dx,OR_OR
    mov ah,9
    int 21h   
    
    or ax,bx

divisione:
   
    ;stampa a schermo la stringa QUOZIENTE    
    lea dx,quoz
    mov ah,9
    int 21h
    
    cifre3: 
    ;controlla che i 2 operandi siano diversi da 0
    add al,"0"
    add dl,"0"    
    cmp al,"0"
    ;je error
    cmp dl,"0"
    ;je error
    sub al,"0"
    sub dl,"0"
    
    ;effettuta le divisione
    div dl
    mov bx,10
    xor cx,cx
    xor dx,dx
    mov offset appoggio,ah ;salva il resto nella stringa APPOGGIO
    xor ah,ah

end start ; set entry point and stop the assembler.