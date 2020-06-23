#
# FIchier à compléter: parcours.py
#
# Chaque fonction retourne la liste des paires d'indices correspondant
# au parcours nommé.
#

def parcours_ligne(n):
    """Retourne la liste des indices (colonne,ligne) (!!attention ici
    ligne et colonne sont inversées!!)  des cases correspondant à un
    parcours tableau de taille n x n en ligne.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 1,2,3,4,5,6,7,8,9 et la
    fonction retournera la liste d'indices [(0,0),(1,0),(2,0),(0,1) ...]

    """
    return [(x, y) for y in range(0, n) for x in range(0, n)]


def parcours_colonne(n):
    """Retourne la liste des indices (colonne,ligne) (!!attention ici
    ligne et colonne sont inversées!!)  des cases correspondant à un
    parcours de tableau de taille n x n en colonne.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 1,4,7,2,5,8,3,6,9 et la
    fonction retournera la liste d'indices [(0,0),(0,1),(0,2),(1,0) ...]

    """
    return [(x, y) for x in range(0, n) for y in range(0, n)]

def parcours_diagonal(n):
    """Retourne la liste des indices (colonne,ligne) (!!attention ici
    ligne et colonne sont inversées!!)  des cases correspondant à un
    parcours de tableau de taille n x n en diagonale.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 3,2,6,1,5,9,4,8,7 et la
    fonction retournera la liste d'indices [(2,0),(1,0),(2,1),(0,0) ...]

    """

    return []

def parcours_antidiagonal(n):
    """Retourne la liste des indices (colonne,ligne) (!!attention ici
    ligne et colonne sont inversées!!)  des cases correspondant à un
    parcours de tableau de taille n x n en anti-diagonale.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 9,6,8,3,5,7,2,4,1 et la
    fonction retournera la liste d'indices [(2,2),(2,1),(1,2),(2,0) ...]

    """
    return []

def parcours_serpentin(n):
    """Retourne la liste des indices (colonne,ligne) (!!attention ici
    ligne et colonne sont inversées!!)  des cases correspondant à un
    parcours de tableau de taille n x n en serpentin.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 1,2,3,6,9,8,7,4,5 et la
    fonction retournera la liste d'indices [(0,0),(1,0),(2,0),(2,1) ...]

    """


    return []

def parcours_sinusoidal(n):
    """Retourne la liste des indices (ligne,
    colonne) des cases correspondant a un parcours sinusoidal d'un
    tableau de taille n x n.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 1,4,7,8,5,2,3,6,9 et la
    fonction retournera la liste d'indices :
    [(0,0),(1,0),(2,0),(2,1),(2,2) ...]

    """
    return [(y, x if y % 2 == 0 else 9 - x) for y in range(0, n) for x in range(0, n)]

def parcours_zigzag(n):
    """Retourne la liste des indices (ligne,
    colonne) des cases correspondant a un parcours sinusoidal d'un
    tableau de taille n x n.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 1,2,3,6,5,4,7,8,9 et la
    fonction retournera la liste d'indices :
    [(0,0),(0,1),(0,2),(1,2),(1,1) ...]

    """
    return [(x if y % 2 == 0 else 9 - x, y) for y in range(0, n) for x in range(0, n)]


print(parcours_ligne(10))
