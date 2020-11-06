def multbyalpha(b, f):
    resultat = b << 1
    taille = len(bin(f)) - 3
    if ((resultat & (1 << taille)) != 0):
        resultat ^= f
    return resultat
