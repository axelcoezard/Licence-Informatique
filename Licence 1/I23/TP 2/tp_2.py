"""
    QUESTION 1
"""
def Lecture(nomFichier):
    with open(nomFichier, "r+") as fichier:
        X, G, Y = set(), dict(), set()
        for line in fichier.readlines():
            comp = line.rstrip().split(">")
            if len(comp[0]) == 0: continue
            if len(comp[1]) == 0: continue
            if not comp[0] in G.keys():
                G[comp[0]] = set()
            X.add(comp[0])
            G[comp[0]].add(comp[1])
            Y.add(comp[1])
        return X, G, Y


"""
    QUESTION 2
"""
def Reciproque(C):
    G_1 = dict()

    for sortie in C[2]:
        if not sortie in G_1.keys():
            G_1[sortie] = set()
        for entree in C[0]:
            if sortie in C[1][entree]:
                G_1[sortie].add(entree)

    return C[2], G_1, C[0]


"""
    QUESTION 3
"""
def ImageDirecte(C, A):
    sortie = []
    for x in A:
        if x in C[0]: sortie += [C[1][x]]
    return sortie


"""
    QUESTION 4
"""
def ImageReciproque(C, B):
    return ImageDirecte(Reciproque(C), B)


"""
    QUESTION 5
"""
def Composer(g, f):
    G_g = g[1]
    G_f = f[1]
    G = dict()

    for entree_g in G_g.keys():
        for sortie_g in G_g[entree_g]:
            if len(sortie_g) != 0:
                G[entree_g] = ImageDirecte(f, sortie_g)[0]

    return g[0], G, f[2]


"""
    QUESTION 6
"""
def EstFonction(C):
    for value in C[1].values():
        if len(value) > 1:
            return False
    return True


"""
    QUESTION 7
"""
def EstApplication(C):
    if not EstFonction(C): return False
    for entree in C[0]:
        if entree == "": return False
        for sortie in C[1][entree]:
            if len(sortie) == 0:
                return False

    return True

def Affiche(c):
    print("X = ",str(c[0]).replace("'",''))
    print("G = ",str(c[1]).replace("'",''))
    print("Y = ",str(c[2]).replace("'",''),end='\n\n')

C = Lecture("correspondance.txt")
Comp = Composer(C, Reciproque(C))

print("C: \n")
Affiche(C)
print("C-1: \n")
Affiche(Reciproque(C))
print("C-1(C): \n")
Affiche(Comp)
