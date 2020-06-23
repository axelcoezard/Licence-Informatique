note = float(input("Entrer une note sur 20: "))

if note >= 10:
    if note >= 16:
        print("Vous avez réussi l'examen avec mention très bien")
    elif note => 14:
        print("Vous avez réussi l'examen avec mention bien")
    elif note => 12:
        print("Vous avez réussi l'examen avec mention assez bien")
    else:
        print("Vous avez réussi l'examen sans mention")
else:
    print("Vous avez pas réussi l'examen")
