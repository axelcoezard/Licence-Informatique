def multbyalpha(b, f):
    resultat = b << 1
    taille = len(bin(f)) - 3
    if ((resultat & (1 << taille)) != 0):
        resultat ^= f
    return resultat


def table_alpha(P):
    m = len(bin(P)) - 3
    length = 1 << m
    lisst, a, index = [0] * (length-1), 1, 0
    while index < length - 1:
        lisst[index] = a
        a = multbyalpha(a, P)
        index += 1
    return lisst


print(table_alpha(13))
