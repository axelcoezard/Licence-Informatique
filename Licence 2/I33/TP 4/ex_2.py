import random


def gendiag(n, t):
    N = [0] * n
    for i in range(n):
        N[i] = [0] * n
        N[i][i] = random.randrange(0, t)
    return N


print(gendiag(4, 10))
