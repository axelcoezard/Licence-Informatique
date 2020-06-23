text = input("entrez une chaine de caracteres : ")

i, j = 0, len(text) - 1
while i < len(text) and j > 0:
    if i < len(text) // 2: print(text[i], text[j])
    i, j = i + 1, j - 1
if len(text) % 2 == 1: print(text[len(text) // 2])
