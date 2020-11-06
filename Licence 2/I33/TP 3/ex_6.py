def multbyalpha(b, f):
    resultat = b << 1
    taille = len(bin(f)) - 3
    if ((resultat & (1 << taille)) != 0):
        resultat ^= f
    return resultat


def table_log(P):
    m = len(bin(P)) - 3
    c = 1 << m
    L = [-1] * c
    i, j = 1, 0
    while j < c - 1:
        L[i], i = j, multbyalpha(i, P)
        j += 1
    return L
