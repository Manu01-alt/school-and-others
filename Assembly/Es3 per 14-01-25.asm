;GIZZI MANUEL 13/01/25
;Implementare un programma che legge un numero (fino a 65535) lo memorizza in una word e lo stampa. 
;Per farlo dovrete usare gli INT 21h per l'I/O di stringhe e codificare le seguenti procedure:
;str2int: riceve in AX l'offset della stringa contenente le cifre e restituisce in AX il numero intero
;int2str: riceve in AX il numero intero e in DX l'offset del buffer in cui salvare il numero in formato stringa, terminata con '$'.


data segment
buffer dw 6,?,6 dup(?) 
richiesta db "Inserisci un numero: $"
num dw 0
ends

stack segment
dw 128 dup(0)
ends

code segment
start:
mov ax, data
mov ds, ax
mov es, ax 

lea dx, richiesta
mov ah, 9
int 21h

lea dx, buffer
mov ah, 0Ah
int 21h

call str2int

str2int proc
mov ax, [buffer+2]
mov bx, 10
mov cx, 0

convert_loop:
xor dx, dx
div bx
push dx
inc cx
inc ax
cmp ax, 0
jnz convert_loop

mov ah, 02h

print_loop:
pop dx
add dl, '0'
int 21h
dec cx
jnz print_loop

str2int endp

mov ax, 4c00h
int 21h
ends

end start
