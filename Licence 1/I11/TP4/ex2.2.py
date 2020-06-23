liste = []
entiers = 0
somme = 0

isZero = False
while not isZero:
    number = float(input("Entrez un nombre: "))
    if number == 0: isZero = True
    elif number - int(number) == 0:
        entiers += 1
        somme += number
    liste += [number]

print("Liste:", liste)
print("Nombre d'entiers:", entiers)
print("Somme des entiers:", somme)
