#!/usr/bin/env python3
# coding: utf-8

#--------------------------------------------------------------
# PocketGL - Pocket Graphics Library
# Version 1.0 (19 mai 2016)
# module graphique minimaliste
# Christian NGUYEN - nguyen@univ-tln.fr
# http://nguyen.univ-tln.fr
#--------------------------------------------------------------

#--------------------------------------------------------------
# A destination des etudiants de L1 informatique a l'UTLN.
# Imperatifs :
# - Python 3.x
# - simple d'usage
# - pas d'animation
# - pas d'evenement
#--------------------------------------------------------------

#--------------------------------------------------------------
# modules externes
module_image = True

# prise en compte de la version de Python
import sys
if sys.version_info >= (3,):
    from tkinter import *
    # pour les images avec Pillow
    try:
        from PIL import Image
        from PIL import ImageTk
    except:
        module_image = False
else:
    from Tkinter import *
    # pour les images avec PIL
    try:
        import Image
        import ImageTk
    except:
        module_image = False

#--------------------------------------------------------------
# variables globales

__root = 0  # id fenetre principale
__canv = 0  # id zone graphique
__la, __ha = 0, 0  # hauteur, largeur de root
__ccol = "black"  # couleur courante
__lim = []  # liste des images
__limtk = []  # liste des images affichees dans le canvas

#--------------------------------------------------------------
# fonctions privees
#--------------------------------------------------------------

#--------------------------------------------------------------
# fonction privee d'affichage d'une erreur


def __erreur(perr):
    if sys.version_info >= (3,):
        # le parser detecte une erreur de syntaxe pour les versions < 3
        # solution : evaluation retardee
        eval("print(perr, file=sys.stderr)")
    else:
        print >> sys.stderr, perr

#--------------------------------------------------------------
# fonctions publiques
#--------------------------------------------------------------

#--------------------------------------------------------------
# creation et affichage de la fenetre graphique
# ATTENTION : premiere instruction du programme


def init_window(pnom='', pla=None, pha=None, color='white'):
    """ATTENTION : premiere instruction du programme
    creation et affichage de la fenetre graphique
    de nom pnom, de largeur pla et de hauteur pha
    """
    global __root  # fenetre principale
    global __canv  # zone graphique
    global __la, __ha  # hauteur et largeur de la fenetre

    __root = Tk()
    if pla == None and pha == None:
        # ATTENTION : ne prend pas en compte les barres du WM (!)
        __la, __ha = __root.winfo_screenwidth(), __root.winfo_screenheight()
    else:
        __la, __ha = pla, pha
    __root.title(pnom)
    __root.resizable(width=False, height=False)
    # zone graphique
    __canv = Canvas(width=__la, height=__ha, bg=color)
    __canv.pack()

# information sur l'ecran


def get_screen_width():
    return __root.winfo_screenwidth()


def get_screen_height():
    return __root.winfo_screenheight()

#--------------------------------------------------------------
# boucle d'attente des evenements
# ATTENTION : derniere instruction du programme


def main_loop():
    """ATTENTION : derniere instruction du programme
    boucle d'attente des evenements
    """
    __root.mainloop()

#--------------------------------------------------------------
# efface l'ecran de travail


def clear_screen():
    "efface l'ecran de travail"
    __canv.delete('all')

#--------------------------------------------------------------
# polymorphisme parametrique : couleur definie
# soit en hexadecimal avec r, v, b dans [O, 255] (8 bits / composante)
# soit par son nom (white, black, red, green, blue, cyan, yellow, magenta, ...)


def current_color(*args):
    """Definition de la couleur courante
       - soit en r, v, b dans [O, 255]
       - soit par son nom (white, black, red, green, blue, ...)
    """
    global __ccol

    # initialisation a noir en cas d'erreur
    __ccol = "black"
    # 1 parametre : le nom de la couleur
    if len(args) == 1:
        if isinstance(args[0], str):
            __ccol = args[0]
        else:
            __erreur("[current_color] le paramètre n'est pas une chaine")
    # 3 parametres : code RVB sur [0, 255]
    elif len(args) == 3:
        if isinstance(args[0], int) and isinstance(args[1], int) and isinstance(args[2], int):
            tc = [0, 0, 0]
            tc[0], tc[1], tc[2] = int(args[0]), int(args[1]), int(args[2])
            if -1 < tc[0] < 256 and -1 < tc[1] < 256 and -1 < tc[2] < 256:
                # concatenation avec suppression du prefixe 0x et
                # ajout d'un zero pour les nombres inf. a 16
                __ccol = '#'
                for i in range(3):
                    if tc[i] < 16:
                        __ccol += '0' + hex(tc[i])[2:]
                    else:
                        __ccol += hex(tc[i])[2:]
            else:
                __erreur("[current_color] composantes RVB pas entre 0 et 255")
        else:
            __erreur("[current_color] l'un des paramètres n'est pas un entier")
    # erreur : nombre de parametres incorrect
    else:
        __erreur("[current_color] nombre de paramètres incorrect (1 ou 3)")

#--------------------------------------------------------------
# force la mise a jour


def refresh():
    "refraichit l'ecran (force le dessin)"
    # ATTENTION : update_idletasks prend en compte les animations en cours
    # ce qui n'est pas le cas du simple update
    __canv.update_idletasks()
    #__canv.update()

#--------------------------------------------------------------
# DRAWING
#--------------------------------------------------------------

#
# affichage d'un point


def point(px, py):
    """affichage d'un point de coordonnees (px, py) dans la couleur courante
    retour de l'identificateur unique de l'objet cree
    """
    if px < 0 or px > __la or py < 0 or py > __ha:
        __erreur("[point] coordonnees hors fenetre")
    # changement de repere
    py = __ha - py
    id = __canv.create_line(px, py, px + 1, py + 1, fill=__ccol)
    # retour de l'id de l'obj du canvas (pour translation, suppression, ...)
    return id

# affichage d'un segment


def line(px1, py1, px2, py2, pep=1):
    """affichage d'un segment de sommets (px1, py1) et (px2, py2),
    d'epaisseur pep, dans la couleur courante
    retour de l'identificateur unique de l'objet cree
    """
    # changement de repere
    py1, py2 = __ha - py1, __ha - py2
    id = __canv.create_line(px1, py1, px2, py2, fill=__ccol, width=pep)
    return id

# affichage d'un rectangle


def rectangle(px1, py1, px2, py2, pep=1):
    """affichage d'un rectangle dans la couleur courante
    defini par le sommet inf. gauche (px1, py1)
    et le sommet sup. droit (px2, py2) et d'epaisseur pep
    retour de l'identificateur unique de l'objet cree
    """
    # changement de repere
    py1, py2 = __ha - py1, __ha - py2
    id = __canv.create_rectangle(px1, py1, px2, py2, outline=__ccol, width=pep)
    return id

# affichage d'un rectangle plein


def box(px1, py1, px2, py2):
    """affichage d'un rectangle plein dans la couleur courante
    defini par le sommet inf. gauche (px1, py1)
    et le sommet sup. droit (px2, py2)
    retour de l'identificateur unique de l'objet cree
    """
    # changement de repere
    py1, py2 = __ha - py1, __ha - py2
    id = __canv.create_rectangle(px1, py1, px2, py2, fill=__ccol, width=0)
    return id

# affichage d'un cercle


def circle(px, py, pr, pep=1):
    """affichage d'un cercle de centre (px, py), de rayon pr et d'epaisseur pep
    retour de l'identificateur unique de l'objet cree
    """
    # changement de repere
    py = __ha - py
    id = __canv.create_oval(
        px - pr, py - pr, px + pr, py + pr, outline=__ccol, width=pep)
    return id

# affichage d'un disque


def disc(px, py, pr):
    """affichage d'un disque de centre (px, py) et de rayon pr
    retour de l'identificateur unique de l'objet cree
    """
    # changement de repere
    py = __ha - py
    id = __canv.create_oval(
        px - pr, py - pr, px + pr, py + pr, fill=__ccol, width=0)
    return id

# affichage d'un polygone


def polygon(*args):
    """affichage d'un polygone construit a partir d'une liste de coordonnees
    retour de l'identificateur unique de l'objet cree
    """
    # 1 parametre : une liste ou un tuple de coordonnees
    if len(args) == 1:
        if isinstance(args[0], list) or isinstance(args[0], tuple):
            # changement de repere
            nb = len(args[0])
            ll = [0 for i in range(nb)]
            for i in range(nb):
                if i % 2 != 0:
                    ll[i] = __ha - args[0][i]
                else:
                    ll[i] = args[0][i]
            id = __canv.create_polygon(ll, fill=__ccol)
        else:
            __erreur("[polygon] le parametre n'est pas une liste ou un tuple")
    # N parametres : une suite de coordonnees
    elif len(args) > 1:
        # changement de repere
        nb = len(args)
        ll = [0 for i in range(nb)]
        for i in range(nb):
            if i % 2 != 0:
                ll[i] = __ha - args[i]
            else:
                ll[i] = args[i]
        id = __canv.create_polygon(ll, fill=__ccol)
    else:
        __erreur("[polygon] parametre incorrect")
    return id

# affichage d'un texte


def text(px, py, pch):
    """affichage d'un texte pch a partir de la position (px, py) aligne a gauche
    retour de l'identificateur unique de l'objet cree
    """
    # changement de repere
    py = __ha - py
    id = __canv.create_text(px, py, text=pch, fill=__ccol, anchor='sw')
    return id

#--------------------------------------------------------------
# IMAGE
#--------------------------------------------------------------

# chargement d'un fichier image et affichage a la position (x, y)


def image(name, width=None, height=None, px=0, py=0):
    """
    retourne une image a placer, avec changement de taille si demande.
    ATTENTION : la reference a l'image doit etre *globale*.
    """
    global __lim, __limtk
    if module_image:
        im = Image.open(name)
        # changement de la taille de l'image si demande
        if width:
            im = im.resize((width, height), Image.ANTIALIAS)
            # im.thumbnail((width, height), Image.ANTIALIAS)
            # Joseph : resize marche pas mais thumbnail marche ...
            # Chris : resize marche mais renvoie une copie de l'image
        __lim.append(im)
        imp = ImageTk.PhotoImage(im)
        __limtk.append(imp)
        # changement de repere
        py = __ha - py
        __canv.create_image(px, py, image=__limtk[-1], anchor='sw')
    else:
        if sys.version_info >= (3,):
            __erreur("[image] module Pillow non charge")
        else:
            __erreur("[image] module PIL non charge")
        return None


#--------------------------------------------------------------
#
# test unitaire
# la condition permet que les lignes suivantes ne soient pas executees si
# le script est importe en tant que module

from math import sin, cos, pi

# variables propres au test unitaire


def __figures():
    # couleurs arc en ciel de Newton + cyan, black - indigo
    lcoul = ('red', 'orange', 'yellow',
             'green', 'cyan', 'blue', 'purple', 'black')
    # points
    current_color('red')
    for i in range(1, 200):
        point(randint(30, 130), randint(300, 400))
    # segments
    current_color('blue')
    for i in range(1, 10):
        line(randint(150, 250), randint(300, 400),
             randint(150, 250), randint(300, 400))
    # rectangles
    current_color('green')
    for i in range(1, 10):
        rectangle(randint(270, 370), randint(300, 400),
                  randint(270, 370), randint(300, 400), randint(1, 5))
    # cercles
    current_color('black')
    for i in range(1, 10):
        circle(randint(410, 470), randint(320, 380), randint(10, 30))
    # rectangles pleins
    for i in range(1, 10):
        current_color(lcoul[randint(0, 6)])
        box(randint(510, 610), randint(300, 400),
            randint(510, 610), randint(300, 400))
    # disques
    for i in range(1, 10):
        current_color(lcoul[randint(0, 6)])
        disc(randint(60, 100), randint(220, 260), randint(10, 30))
    # polygones
    current_color('black')
    polygon(150, 200, 250, 200, 200, 280)  # triangle
    angle = 90.0
    idt2 = polygon(150, 200, 250, 200, 200, 280)  # 2eme triangle a tourner
    ll1 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(5):
        ll1[i * 2] = 30 * cos(angle * pi / 180.0) + 200
        ll1[i * 2 + 1] = 30 * sin(angle * pi / 180.0) + 230
        angle += 72
    current_color('red')
    polygon(ll1)  # pentagone
    # texte
    mot1, mot2, mot3 = 'dans', 'tous les', 'sens'
    current_color('black')
    y = 260
    for i in range(4):
        text(270, y, mot1[i])
        y -= 20
    x, y = 290, 190
    for i in range(8):
        text(x, y, mot2[i])
        x, y = x + 7, y + 9
    text(320, 190, mot3)
    # image
    image("ferme.png", px=400, py=190)

#--------------------------------------------------------------
if __name__ == '__main__':
    from random import randint
    from time import sleep

    init_window("pgl : test unitaire", 800, 600)
    # mode "direct" (i.e image construite par programme)
    __figures()
    main_loop()
