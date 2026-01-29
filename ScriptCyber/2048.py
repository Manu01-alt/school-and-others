from pwn import remote

io = remote("2048.challs.olicyber.it", 10007)
io.recvlines(2) #salta le prime due righe

for _ in range(2048):
    operatore = io.recvuntil(b" ").strip().decode()
    x = int(io.recvuntil(b" ").strip().decode())
    y = int(io.recvuntil(b" ").strip().decode())

    print(_, operatore, x, y)

    result = 0
    match operatore:
        case "SOMMA":
            result = x+y
        case "DIFFERENZA":
            result = x-y
        case "PRODOTTO":
            result = x*y
        case "DIVISIONE_INTERA":
            result = x//y
        case "POTENZA":
            result = x**y

    io.sendline(str(result).encode())

io.interactive()