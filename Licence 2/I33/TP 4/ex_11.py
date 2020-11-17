from ex_9 import liste_perm


def genmatrixperm2(n):
    M = [0] * n
    liste_p = liste_perm(n)
    for i in range(n):
        M[i] = 1 << liste_p[i]
    return M
