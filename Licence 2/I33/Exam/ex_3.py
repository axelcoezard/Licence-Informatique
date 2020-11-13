def decompose(n):
    T = []
    while n != 0:
        T += [n & 1]
        n = n >> 1
    return T[::-1]


print(decompose(14))
