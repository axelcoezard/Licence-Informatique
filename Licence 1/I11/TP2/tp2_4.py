next = True

while next:
    a = input("Valeur de a : ")
    b = input("Valeur de b : ")
    operator = input("Choix de l'operateur parmi (+,-,*,/) : ")

    result = eval(a + operator + b)

    print("Le resultat est", a, operator, b, "=", result)
    print("Cette expression est de type", type(result))

    next = input("Continuer (y/n) ? ")
    if next == "n": next = False
