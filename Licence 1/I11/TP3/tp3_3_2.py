text = input("entrez une chaine de caracteres : ")

isPalindromic = text[0] == text[len(text) - 1]

i, j = 0, len(text)- 1
while i < j and isPalindromic:
    isPalindromic = text[i] == text[j]
    i, j = i + 1, j - 1

print(isPalindromic)
