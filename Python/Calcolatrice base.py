a = float(input("Inserire il primo valore: "))
b = float(input("Inserire il secondo valore: "))
op = input("Inserire l'operazione da fare (+,-,*,/): ")

if op == '+':
    print(a+b)
elif op == '-':
    print(a-b)
elif op == '*':
    print (a*b)
elif op == '/' and b!=0:
    print (a/b)
else:
    print("Operazione non eseguibile")