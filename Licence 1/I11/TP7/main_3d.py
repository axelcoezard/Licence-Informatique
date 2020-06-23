from geometrie_3d import *
from math import pi
from time import sleep

c = (300, 300)
carre = [
    (300, 300, 300),
    (400, 300, 300),
    (400, 300, 400),
    (300, 300, 400),
    (300, 400, 300),
    (400, 400, 300),
    (400, 400, 400),
    (300, 400, 400)
]
cone = [(230,230,50),(300,300,0),(200,300,0),(200,200,0),(300,200,0)]

init_window("Rotation 3D", 500, 500)
while True:
    cone = rotation_3d(cone, c, 0, pi/8, 0)
    # carre = rotation_3d(carre, c, pi/32, pi/16, pi/8)
    # dessine_carre_3d(carre)
    dessine_cone_3d(cone)
    refresh()
    sleep(0.5)
    clear_screen()
main_loop()
