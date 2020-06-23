from geometrie_2d import *
from math import pi
from time import sleep

theta = pi/32
c = (250, 250)
p = [
    (300, 300),
    (200, 300),
    (200, 200),
    (300, 200)
]

init_window("Rotation 2D", 500, 500)
while True:
    p = rotation_polygone_2d(p, c, theta)
    dessine_polygone_2d(p)
    refresh()
    sleep(0.05)
    clear_screen()
main_loop()
