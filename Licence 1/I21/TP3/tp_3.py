def factorielle(n):
    f = 1
    for i in range(1, n + 1): f *= i
    return f


def TrianglePascal(n):
    coeffs = []
    for x in range(0, n): # x va de 0 à n - 1
        line = [0] * (x + 1)
        for y in range(x + 1): # y va de 0 à x - 1
            line[y] = factorielle(x) / (factorielle(x - y) * factorielle(y))
        coeffs += [line]
    return coeffs


print(TrianglePascal(6))
