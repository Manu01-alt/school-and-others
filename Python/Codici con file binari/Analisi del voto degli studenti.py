file = open("studenti.txt", "r")

righe = file.readlines()
file.close()

dict={}

for i in righe:
    riga = i.strip().split(" ")
    dict.update({riga[0]: riga[1]})
    

sum = 0 

for i in dict.keys():
    sum += int(dict[i])
media = sum / len(dict)
print(f"\nLa media dei voti è: {media:.2f}")
 

max_voto = max(int(voto) for voto in dict.values())
print(f"\nIl voto massimo è: {max_voto}")

studenti_max = []
for i in dict.keys():
    if int(dict[i]) == max_voto:
        studenti_max.append(i)

print("Gli studenti con il voto massimo sono:")
for studente in studenti_max:
    print(f"- {studente}")



dict_voti = {}

for i in dict.keys():
    voto = int(dict[i])
    if voto not in dict_voti:
        dict_voti[voto] = []
    dict_voti[voto].append(i)

print("\n", dict_voti)