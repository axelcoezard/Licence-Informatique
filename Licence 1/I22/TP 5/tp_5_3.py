def majuscule(chaine):
    whitelist = "abcdefghijklmnopqrstuvwxyz"
    chrs = [chr(ord(c) - 32) if c in whitelist else c for c in chaine]
    return "".join(chrs)

print(majuscule("axel coezard"))

def val2ascii(entier):
    ch = ""
    for i in range(entier):
        ch = chr(ord(ch) + 1)
    print(ch)

val2ascii(355)
