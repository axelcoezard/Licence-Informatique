import matplotlib.pyplot as plt
import math as math
from time import time
from random import randrange, randint

def intervalle(a, b, inc):
    values = []
    values += [a]
    while values[len(values)-1] + inc <= b:
        last = values[len(values)-1]
        values += [last + inc]
    return values

"""

    PREMIÈRE COURBES AVEC MATPLOTLIB

"""

def valeur_sin(t):
    return [math.sin(x) for x in t]


def valeur_cos(t):
    return [math.cos(x) for x in t]

# I = intervalle(-math.pi/2, math.pi/2, 0.2)

# plt.plot(I, valeur_sin(I))
# plt.plot(I, valeur_cos(I))
# plt.show()

"""

    ETUDE DE LA MULTIPLICATION

"""

def multiplication(n1, n2):
    n1, n2 = n1[::-1], n2[::-1]

    n = len(n1)
    n3 = [0] * 2 * n

    j = 0
    while j < n:
        i, r = 0, 0
        while i < n:
            p = n3[i + j] + n1[i] * n2[j] + r
            n3[i + j] = p % 10
            r = p // 10
            i += 1
        n3[i + j] = r
        j += 1

    return n3[::-1]

def time_mult_py(n, k):
    taille = 10 ** n

    liste = [(randrange(taille), randrange(taille)) for i in range(k)]

    start = time()
    products = [n1 * n2 for n1, n2 in liste]
    stop = time()

    return stop - start


def nombre_alea(n):
    return [randrange(10) for i in range(n)]


def time_my_mult(n, k):
    liste = [(nombre_alea(n), nombre_alea(n)) for i in range(k)]

    start = time()
    products = [multiplication(n1, n2) for n1, n2 in liste]
    stop = time()

    return stop - start


# I = intervalle(0, 20, 2)[1:]
# p_valeurs = []
# m_valeurs = []

# for i in I:
#     p_valeurs += [time_mult_py(i, 100000)]
#     m_valeurs += [time_my_mult(i, 100000)]


# plt.plot(I, p_valeurs)
# plt.plot(I, m_valeurs)
# plt.show()

"""

    ETUDE DE L'INSTRUCTION '+'

"""

def time_plus(n,k):
    liste = [0] * n

    start = time()
    for i in range(k):
        liste = liste + [i]
    stop = time()

    return stop - start

def time_inc(n,k):
    liste = [0] * n

    start = time()
    for i in range(k):
        liste += [i]
    stop = time()

    return stop - start

def time_append(n,k):
    liste = [0] * n

    start = time()
    for i in range(k):
        liste.append(i)
    stop = time()

    return stop - start

tailles = [256,512,1024,2048,4096,8192]

plus_taille = []
inc_taille = []
append_taille = []

for t in tailles:
    plus_taille += [time_plus(t, 10)]
    inc_taille += [time_inc(t, 10)]
    append_taille += [time_append(t, 10)]

# plt.subplot(221)
# plt.plot(tailles, plus_taille)
# plt.legend("Plus")
# plt.subplot(222)
# plt.plot(tailles, inc_taille)
# plt.legend("Inc")
# plt.subplot(223)
# plt.plot(tailles, append_taille)
# plt.legend("Append")
# plt.show()

"""

    ETUDE DES FONCTIONS MIN ET MAX

"""

def list_alea(n, k):
    return [randrange(k) for i in range(n)]

def time_min(n, k):
    liste = list_alea(n, k)
    start = time()
    for i in liste:
        min(liste)
    stop = time()
    return stop - start


def time_max(n, k):
    liste = list_alea(n, k)
    start = time()
    for i in liste:
        max(liste)
    stop = time()
    return stop - start


# tailles = [256,512,1024,2048,4096,8192]

min_taille = []
max_taille = []

for t in tailles:
    min_taille += [time_min(t, 10)]
    max_taille += [time_max(t, 10)]

plt.subplot(221)
plt.plot(tailles, min_taille)
plt.title("Min")
plt.subplot(222)
plt.plot(tailles, max_taille)
plt.title("Max")
plt.show()


"""

    ETUDE DE LA FONCTION IN

"""

def list_alea(n, k):
    return [randrange(k) for i in range(n)]

def dict_alea(n):
    d = dict()
    for i in range(n):
        d[i] = randrange(10)
    return d

def time_list(n, k):
    liste = list_alea(n, k)
    start = time()
    k in liste
    stop = time()
    return stop - start

def time_dict(n):
    dic = dict_alea(n)
    start = time()
    10 in dic
    stop = time()
    return stop - start

# tailles = [256,512,1024,2048,4096,8192]
#
# list_taille = []
# dict_taille = []
#
# for t in tailles:
#     list_taille += [time_list(t, 10)]
#     dict_taille += [time_dict(t)]
#
# plt.subplot(221)
# plt.plot(tailles, list_taille)
# plt.title("'in' in a list")
# plt.subplot(222)
# plt.plot(tailles, dict_taille)
# plt.title("'in' in a dict")
# plt.show()
