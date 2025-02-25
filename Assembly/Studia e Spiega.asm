; Cosa fa il seguente programma? Senza implementarlo su emu, inserire
; i commenti mancanti (;?) e fornire una spiegazione a parole del
; programma e dell'idea che c'e' sotto.
; NB. Eventuali istruzioni o direttive non note dovranno essere
; approfondite autonomamente

.model small   ;?
.stack 100     ;?

.data
    output_msg db 13, 10, "Stringa invertita: $"

.code
    mov ax, @data  ;carico l'indirizzo del segmento in ax
    mov ds, ax     ;imposto il data segment  
    mov ss, ax     ;imposto lo stack segment
    mov sp, 80h   ; Inizializza la cima dello stack

    ;?
    mov ax, 01h   ;imposto in ax 1 e sposto nello stack
    push ax
 
read_and_push:
    mov ah, 01h
    int 21h 
    cmp al, 0Dh   ;controllo se il carattere e' invio
    je print
    push ax       ;sposto il carattere nello stack
    jmp read_and_push

print: 
    lea dx, output_msg ;carico in dx l'offset del messaggio di output
    mov ah, 09h   ;uso l'interrupt per l'output di una stringa
    int 21h

print_reverse:
    pop dx        ;sposto dallo stack in dx l'ultimo carattere
    cmp dl, 0Dh   ;controllo se e' invio
    je final_exit
    mov ah, 02h   ;stampo il carattere
    int 21h
    jmp print_reverse

final_exit:
    mov ah, 4Ch   ; Uscita dal programma
    int 21h

end

; Questo programma contiene una grave falla di sicurezza:
; sapresti dire qual'e'? (come innescarla e cosa provoca?)
; Come dovrebbe essere modificato il programma? (come
; patchare il codice?)
                        
                        
;si verifica uno stack overflow dove data segment e stack segment si incontrano