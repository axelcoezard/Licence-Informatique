import random
from ex_3 import gentrianginf


def genasym(n, t):
    L = gentrianginf(n, t)
    for i in range(n):
        for j in range(i + 1, n):
            L[i][j] = -L[j][i]
    return L
