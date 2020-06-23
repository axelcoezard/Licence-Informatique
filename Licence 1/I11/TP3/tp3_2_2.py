from pocketnoobj import *

characters = input("saisir une chaine de caracteres :")
contains = False

i = 0
while i < len(characters) and characters[i] != " ": i += 1

if i < len(characters): print("la chaine contient ' '")
else: print("la chaine ne contient pas ' '")
