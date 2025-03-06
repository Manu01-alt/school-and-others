def calculate_love_score(name1, name2):
    
    true_score = 0
    love_score = 0

    nome_concatenato = name1 + name2
    nome_concatenato.lower()


    for letter in "true":
            if letter.isalpha():
                true_score += nome_concatenato.count(letter)
    
    for letter in "love":
            if letter.isalpha():
                love_score += nome_concatenato.count(letter)

    return (str(true_score) + str(love_score))



name1 = input("Inserisci il primo nome: ")
name2 = input("Inserisci il secondo nome: ")
print(calculate_love_score(name1, name2))