from ex_9 import liste_perm


def genmatrixperm(n):
    M = [0] * n
    liste_p = liste_perm(n)
    for i in range(n):
        M[i] = [0] * n
        M[i][liste_p[i]] = 1
    return M
