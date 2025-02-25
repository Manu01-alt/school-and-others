;GIZZI MANUEL 3CINF 
;Parte svolta: Procedure per prendere i due operandi ed il segno

data segment
        
    array dw 4 dup(?)   
    
    help db "per poter mettere il segno della potenza premere (shift+6)$"
    help2 db "per poter mettere il segno dell'and premere (shift+7)$"
    input db "Inserire operando, operazione e secondo operando: $"
    str db 20,?,20 dup(?) 
    
    op1 dw 4 dup(?)
    op2 dw 4 dup(?)
    segno db 0
    indice db 1 
    indice2 db 0
    result dw 4 dup(?)
    memory db 200 dup(0)
    cont_rest dw 4 dup(?) 
    
     
    error_op db "ERRORE! Operazione non riconosciuta. $"
    error_zero db "ERRORE! impossibile dividere per zero. $"
    error_sott db " ERRORE! impossibile sottrare per un numero a un numero piu' piccolo. $"  
        
    send db "bye.$"
    
    resto db " Con un resto di $"
    
    
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:

    mov ax, data
    mov ds, ax
    mov es, ax
    
    mov ah,9
    lea dx,help
    int 21h
    call acapo
    
    mov ah,9
    lea dx,help2
    int 21h
    call acapo
             
    lea dx, input
    mov ah, 09h
    int 21h

;Inserisco in input l'operazione da fare        
number:
        
    call acapo   ;chiamo la procedura per andare a capo
        
    call indic   ;chiamo la procedura per la gestione dell'indice
    
    ;leggo stringa di input 
    lea dx, str
    mov ah ,0Ah
    int 21h
    
    ;carico l'offset di str in SI
    lea si,str
    inc si ;incremento per saltare il valore che indica la lunghezza della stringa
    ;carico l'offset dell'array in DI
    lea di,array
    inc di
    
     
;Primo Ciclo
ciclo1:
    
    mov dl,[si]
    mov [di],dx ;Sposto il valore da DX alla locazione puntata da DI (carattere in str)    
    inc si      ;incremento SI per passare al primo valore della stringa
    
    ;Controllo se il valore e' X, nel caso lo fosse salto a fine
    cmp [si],"x"
    je fine
    cmp [si],"X"
    je fine
    ;Controllo se il valore e' compreso tra 0 e 9, nel caso lo fosse salto a fuori1
    cmp [si],"0"
    jb fuori1
    cmp [si],"9"
    ja fuori1 
    inc di
    
    jmp ciclo1
    
fuori1: 
    cmp [si]," " ;Controllo il carattere con uno spazio, in caso salto a ciclo2
    je ciclo2
    
    mov bp,si  ;Salvo l'indirizzo in BP
   
    call getInt;Chiamo la procedura per trasformare il numero da stringa ad intero  
    
    mov op1,ax ;Memorizzo il valore presente in AX in op1
    
    mov si,bp  ;Ripritino il valore di SI 
   
    call getoperand;Chiamo la procedura per ottenere l'operatore
    
    lea di,array ;Carico l'offset dell'array in DI
    inc di ;incremento DI
    
ciclo2:    
    mov [di],dx  ;Sposto il valore da DX nella locazione puntata da DI  
    inc si       ;Passo al carattere successivo
    ;Controllo se e' compreso tra 0 e 9, in caso salto a fuori2
    cmp [si],"0" 
    jb fuori2
    cmp [si],"9"
    ja fuori2 
    mov dl,[si] ;Sposto il valore in DL
    inc di ;incremento DI   
    
    jmp ciclo2 ;ritorno all'inizio del ciclo2

fuori2:
    cmp [si]," ";Controllo se il valore puntato da SI e' uno spazio, nel caso continuo a leggere la stringa
    je ciclo2
    call getInt ;Chiamo la procedura GetInt per ottenere il secondo operando
    mov op2,ax 
    
    
    mov al,segno ;Sposto il valore della variabile segno in al per confrontarlo
    
;Eseguo i vari controlli per determinare l'operazione da fare  
    cmp al,"+" 
    jne pross1
    call addizione ;Chiamo la procedura per l'addizione
    jmp pross8 
    
pross1:
        
    cmp al,"-"
    jne pross2
    call sottrazione ;Chiamo la procedura per la sottrazione
    jmp pross8
pross2:
    
    cmp al,"*"
    jne pross3
    call moltiplicazione ;Chiamo la procedura per la moltiplicazione
    jmp pross8

pross3:    

    cmp al,"/"    
    jne pross4
    call divisione ;Chiamo la procedura per la divisione
    jmp pross8

pross4:      

    cmp al,"!"
    jne pross5
    call fattoriale1 ;Chiamo la procedura per il fattoriale 
    jmp pross8

pross5:    

    cmp al,"&"
    jne pross6
    call and_and1 ;Chiamo la procedura per l'and
    jmp pross8

pross6:    

    cmp al,"|"
    jne pross7
    call or_or1 ;Chiamo la procedura per l'or
    jmp pross8

pross7:    

    cmp al,"^"   
    jne no_uguale
    call potenza1 ;Chiamo la procedura per la potenza
    jmp pross8

;Mostro a schermo la stringa di errore in caso non venga riconosciuto il segno
no_uguale:
    call acapo
    lea dx,error_op
    mov ah, 09h
    int 21h
    call acapo
    jmp number

pross8:
    
    call acapo
    
    mov ah,2
    mov dl,"="
    int 21h 
    
    mov dl," "
    int 21h
    
    mov bl,segno
    cmp bl,"/"
    je stampdiv ;salto a stampdiv per stampare il risultato della divisione
   
    mov ax,result ;Imposto in ax il valore da stampare    
    mov bx,10 ;imposto in bx 10
    
    call stampa ;Chiamo la procedura di stampa
    
    call acapo
    
    ;indico la posizione in cui andare a salvare il risultato in memoria
    lea di,memory 
    xor ax,ax
    mov al,indice ;carico il valore dell'indice in AL
    
    add di,ax ;Aggiungo a DI il valore dell'indice 
    
    dec di ;decremento due volte DI per allinearlo nel posto giusto
    dec di
    
    mov bx,result ;sposto in bx il valore di result
    
    mov [di],bx ;salvo il valore di bx all'indirizzo puntato da DI
    
    jmp number;ritorno all'inizio del programma.

stampdiv:
    mov ax,result
    mov bx,10
    call stampa 
    mov ah,9
    lea dx, resto
    int 21h
    mov ax,cont_rest
    call stampa 
    jmp number
      
;Termino il programma    
fine:
    call acapo 
    mov ah,9
    lea dx,send 
    int 21h    
    mov ax, 4C00h
    int 21h            


;procedura per la gestione dell'indice 
indic proc  
   
   mov dl,indice ;copio l'indice nel registro dl 
   cmp dl,9
   ja doppio     ;controllo se l'indice va' oltre il 9


;ad ogni ripetizione vado ad aumentare il valore dell'indice
rip: 
   inc dl        ;incremento il valore dell'indice 
   mov indice,dl ;salvo il nuovo valore nella variabile 
   dec dl        ;decremento per tornare al valore originale
   add dl,"0"    ;converto da decimale ad ascii
   mov bl,dl     ;salvo in bl per la stampa
   jmp stamp2
          
doppio:
    ;incrementa la decine per l'indice
    mov dl,0
    mov indice,dl   ;azzero l'unita' dopo essere arrivato a 9
    mov bl,indice2  ;carico la decina in bl  
    inc bl          ;incremento la decina dell'indice presente in BL
    mov indice2,bl  ;imposto il nuovo valore nella variabile   
    jmp rip

stamp2:   
   ;stampo il numero
   mov ah,2
   mov dl,indice2  ;stampo prima la decina dell'indice
   add dl,"0"  
   int 21h
   mov dl,bl       ;stampo la unita' salvata in BL
   int 21h 
   mov dl,"]"
   int 21h
   mov dl," "
   int 21h 
       
    ret
indic endp

;-----------------------------------
;procedura per andare a capo
acapo proc 
    
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h
    
    
    ret
acapo endp    
;-----------------------------------
;Procedura per convertire un numero da stringa ad intero
getint proc
    
      mov result, 00h   ;inizializzo result
      mov bx , 10       ;imposto BX a 10 per la moltiplicazione
      lea ax, [array+2] ;carico l'offset dell'array in AX dal primo carattere
      mov si , ax       ;punto al primo carattere della stringa
      
      ;ciclo per la conversione
      convert_loop:
         xor ah , ah
         mov al , [si] ;carico il carattere corrente in al                 
         cmp al , 00   ;confronto il valore in AL con 00 per controllare se siamo alla fine della stringa                
         je done                       
         
         sub al , '0'  ;converto il carattere in valore numerico                
         mov cx , ax   ;imposto in CX il valore di AX               
         mov ax , result ;carico in ax il valore del risultato quasi pronto              
         mul bx        ;moltiplico per 10               
         add ax , cx   ;aggiungo il valore in CX ad AX               
         mov result , ax ;imposto come valore della variabile result il valore presente in AX              
         
         inc si ;punto al carattere successivo e ritorno all'inizio del ciclo                         
         jmp convert_loop               

   done:
      mov ax , result ;riporto in AX il risultato finale 
      
      ret

getint endp
;-----------------------------------
;Procedura per ottenere l'operatore
getoperand proc 

prima:    
    mov ah,[si] ;sposto in ah il carattere puntato da SI
    cmp ah," "  ;controllo se e' uno spazio, in caso salto a dopo 
    je  dopo
    mov segno,ah ;imposto come valore della variabile segno il valore presente in AH
    jmp fin

;Incremento SI per ignorare lo spazio    
dopo:
    inc si
    jmp prima    
;fine della procedura
fin:     
    ret 
getoperand endp 
;-----------------------------------
;Procedura per la stampa
stampa proc 
    
    pop di ;salvo in DI l'indirizzo di ritorno
    xor cx,cx
salva:
    ;inscrive nello stack il risulato dell'operazione
        
    xor dx,dx ;azzero dx per la divisione 
    div bx  ;divido per 10 il risultato
    push dx ;sposto nello stack il resto   
    inc cx  ;incremento cx usandolo come contatore
    cmp ax,0 ;controllo se in AX ci sono altre cifre, se si', continuo a dividere
    je stamp
    jmp salva

stamp:
    ;stampa a schermo dallo stack il risultato dell'operazione
    pop dx  ;prendo il resto dallo stack e lo stampo
    add dl,"0"   
    mov ah,2
    int 21h    
    loop stamp ;continuo fino alla fine del contatore

    push di ;metto di nuovo DI nello stack, per ritornare alla call
    ret
stampa endp 
;---------------------------  
;Procedura per l'addizione
addizione proc
        
    mov ax,op1
    mov dx,op2
    
    
    ;esegue l'addizione tra i due operandi
    add ax,dx
    mov bx,10
    mov result,ax 
              
    ret          
addizione endp    
;---------------------------
;Procedura per la sottrazione
sottrazione proc 

    
    mov ax,op1
    mov dx,op2
    
    cmp ax,dx
    jb errorsot
    jmp sottra
;In caso il primo operando fosse minore del secondo, mostra a schermo la stringa di errore    
errorsot:   
    mov ah,9
    lea dx,error_sott
    int 21h 
    mov result,0000h
    jmp fin4
            

sottra:    
    ;esegue la sottrazione tra i 2 operandi 
    sub ax,dx
    mov bx,10

    mov result,ax
    
    
fin4:    
    ret
    
sottrazione endp       
;---------------------------
;Procedura per la moltiplicazione    
moltiplicazione proc 

    ;eseguo la moltiplicazione tra i due operandi
    mov ax,op1
    mov dx,op2
    
    mul dx
    mov bx,10
    
    mov result,ax
    
    ret

moltiplicazione endp
;---------------------------
;Procedura per il fattoriale
fattoriale1 proc
    
    mov cx,op1 ;copio in cx il primo operando
    
    mov bx,cx ;copio in bx il valore presente in cx, usandolo come contatore 
    dec bx ;decremento il valore
fatt:    
    
    mov ax,bx ;sposto in ax il valore di bx
    
    mul cx ;moltiplico il primo operando per il suo precedente
           
    mov cx,ax ;reimposto in cx il valore di ax
    dec bx    ;decremento bx
    cmp bx,0  ;quando bx va a 0, l'operazione finisce
    
    mov result,ax
    
    ret
fattoriale1 endp
;---------------------------
;Procedura per la potenza
potenza1 proc
    
    
    mov ax,op1 ;imposto in ax il primo operando
    
    mov bx,ax  ;copio il valore in bx
    
    mov cx,op2 ;imposto come contatore il secondo operando
    dec cx;decremento cx
pot:    
    mul bx ;moltiplico per se' stesso il primo operando
    dec cx ;decremento cx
    
    cmp cx,0 ;quando il contatore va a 0, l'operazione finisce
    jne pot
        
    
    mov result,ax
             
    ret
potenza1 endp
;---------------------------
;Procedura per AND (Operatore logico che restituisce il valore dei bit in comune)
and_and1 proc
        
    mov ax,op1
    mov bx,op2

    AND ax,bx ;uso l'istruzione AND che confronta il valore in bit dei due operandi 
    
    mov result,ax

    ret
and_and1 endp
;---------------------------
;Procedura per OR (Operatore logico che restituisce il valore dei bit presenti nei due operandi)
or_or1 proc    
    
    mov ax,op1
    mov bx,op2
    
    or ax,bx  ;uso l'istruzione OR che confronta il valore in bit dei due operandi
    
    mov result,ax
    
    ret
    
or_or1 endp 
;---------------------------
;Procedura per la divisione    
divisione proc
    
    mov ax,op1 
    mov bx,op2
    xor dx,dx  ;azzero DX per il resto
        
    cmp bx,0  ;confronto il secondo operando con 0
    jne giust 
;Errore mostrato a schermo nel caso ci dovesse essere una divisione per 0
error1:

    mov ah,9
    lea dx,error_zero
    int 21h
    jmp finindus

giust:
    
    div bx ;eseguo la divisione 
    
    mov result,ax ;salva il risultato 
    mov cont_rest,dx ;salva il resto 

finindus:    
    ret
divisione endp

ends
end start ; set entry point and stop the assembler.