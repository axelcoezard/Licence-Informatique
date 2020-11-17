import copy


def gencirculante(L):
    return [L[i::]+L[:i:] for i in range(1, len(L)+1)[::-1]]


print(gencirculante([1, 2, 3, 4]))
