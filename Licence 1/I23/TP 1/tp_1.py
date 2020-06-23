from random import *

lettres = "abcdefghijklmnopqrstuvwxyz"
parentheses = "()"
operateurs = "!+*"

"""
    Fonction qui sert à lister les variables de l'expression
    rentré en paramètre.

    @param String expression

    @return La liste triée des variables
"""
def ListerVariables(expression):
    variables = []
    for char in expression:
        if char in lettres and not char in variables:
            variables += [char]
    return sorted(variables)


"""
    Fonction qui génère le dictionnaire des variables rentrées
    en paramètre

    @param List variables

    @return Le dictionnaire des variables
"""
def DicoVariables(variables):
    dicovar = {}
    for i, char in enumerate(variables): dicovar[char] = i
    return dicovar


"""
    Fonction qui converti un entier en binaire de n bits.

    @param Integer L'entier
    @param Integer n bits

    @return String Le nombre binaire
"""
def Int2Bin(entier, n):
    binn = bin(entier)[2:]
    if len(binn) < n:
        binn = "0" * (n - len(binn)) + binn
    return binn


"""
    Fonction qui converti un binaire en un tuple de booléens.

    @param String Le binaire

    @return Le tuple de booléens
"""
def Bin2Bool(bits):
    tuple = ()
    for bit in bits:
        tuple += ("True" if bit == "1" else "False",)
    return tuple


"""
    Fonction qui génère un nombre soit égale à 1 soit à 0.

    @return Le nombre 1 ou 0.
"""
def RandBin():
    return 0 if random() < 0.5 else 1


"""
    Fonction qui remplace les !, * et + par respectivement not,
    and et or. Elle remplace aussi les variables par leurs valeurs.

    @param String L'expression
    @param Tuple Les valeurs des variables
    @param Dict Le dictionnaire des variables

    @return L'expression changée
"""
def Math2Python(expression, vecteur, dicovar):
    n_expr = ""
    for char in expression:
        if char == "!": n_expr += "not "
        if char == "*": n_expr += "and"
        if char == "+": n_expr += "or"
        if char == "(": n_expr += "("
        if char == ")": n_expr += ")"
        if char == " ": n_expr += " "
        if char in dicovar:
            n_expr += str(vecteur[dicovar[char]])

    return n_expr


"""
    Fonction qui calcule la table de verité d'une expression.

    @param String L'expression
    @param Dict Les variables
"""
def TableVerite(expression, dicovar):
    n = len(dicovar)

    vecteurs = [(RandBin(), RandBin(), RandBin())]
    len_t = len(vecteurs)
    while len_t < 2**n:
        t = (RandBin(), RandBin(), RandBin())
        if not t in vecteurs: vecteurs += [t]
        len_t = len(vecteurs)

    result = []
    for vecteur in vecteurs:
        result += [vecteur + (1 if eval(Math2Python(expression, vecteur, dicovar)) else 0,)]

    return result


"""
    Fonction qui affiche la table de verité dans la console.

    @param Dict Les variables
    @param String L'expression
    @param List<Tuple> Liste des lignes du tableau
"""
def AfficheTableVerite(dicovar, expression, result):
    line_1 = "| " + " | ".join(list(sorted(dicovar.keys())) + [expression])  + " |"
    line_a = "—" * len(line_1)

    print("\n" + line_a)
    print(line_1)
    print(line_a)

    for i in range(len(result)):
        v = ["1" if v else "0" for v in sorted(result)[i]]
        print("| " + " | ".join(v))

    print(line_a + "\n")


"""
    Fonction qui calcul la forme normal conjonctive de la table
    de vérité.

    @param List<Tuple> Table de vérité
    @param List Liste des variables
"""
def FNC(TDV, listevar):
    disjonctiv = []

    for vector in TDV:
        if vector[len(vector)-1] == 0:
            monome = []
            for index, value in enumerate(vector[:len(vector)-1]):
                character = listevar[index]
                monome += [character if value == 1 else character + "\u0304"]
            disjonctiv += ["(" + "+".join(monome) + ")"]

    return "*".join(disjonctiv)


"""
    Fonction qui calcul la forme normal disjonctive de la table
    de vérité.

    @param List<Tuple> Table de vérité
    @param List Liste des variables
"""
def FND(TDV, listevar):
    disjonctiv = []

    for vector in TDV:
        if vector[len(vector)-1] == 1:
            monome = ""
            for index, value in enumerate(vector[:len(vector)-1]):
                character = listevar[index]
                monome += character if value == 1 else character + "\u0304"
            disjonctiv += [monome]

    return "+".join(disjonctiv)

expression = "!(p + q) * (!p + r) + (p * q)"

variables = ListerVariables(expression)
dicovar = DicoVariables(variables)
result = TableVerite(expression, dicovar)
fnd = FND(result, variables)
fnc = FNC(result, variables)

AfficheTableVerite(dicovar, expression, result)
print("Forme normale disjonctive:", fnd)
print("Forme normale conjonctive:", fnc)
