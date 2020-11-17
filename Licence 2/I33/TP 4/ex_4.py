import random
from ex_3 import gentrianginf


def gensym(n, t):
    N = gentrianginf(n, t)
    i = 0
    for i in range(n):
        for j in range(i + 1, n):
            N[i][j] = N[j][i]
    return N


print(gensym(4, 10))
