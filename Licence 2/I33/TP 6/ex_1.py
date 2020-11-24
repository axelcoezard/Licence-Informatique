def decompose(n):
    D, i = dict(), 2
    while n != 1:
        if n % i == 0:
            n //= i
            D[i] = [i, D[i][1] + 1] if i in D else [i, 1]
        else:
            i += 1
    return list(D.values())


print(decompose(99999876400))
