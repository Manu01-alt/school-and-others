jmp inizio

stringa db 100, ?, 100 dup(0)

inizio:
    lea dx, stringa
    mov ah, 0Ah
    int 21h

    mov dl, 10
    mov ah, 2
    int 21h
    mov dl, 13
    mov ah, 2
    int 21h

    mov cl, stringa[1]
    lea si, stringa + 2

ciclo:
    mov al, [si]
    inc si

    ; Ignora caratteri non alfabetici (spazi, punteggiatura)
    cmp al, 'a'
    jl controlla_maiuscole
    cmp al, 'z'
    jle rot13_minuscole

controlla_maiuscole:
    cmp al, 'A'
    jl fine_ciclo
    cmp al, 'Z'
    jg fine_ciclo

rot13_minuscole:
    add al, 13
    cmp al, 'z'
    jg riavvolgi_minuscole
    jmp stampa

riavvolgi_minuscole:
    sub al, 26
    jmp stampa

rot13_maiuscole:
    add al, 13
    cmp al, 'Z'
    jg riavvolgi_maiuscole
    jmp stampa

riavvolgi_maiuscole:
    sub al, 26

stampa:
    mov dl, al
    mov ah, 2
    int 21h

fine_ciclo:
    dec cl
    jnz ciclo

    ret
