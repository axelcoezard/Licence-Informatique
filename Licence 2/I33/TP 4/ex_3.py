import random


def gentrianginf(n, t):
    N = [0] * n
    for i in range(0, n):
        N[i] = [0] * n
        for j in range(0, i + 1):
            N[i][j] = random.randrange(0, t)
    return N


print(gentrianginf(4, 7))
