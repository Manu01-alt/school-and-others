;GIZZI MANUEL 3CINF
; dopo aver completato il codice dall'esempio3, implementare l'input
;dei dati (sfruttare le procedure definite negli esercizi precedenti)


acapo macro
    
    mov ah, 2
    mov dl, 13
    int 21h   
    mov dl, 10
    int 21h
 endm 





data segment
    ; add your data here!
distance DW 6, 0 ; Distanza per viaggio (km)
cost_per_km DW 6, 0 ; Costo per chilometro
budget DW 6, 0 ; Budget totale disponibile
cost_per_trip DW 0 ; Costo totale per viaggio
max_trips DW 0 ; Numero massimo di viaggi
remaining_budget DW 0 ; Residuo del budget
str_budget db "Budget disponibile: $"
str_costo db "Costo per viaggio: $"
str_viaggi db "Viaggi massimi: $"
str_budget_res db "Budget residuo: $"
str_richiesta_dist db "inserire distanza (Km): $"
str_richiesta_cost_km db "inserire costo per chilometro: $"
str_richiesta_budget db "inserire budget: $"
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
   
    
MOV AX, @DATA ; Inizializza il segmento dati
MOV DS, AX                         

    lea dx, str_richiesta_dist
    mov ah, 9
    int 21h 
    ;inserisco la distanza
    lea dx, distance
    mov ah, 0Ah
    int 21h
    
    acapo        
    lea dx, str_richiesta_cost_km 
    mov ah, 9
    int 21h 
    ;Inserisco il costo per km        
    lea dx, cost_per_km
    mov ah, 0Ah
    int 21h 
    
    acapo
    
    lea dx, str_richiesta_budget
    mov ah, 9
    int 21h 
    ;inserisco il budget
    lea dx, budget
    mov ah, 0Ah
    int 21h 
    
    acapo


; Costo per viaggio (cost_per_trip = distance * cost_per_km)
MOV AX, distance ; Carica la distanza in AX
MOV BX, cost_per_km ; Carica il costo per km in BX
MUL BX ; AX = distance * cost_per_km
MOV cost_per_trip, AX ; Salva il risultato in cost_per_trip
; Numero massimo di viaggi (max_trips = budget / cost_per_trip)
MOV AX, budget ; Carica il budget in AX
MOV BX, cost_per_trip ; Carica il costo per viaggio in BX
DIV BX ; AX = budget / cost_per_trip, DX = resto
MOV max_trips, AX ; Salva il numero massimo di viaggi
MOV remaining_budget, DX ; Salva il budget residuo
; Stampa dei risultati
;Stampa "Budget disponibile:
lea dx, str_budget
mov ah, 9
int 21h
MOV AX, budget ; Carica il costo per viaggio
CALL PRINT_NUMBER ; Stampa il numero
; Stampa "Costo per viaggio: 
lea dx, str_costo
mov ah, 9
int 21h
MOV AX, cost_per_trip
CALL PRINT_NUMBER
; Stampa "Viaggi massimi:"
lea dx, str_viaggi
mov ah, 9
int 21h
MOV AX, max_trips
CALL PRINT_NUMBER
; Stampa "Budget residuo:"
lea dx, str_budget_res
mov ah, 9
int 21h
MOV AX, remaining_budget
CALL PRINT_NUMBER
; Fine del programma
MOV AH, 4CH ; Termina il programma
INT 21H 
; Procedura per stampare un numero (AX contiene il numero da stampare)
PRINT_NUMBER PROC
XOR DX, DX ; Resetta DX
XOR CX, CX ; Resetta CX - contatore cifre
MOV BX, 10 ; Divisore per ottenere le cifre
DIVIDE_LOOP:
DIV BX ; Divide AX per 10
PUSH DX ; Salva il resto sullo stack
XOR DX,DX ; Resetta DX per la prossima divisione
INC CX
OR AX, AX ; Controlla se il quoziente e' 0
JZ PRINT_DIGITS ; Se si', passa alla stampa
JMP DIVIDE_LOOP ; Altrimenti continua a dividere
PRINT_DIGITS:
POP DX ; Recupera la cifra dallo stack
ADD DL, '0' ; Converte la cifra in carattere ASCII
MOV AH, 02H ; Funzione DOS: stampa carattere
INT 21H
LOOP PRINT_DIGITS ; Se si', continua a stampare
MOV DX, 0DH
INT 21H
MOV DX, 0AH
INT 21H
RET
PRINT_NUMBER ENDP

end start ; set entry point and stop the assembler.
