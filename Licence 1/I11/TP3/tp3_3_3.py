n_text = input("entrez une chaine de caracteres : ")

isPalindromic = n_text[0] == n_text[len(n_text) - 1]

i, j = 0, len(n_text)- 1
while i < j and isPalindromic:
    if n_text[i] == " ": i += 1
    elif n_text[j] == " ": j -= 1
    else:
        isPalindromic = n_text[i] == n_text[j]
        i, j = i + 1, j - 1

print(isPalindromic)
