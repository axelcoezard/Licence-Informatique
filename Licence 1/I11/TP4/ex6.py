def tuple_sum(u, v):
    if len(u) == len(v):
        sum = ()
        i = 0
        while i < len(u):
            sum += (u[i] + v[i],)
            i += 1
        return sum

def tuple_ask():
    size = int(input("Entrez une taille de tuple:"))
    tuple = ()
    while size != 0:
        tuple += (float(input("Valeur: ")),)
        size -= 1
    return tuple

def tuple_product(u, v):
    if len(u) == len(v):
        product = 0
        i = 0
        while i < len(u):
            product += u[i] * v[i]
            i += 1
        return product

def tuple_module(u):
    product = tuple_product(u, u)
    return product ** .5

def tuple_cosinus(u, v):
    mod_u = tuple_module(u)
    mod_v = tuple_module(v)
    product = tuple_product(u, v)
    return product / mod_v / mod_u

u = tuple_ask()
v = tuple_ask()

print("Tuples:", u, v)
print("Somme de u et v", tuple_sum(u, v))
print("Produit scalaire de u et v:", tuple_product(u, v))
print("Verfication cosinus(u, u):", tuple_cosinus(u, u))
print("Cosinus u et v:", tuple_cosinus(u, v))
