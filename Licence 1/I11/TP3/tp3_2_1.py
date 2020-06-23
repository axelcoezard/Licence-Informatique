from pocketnoobj import *

ch = input("saisir une chaine de caracteres :")
i = 0

while i < len(ch):
    if isalpha(ch[i]): print(ch[i], "Lettre")
    elif isdigit(ch[i]): print(ch[i], "Chiffre")
    else: print(ch[i], "Caractere special")
    i = i + 1
