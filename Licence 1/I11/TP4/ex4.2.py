liste = ["axel", "coezard", "transporation", "space", "elon", "musk"]

inf5  = []
sup10 = []

for word in liste:
    if len(word) < 5: inf5 += [word]
    elif len(word) > 10: sup10 += [word]

print("Mots:", liste)
print("Mots de taille inf. à 5:", inf5)
print("Mots de taille sup. à 10:", sup10)
