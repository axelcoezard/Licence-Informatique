from pocketgl import *
from math import *

width = 700
height = 500
middle_x = 350
middle_y = 250

init_window ("Fonctions", width, height)

"""

    Affichage du quadrillage

"""
current_color("grey")

for x in range(-3, 4):
    box(middle_x + x * 100, 0, middle_x + x * 100, height)

for y in range(-2, 3):
    box(0, middle_y + y * 100, width, middle_y + y * 100)

"""

    Affichage du repère orthonormé

"""
current_color("green")
box(width / 2, 0, width / 2, height)
box(0, height / 2, width, height / 2)

"""

    Affichage des rectangle d'air
    Calcul de l'intégrale de la courbe

"""
# somme = 0
# current_color("blue")
# for x in range(-3, 4):
#     xx = middle_x + x * 100
#     yy = middle_y + cos(x + 1) * 100
#     box(xx, middle_y, xx + 100, yy)
#     air = cos(x + 1)
#     somme += air if yy >= middle_y else -air
# print("Intégrale:", somme)

"""

    Affichage de la courbe

"""
last_x = 0
last_y = middle_y + cos(-3) * 100
current_color("red")
for x in range(-300, 301):
    xx = middle_x + x
    yy = middle_y + cos(x / 100) * 100
    line(last_x, last_y, xx, yy)
    last_x, last_y = xx, yy

"""

    Affichage des rectangle d'air
    Calcul de l'intégrale de la courbe
    (avec un pas)

"""
def integrale_cos(pas):
    somme = 0
    current_color("blue")
    x = -3
    while x < 3:
        # affichage
        xx = middle_x + x * 100
        yy = middle_y + cos(x + 1) * 100
        box(xx, middle_y, xx + 100, yy)
        # air
        air = pas * cos(x + 1)
        somme += air if yy >= middle_y else -air
        x += pas
    return somme

"""

    Affichage dynamique

"""
valeur = 3.847490569099081
pas = 1/2
puissance = 1
c_pas = pas ** puissance
while integrale_cos(c_pas) - valeur > 10 ** -4:
    puissance += 1
    c_pas = pas ** puissance
    print("Calcul...", integrale_cos(c_pas), valeur)
    refresh()
print("Plus grande valeur de pas:", pas, "**", puissance)


main_loop()
