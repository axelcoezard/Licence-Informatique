from math import *

def factorielle(n):
    result = 1
    for i in range(1, n + 1): result *= i
    return result

def puissance(x, n):
    result = 1
    for i in range(0, n): result *= x
    return result

def serie_exp(x, n):
    sum = 0
    for i in range(0, n + 1):
        sum += puissance(x, i) / factorielle(i)
    return sum


x = float(input("Entrer un flottant x: "))
p = int(input("Entrer une precision p: "))

n = 0
while serie_exp(1, n) - exp(1) < (10 ** -p):
    n += 1

print(x, p, "Valeur n:", n, "e=", serie_exp(1, n))
