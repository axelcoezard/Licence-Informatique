def recherche2(L,S,p):
    T = []
    k = 0
    somme = L[0]
    i = 1
    while i <= p:
        somme += L[i]
        i += 1
    if somme >= S:
        T += [0]
    k = 1
    while k < len(L) - p:
        somme += L[p+k] - L[k-1]
        if somme >= S:
            T += [k]
        k += 1
    return T