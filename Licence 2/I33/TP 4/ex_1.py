import random


def genmatrix(n, p, t):
    N = [0] * n
    for i in range(n):
        N[i] = [0] * p
        for j in range(p):
            N[i][j] = random.randrange(0, t)
    return N


print(genmatrix(2, 3, 7))
