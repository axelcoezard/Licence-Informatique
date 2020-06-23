#
# Fichier à compléter: deplacement.py
#
# Chaque fonction doit renvoyer la liste des indices (col,lig) des
# cases sur lesquelles la pièce en question peut aller.
#
from math import *

def cases_fou(col,lig):
    """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer un fou positionné sur la case (col, lig)

    Ex: fou en (2,3)
    - - - - - - - - - -
    |           x     |
    | x       x       |
    |   x   x         |
    |     F           |
    |   x   x         |
    | x       x       |
    |           x     |
    |             x   |
    - - - - - - - - - -

    """
    diag_1 = [(x, y) for x in range(0, 8) for y in range(0, 8) if x - col == y - lig and not x == col]
    diag_2 = [(x, y) for x in range(0, 8) for y in range(0, 8) if x - col == lig - y and not x == col]
    return diag_1 + diag_2

def cases_tour(col,lig):
    """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer une tour positionnée sur la case (col, lig)

    Ex: tour en (5,3)
    - - - - - - - - - -
    |           x     |
    |           x     |
    |           x     |
    | x x x x x T x x |
    |           x     |
    |           x     |
    |           x     |
    |           x     |
    - - - - - - - - - -

    """
    ligne = [(col, x) for x in range(0, 8) if not x == lig]
    colonne = [(y, lig) for y in range(0, 8) if not y == col]

    return ligne + colonne

def cases_reine(col,lig):
    """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer un fou positionnée sur la case (col, lig)

    Ex: dame en (6,1)
    - - - - - - - - - -
    |           x x x |
    | x x x x x x D x |
    |           x x x |
    |         x   x   |
    |       x     x   |
    |     x       x   |
    |   x         x   |
    | x           x   |
    - - - - - - - - - -

    """
    ligne = [(col, x) for x in range(0, 8) if not x == lig]
    colonne = [(y, lig) for y in range(0, 8) if not y == col]

    diag_1 = [(x, y) for x in range(0, 8) for y in range(0, 8) if x - col == y - lig and not x == col]
    diag_2 = [(x, y) for x in range(0, 8) for y in range(0, 8) if x - col == lig - y and not x == col]

    return ligne + colonne + diag_1 + diag_2

def cases_roi(col,lig):
   """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer un roi positionné sur la case (col, lig)

    Ex: Roi en (4,5)
    - - - - - - - - - -
    |                 |
    |                 |
    |                 |
    |                 |
    |      x x x      |
    |      x R x      |
    |      x x x      |
    |                 |
    - - - - - - - - - -

   """
   cases = []

   r1 = range(col - 1, col + 2)
   r2 = range(lig - 1, lig + 2)

   return [(x, y) for x in r1 for y in r2 if (x >= 0 and x <= 7) and (y >= 0 and y <= 7) and not (x, y) == (col, lig)]

def cases_cavalier(col,lig):
    """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer un fou positionné sur la case (col, lig)

    Ex: cavalier en (3,3)
    - - - - - - - - - -
    |                 |
    |     x   x       |
    |   x       x     |
    |       C         |
    |   x       x     |
    |     x   x       |
    |                 |
    |                 |
    - - - - - - - - - -

    """

    cases = []
    for x in range(col - 2, col + 3):
        for y in range(lig - 2, lig + 3):
            d = sqrt((col - x) ** 2 + (lig - y) ** 2)
            if not (x, y) == (col, lig) and 2 < d <= 2.5:
                if x >= 0 and x <= 7 and y >= 0 and y <= 7:
                    cases += [(x, y)]

    return cases

def cases_pion(col,lig):
    """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer un fou positionné sur la case (col, lig)

    Ex: pions en (1,6) et (5,3)
    - - - - - - - - - -
    |                 |
    |                 |
    |           x     |
    |           P     |
    |   x             |
    |   x             |
    |   P             |
    |                 |
    - - - - - - - - - -

    """
    if lig >= 6: return [
        (col, lig - 1),
        (col, lig - 2)
    ]
    else: return [(col, lig - 1)]
