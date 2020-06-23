text = input("entez une chaine de caracteres: ")
n_numbers = 0
n_words = 0
j = 0
state = 0

while j < len(text):
    if state == 0 and text[j] != " ":
        state = 1
        if 92 <= ord(text[j]) <= 122: n_words += 1
        else: n_numbers += 1
    elif state == 1 and text[j] == " ":
            state = 0
    j += 1

print("Nombre de nombres:", n_numbers)
print("Nombre de mots:", n_words)
