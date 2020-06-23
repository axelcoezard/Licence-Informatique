from pocketnoobj import *

characters = input("saisir une chaine de caracteres :")
newChaine = ""


for char in characters:
    if char != " ": newChaine += str(char)

print(newChaine)
