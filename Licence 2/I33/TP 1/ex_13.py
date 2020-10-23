def recherche(L,S,p):
    T = []
    k = 0
    while k < len(L) - p:
        somme = L[k]
        i = k + 1
        while i <= p + k:
            somme += L[i]
            i += 1
        if somme >= S:
            T += [k]
        k += 1
    return T