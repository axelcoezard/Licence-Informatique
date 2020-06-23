# nombres : de 48 à 57
# lettres : de 92 à 122

text = input("entez une chaine de caracteres")
words = text.split(" ")
numbers = ""

for word in words:
    i = 0
    containsLetter = 92 <= ord(word[i]) <= 122
    while i < len(word) and containsLetter:
         containsLetter = 92 <= ord(word[i]) <= 122
         i += 1
    if not containsLetter:  numbers += " " + word

print("nombres presents:" + numbers)
