from random import *

"""

    Modélisation à partir d'une liste

"""

def init_ram_list(taille):
    return [0] * taille

# RAM = init_ram_list(16)
# print(RAM)

def fill_ram_random(ram, N):
    for n in range(N):
        index = randint(0, len(ram) - 1)
        valeur = randint(1, 255)
        ram[index] = valeur
    return ram

# RAM = fill_ram_random(RAM, 5)
# print(RAM)

def fill_ram_place(ram, N):
    for n in range(N):
        index = randint(0, len(ram) - 1)
        ram[index] = index
    return ram

# RAM = fill_ram_place(RAM, 5)
# print(RAM)

def get_value_list(ram, adresse):
    return ram[adresse]

# print(get_value_list(RAM, 3))
# print(get_value_list(RAM, 4))

"""

    Modélisation à partir d'un dictionnaire

"""

def init_ram_dict(taille):
    return {"taille": taille}

# RAM = init_ram_dict(16)
# print(RAM)

def fill_ram_random_dict(ram, N):
    for n in range(N):
        index = randint(1, ram["taille"] - 1)
        valeur = randint(1, 255)
        ram[index] = valeur
    return ram

# RAM = fill_ram_random_dict(RAM, 5)
# print(RAM)

def fill_ram_place_dict(ram, N):
    for n in range(N):
        index = randint(1, ram["taille"] - 1)
        ram[index] = index
    return ram

# RAM = fill_ram_place_dict(RAM, 5)
# print(RAM)

def get_value_dict(ram, adresse):
    return ram.get(adresse, 0)

# print(get_value_dict(RAM, 3))
# print(get_value_dict(RAM, 4))
# print(get_value_dict(RAM, 30))


"""

    Cache Full associative

"""

def is_in(mem_asso, mot):
    taille = len(mem_asso)
    etat = "MISS"
    comparaisons = []
    index = None
    for i, m in enumerate(mem_asso):
        if not m == mot: comparaisons += [False]
        else:
            comparaisons += [True]
            index = i
            etat = "HIT"
    return (etat, comparaisons, index)

# print([4, 1, 2, 0])
# print(3, is_in([4, 1, 2, 0], 3))
# print(1, is_in([4, 1, 2, 0], 1))
# print(0, is_in([4, 1, 2, 0], 0))

def get_value(mem, idx):
    if idx > len(mem): return None

    value = mem[idx]
    if not value["ok"]:
        value["data"] = None
    return value

# M = [
#     {'ok': True, 'data': 0x44},
#     {'ok': False, 'data': 0XFF},
#     {'ok': True, 'data': 0x22},
#     {'ok': True, 'data': 0x99}
# ]
#
# print(3, get_value(M, 3))
# print(1, get_value(M, 1))

def in_cache(mem_asso, mem_class, adresse):
    cache = is_in(mem_asso, adresse)
    value = get_value(mem_class, adresse)

    if cache[0] == "HIT" and value["ok"]:
        return ("HIT", value["data"])
    return ("MISS", None)

# mem_associative = [4, 1, 2, 0]
# mem_classique = [
#     {'ok': True,  'data': 0x44},
#     {'ok': False, 'data': 0XFF},
#     {'ok': True,  'data': 0x22},
#     {'ok': True,  'data': 0x00}
# ]
#
# print(3, in_cache(mem_associative, mem_classique, 3))
# print(1, in_cache(mem_associative, mem_classique, 1))
# print(2, in_cache(mem_associative, mem_classique, 2))



"""

    Cache direct-mapped

"""

def in_cache_direct_mapped(mem_class, adresse):
    if adresse > len(mem_class):
        adresse = len(mem_class) - 1
    value = get_value(mem_class, adresse)
    etat = "MISS"
    data = None

    if value["ok"]:
        etat = "HIT"
        data = value["data"]

    return (etat, data)

# mem_classique = [
#     {'ok': True, 'data': 0x00},
#     {'ok': False, 'data': 0XFF},
#     {'ok': True, 'data': 0x22},
#     {'ok': True, 'data': 0x77}
# ]
#
# print(0, in_cache_direct_mapped(mem_classique, 0))
# print(7, in_cache_direct_mapped(mem_classique, 7))
# print(1, in_cache_direct_mapped(mem_classique, 1))
# print(3, in_cache_direct_mapped(mem_classique, 3))

"""

    Pour aller plus loin

"""

def in_cache_direct_mapped_fixed(mem_class, adresse):
    binary = str(bin(adresse)).split("0b")[1] # On récupére le code binaire
    tag = binary[:-2] if binary[:-2] != '' else 0 # On récupère le tag

    if adresse > len(mem_class):
        adresse = len(mem_class) - 1

    value = get_value(mem_class, adresse)

    # Si la valeut est OK et que le tag est valide on fini
    if value["ok"] and int(value["tag"]) == int(value["tag"]):
        return "HIT", value["data"]

    return "MISS", None
#
# mem_direct_mapped = [
#     {'ok': True, 'data': 0x00, 'tag': 0x0},
#     {'ok': False, 'data': 0XFF, 'tag': 0x1},
#     {'ok': True, 'data': 0x22, 'tag': 0x0},
#     {'ok': True, 'data': 0x77, 'tag': 0x1}
# ]
#
# print(in_cache_direct_mapped_fixed(mem_direct_mapped, 0), 0)
# print(in_cache_direct_mapped_fixed(mem_direct_mapped, 7), 7)
# print(in_cache_direct_mapped_fixed(mem_direct_mapped, 1), 1)
# print(in_cache_direct_mapped_fixed(mem_direct_mapped, 3), 3)

def replace_random(mem_asso, mem):
    # On liste chaque entrée de la mémoire et son indice,
    # cela nous permet de vérifier si l'entrée est OK
    # et dans le cas contraire on retourne l'indice
    for index, entry in enumerate(mem):
        if not entry["ok"]: return index

    # dans le cas ou toutes les entrées sont OK
    # on retourne un indice aléatoire
    return randint(0, len(mem) - 1)

# mem_associative = [4, 1, 2, 0]
# mem_classique = [
#     {'ok': True, 'data': 0x44},
#     {'ok': False, 'data': 0XFF},
#     {'ok': True, 'data': 0x22},
#     {'ok': True, 'data': 0x00}
# ]
#
# print(replace_random(mem_associative, mem_classique))
#
# mem_classique = [
#     {'ok': True, 'data': 0x44},
#     {'ok': True, 'data': 0XFF},
#     {'ok': True, 'data': 0x22},
#     {'ok': True, 'data': 0x00}
# ]
#
# print(replace_random(mem_associative, mem_classique))


def add_fifo(fifo, valeur):
    # On cherche l'indice du premier None
    noneIndex = 0
    while noneIndex < len(fifo) and fifo[noneIndex] != None:
        noneIndex += 1
    # On vérifie si la file est pleine
    if noneIndex >= len(fifo): return False
    # Si elle ne l'est pas on ajoute la valeur
    else:
        fifo[noneIndex] = valeur
        return fifo


# fifo = [None, None, None, None]
# print(fifo)
# fifo = add_fifo(fifo, 10)
# print(fifo)
# fifo = add_fifo(fifo, 99)
# print(fifo)
# fifo = add_fifo(fifo, 2)
# print(fifo)


def get_fifo(fifo):
    # On récupère et enlève la valeur à l'indice 0
    valeur = fifo.pop(0)
    # On ajoute un None à la fin de la file
    fifo.append(None)
    return fifo, valeur


# fifo = [10, 99, 2, None]
# print(fifo)
#
# fifo, valeur = get_fifo(fifo)
# print(fifo, valeur)
#
# fifo, valeur = get_fifo(fifo)
# print(fifo, valeur)
#
# fifo, valeur = get_fifo(fifo)
# print(fifo, valeur)


def replace_fifo(mem, fifo):
    # On trouve l'indice de la première entrée
    # de la mémoire qui est invalide
    invalideIndex = None
    for index, entry in enumerate(mem):
        if not entry["ok"]:
            invalideIndex = index
            break

    #SI une entrée est invalide
    # on retourne son indice et la nouvelle file
    if invalideIndex != None:
        return invalideIndex, add_fifo(fifo, invalideIndex)
    # SInon on récupère la plus ancienne valeur
    # et on la remet au dessus del a file
    else:
        valeur = get_fifo(fifo)[1]
        fifo = add_fifo(fifo, valeur)
        return valeur, fifo

# mem_classique = [{'ok': True, 'data': 0x44}, {'ok': False, 'data': 0XFF},
#                  {'ok': True, 'data': 0x22}, {'ok': True, 'data': 0x00}]
#
# print(replace_fifo(mem_classique, [2, 3, 0, None]))
#
# mem_classique = [{'ok': True, 'data': 0x44}, {'ok': True, 'data': 0XFF},
#                  {'ok': True, 'data': 0x22}, {'ok': True, 'data': 0x00}]
#
# print(replace_fifo(mem_classique, [2, 3, 0, 1]))
#
# mem_classique = [{'ok': True, 'data': 0x44}, {'ok': True, 'data': 0XFF},
#                  {'ok': True, 'data': 0x22}, {'ok': True, 'data': 0x00}]
#
# print(replace_fifo(mem_classique, [3, 0, 1, 2]))

def update_lru(pile, valeur):
    # On cherche l'indice du premier None
    noneIndex = 0
    while noneIndex < len(pile) and pile[noneIndex] != None:
        noneIndex += 1
    noneIndex -= 1 #On trouve l'indice du dernier nombre en cache

    # On cherche l'indice de la valeur a mettre àjour
    index = 0
    while pile[index] != valeur:
        index += 1

    pile.pop(index) # On enlève la valeur
    pile.pop(noneIndex) # On enlève le None
    pile.append(valeur) # On ajoute la valeur à la fin
    pile.append(None) # O, rajoute le None enlevé

    return pile

pile = [2, 3, 0, None]

pile = update_lru(pile, 3)
print(pile)

pile = update_lru(pile, 2)
print(pile)

pile = update_lru(pile, 2)
print(pile)
