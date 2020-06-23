"""
    Module geometrie_2d
    créé par Axel Coezard
    le 10 / 12 / 19
"""

from math import *
from vecteur import *
from pocketgl import *
from geometrie_2d import *

def mat_rotation_3dx(theta):
    col1 = (1, 0, 0)
    col2 = (0, cos(theta), sin(theta))
    col3 = (0, -sin(theta), cos(theta))
    return [col1, col2, col3]

def mat_rotation_3dy(theta):
    col1 = (cos(theta), 0, sin(theta))
    col2 = (0, 1, 0)
    col3 = (-sin(theta), 0, cos(theta))
    return [col1, col2, col3]

def mat_rotation_3dz(theta):
    col1 = (cos(theta), sin(theta), 0)
    col2 = (-sin(theta), cos(theta), 0)
    col3 = (0, 0, 1)
    return [col1, col2, col3]

def rotation_point_3dx(p, c, theta):
    diff = diff_vect(p, c)
    rot = mat_rotation_3dx(theta)
    return somme_vect(c, prod_mat_vec(diff, rot))

def rotation_point_3dy(p, c, theta):
    diff = diff_vect(p, c)
    rot = mat_rotation_3dy(theta)
    return somme_vect(c, prod_mat_vec(diff, rot))

def rotation_point_3dz(p, c, theta):
    diff = diff_vect(p, c)
    rot = mat_rotation_3dz(theta)
    return somme_vect(c, prod_mat_vec(diff, rot))

def dessine_cone_3d(cone):
    sommet = cone[0]
    base = cone[1:]

    for p in base:
        line(sommet[0], sommet[1], p[0], p[1])

    dessine_polygone_2d(base)

def dessine_carre_3d(carre):
    base1 = carre[:4]
    base2 = carre[4:]

    dessine_polygone_2d(base1)
    dessine_polygone_2d(base2)

    for p1, p2 in zip(base1, base2):
        line(p1[0], p1[1], p2[0], p2[1])


def rotation_3d(obj, c, alpha, beta, gamma):
    n_obj = []
    for point in obj:
        point = rotation_point_3dx(point, c, alpha)
        point = rotation_point_3dy(point, c, beta)
        n_obj += [rotation_point_3dz(point, c, gamma)]

    return n_obj
