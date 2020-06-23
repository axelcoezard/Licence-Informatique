from pocketnoobj import *

characters = input("saisir une chaine de caracteres :")
contains = 0

for char in characters:
    if char == " ": contains += 1

print("la chaine contient", contains, "fois ' '")
