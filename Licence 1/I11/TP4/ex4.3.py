liste = ["axel", "coezard", "transporation", "space", "elon", "musk"]

longueur = int(input("Entrez une longueur: "))
ofLongueur = []

i = 0
while i < len(liste):
    if len(liste[i]) == longueur:
        ofLongueur += [i]
    i += 1

print("Mots:", liste)
print("Mots de taille", longueur, ":", ofLongueur)
