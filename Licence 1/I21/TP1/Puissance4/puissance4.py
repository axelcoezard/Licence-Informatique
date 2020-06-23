#############################################
# Jeu du Puissance 4                        #
# Cours d'algorithmique                     #
# Licence Informatique - 1ere année         #
# Université de Toulon                      #
#                                           #
# Version du 01/03/2019                     #
#############################################


def init_jeu():
    """Renvoie une grille de jeu 6x7 sous forme d'une
    liste de listes remplie de 0"""
    return [[0]*7 for i in range(6)]

def dessine_grille(grille):
    """Retourne sous forme de chaine de caracteres l'état de la grille de jeu
    ainsi que le numéro des colonnes:
       -O pour le joueur 1
       -X pour le joueur 2

    """
    g = ""
    g += "—————————————\n"
    for i in range(0, 6): g += "|" + str(i + 1)
    g += "|\n"
    g += "—————————————\n"

    for j in range(0, 7):
        for i in range(0, 6):
            if not grille[i][j] == 0:
                g += " " + grille[i][j]
            else: g += " -"
        g += "\n—————————————\n"
    return g

def coups_legaux(grille):
    """Renvoie la liste des colonnes dans lesquelles il est possible de
    jouer un jeton

    """
    coups = []
    for i in range(0, 6):
        if grille[i][0] == 0:
            coups += [str(i + 1)]

    return coups

def jouer_coup(joueur, coup, grille):
    """Ajoute un jeton pour le joueur <joueur> dans la colonne <coup> dans
    la grille et renvoie la ligne où celui-ci a été joué

    """

    i = 6
    while not grille[int(coup)][i] == 0 and i > 0:
        i -= 1

    grille[int(coup)][i] = "O" if joueur == 0 else "X"
    return grille


def gagnant_colonne(lig, col, grille):
    """Renvoie True si le coup joué (lig,col) forme une colonne de 4 jetons
    False sinon
    """
    return

def gagnant_ligne(lig, col, grille):
    """Renvoie True si le coup joué (lig,col) forme une ligne de 4 jetons
    False sinon
    """
    return

def gagnant_diagonale(lig, col, grille):
    """Renvoie True si le coup joué (lig,col) forme une diagonale de 4 jetons
    False sinon
    """
    return

def gagnant_antidiagonale(lig, col, grille):
    """Renvoie True si le coup joué (lig,col) forme une antidiagonale de 4 jetons
    False sinon
    """
    return

def gagner(lig, col, grille):
    """Renvoie True si le coup joué est un coup gagnant
    False sinon
    """
    return

def main():
    """Programme principal:
    A chaque itération de la boucle de jeu il faut:
      - afficher l'état du jeu
      - calculer les coups légaux
      - stopper la partie si la liste est vide
      - demander un coup legal au joueur actif
      - ajouter son jeton dans la grille
      - arreter la partie si le coup est gagnant
      - changer le joueur actif et recommencer

    """
    grille = init_jeu()
    active_player = 0

    while not coups_legaux(grille) == []:
        print(dessine_grille(grille))
        print("C'est le tour du joueur:", active_player)
        print("Coups légaux:", " ".join(coups_legaux(grille)))
        coup = int(input("Choissiez un coup légal parmis la liste ci-dessus:")) - 1
        if coup > 5: coup = 5
        if coup < 1: coup = 1

        grille = jouer_coup(active_player, coup, grille)

        active_player = 0 if active_player == 1 else 1

if __name__=='__main__':
    main()
