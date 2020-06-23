"""
    Module geometrie_2d
    créé par Axel Coezard
    le 10 / 12 / 19
"""

from math import *
from vecteur import *
from pocketgl import *

def mat_rotation_2d(theta):
    col1 = (cos(theta), -sin(theta))
    col2 = (sin(theta), cos(theta))
    return [col1, col2]

def rotation_point_2d(p, c, theta):
    diff = diff_vect(p, c)
    rot = mat_rotation_2d(theta)
    return somme_vect(c, prod_mat_vec(diff, rot))

def dessine_polygone_2d(pol):
    p1 = pol[len(pol)-1]
    for p2 in pol:
        current_color("black")
        line(p1[0], p1[1], p2[0], p2[1])
        p1 = p2

def rotation_polygone_2d(p, c, theta):
    return [rotation_point_2d(s, c, theta) for s in p]
