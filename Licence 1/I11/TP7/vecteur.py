"""
    Module vecteur
    créé par Axel Coezard
    le 10 / 12 / 19
"""

def somme_vect(u, v):
    return tuple(a + b for a, b in zip(u, v))

def diff_vect(u, v):
    return tuple(a - b for a, b in zip(u, v))

def prod_scal(u, v):
    return sum(a * b for a, b in zip(u, v))

def prod_mat_vec(u, m):
    return tuple(prod_scal(u, v) for v in m)
