from time import time

"""
    QUESTION 1
"""
def factorielle(n):
    f = 1
    for i in range(1, n + 1): f *= i
    return f


"""
    QUESTION 2
"""
def TrianglePascal(n):
    c = []
    for x in range(n): c += [[1] * (x + 1)]
    for x in range(2, n):
        for y in range(1, x):
            c[x][y] = c[x - 1][y - 1] + c[x - 1][y]
    return c

"""
    QUESTION 3
"""
def phoque(n):
    if n == 1: return ["."]
    elif n == 2: return ["-", ".."]

    n_1 = ["." + a for a in phoque(n - 1)]
    n_2 = ["-" + a for a in phoque(n - 2)]

    return n_1 + n_2

"""
    QUESTION 4
"""
def phoqueit(n):
    s1 = ["."]
    s2 = ["-", ".."]

    if n == 0: return s1
    elif n == 1: return s2

    for i in range(2, n):
        s1b = [a + "-" for a in s1]
        s2b = [a + "." for a in s2]
        s1, s2 = s2, s1b + s2b

    return s2

# start_1 = time()
# phoque(30)
# time_1 = time() - start_1

# start_2 = time()
# phoqueit(30)
# time_2 = time() - start_2

# print(time_1,["." + a time_2)

"""
    QUESTION 5
"""
def Fibonacci(n):
    termes = tuple()
    for i in range(n + 1):
        j, f1, f2 = 0, 0, 1
        while j < i:
            f1, f2 = f2, f1 + f2
            j += 1
        termes += (f2,)
    return termes

"""
    QUESTION 6
"""
def genuplet(n, m, nuplet):
    if n > 0:
        for i in range(m):
            genuplet(n - 1, m, nuplet + (i + 1,))
    else: print(nuplet)

genuplet(2, 3, ())
