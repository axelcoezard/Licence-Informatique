liste = []

number = float(input("Entrez un nombre: "))
while number != 0:
    liste += [number]
    number = float(input("Entrez un nombre: "))

print(liste)
