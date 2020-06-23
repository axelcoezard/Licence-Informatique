a = input("Valeur de a : ")
b = input("Valeur de b : ")
operator = input("Choix de l'operateur parmi (+,-,*,/) : ")

result = eval(a + operator + b)

print("Le resultat est", a, operator, b, "=", result)
print("Cette expression est de type", type(result))
