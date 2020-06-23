from random import *
from math import *
from pocketgl import *

N = int(input("Difficulté: "))

size = int(sqrt(N))

init_window ("Pi graph", size, size)

n = 0
for i in range(N):
    x, y = random(), random()
    xx = (x - 0.5) ** 2
    yy = (y - 0.5) ** 2
    if sqrt(xx + yy) <= 0.5:
        current_color("green")
        n += 1
        print("PI:", 4 * n / N)
    else: current_color("red")
    point(x * size, y * size)
    refresh()

main_loop()
