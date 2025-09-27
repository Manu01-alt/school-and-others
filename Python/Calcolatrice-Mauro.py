
flag = 0
while flag != 1:
    print("\nScrivere l'operazione")
    user_input = input()
    num1 = ""
    num2 = ""
    operazione = ""
    
    if user_input.lower() == "fine":
        print("Byeee...")
        flag = 1
        continue

    for n in user_input:
        if n == "+" or n == "-" or n == "*" or n == "x" or n == "/" or n == ":":
            operazione = n

    user_input = user_input.split(operazione)

    num1 = float(user_input[0])
    num2 = float(user_input[1])

    if operazione == "+":
        risultato = num1 + num2
    elif operazione == "-":
        risultato = num1 - num2
    elif operazione == "*" or operazione == "x":
        risultato = num1 * num2
    elif operazione == "/" or operazione == ":":
        if num2 == 0:
            risultato = "Errore: Divisione per zero"
        else:
            risultato = num1 / num2

    print("Risultato:", risultato)
