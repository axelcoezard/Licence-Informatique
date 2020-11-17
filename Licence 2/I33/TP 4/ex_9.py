import random


def liste_perm(n):
    L = []
    for i in range(n):
        L += [i]
    i = 1
    while i < n:
        perm = random.randrange(0, n-i)
        tmp = L[perm]
        L[perm] = L[n-i]
        L[n-i] = tmp
        i += 1
    return L
