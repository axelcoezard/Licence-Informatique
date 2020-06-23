def somme(u, v):
    if len(u) == len(v):
        sum = ()
        i = 0
        while i < len(u):
            sum += (u[i] + v[i],)
            i += 1
        return sum

def mult(u, a):
    product = ()
    i = 0
    while i < len(u):
        product += (u[i] * a,)
        i += 1
    return product

def produit_scalaire(u, v):
    if len(u) == len(v):
        product = 0
        i = 0
        while i < len(u):
            product += u[i] * v[i]
            i += 1
        return product

def norme(u):
    product = produit_scalaire(u, u)
    return product ** .5

def cosinus(u, v):
    mod_u = norme(u)
    mod_v = norme(v)
    product = produit_scalaire(u, v)
    return product / mod_v / mod_u

def saisit_vecteur():
    size = int(input("Entrez une taille de vecteur:"))
    tuple = ()
    while size != 0:
        tuple += (float(input("Valeur: ")),)
        size -= 1
    return tuple

u = saisit_vecteur()
v = saisit_vecteur()

print("Tuples:", u, v)
print("Somme de u et v", somme(u, v))
print("Produit de u et 8.5:", mult(u, 8.5))
print("Produit scalaire de u et v:", produit_scalaire(u, v))
print("Verfication cosinus(u, u):", cosinus(u, u))
print("Cosinus u et v:", cosinus(u, v))
