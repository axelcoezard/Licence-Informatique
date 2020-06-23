choice = input("Chiffrement ( E ) ncode ou Dechiffrement ( D ) ecode ? ")
key = int(input("Cle de chiffrement ? "))
text = input("Texte ? ")
cypher = ""

if choice == "D": key *= -1

i = 0
while i < len(text):
    if text[i] == " ": cypher += " "
    else: cypher += chr(ord(text[i]) + key)
    i += 1

print("Chiffre :", cypher)
