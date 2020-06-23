from random import *
from math import *
from pocketgl import *

faces = 6
resultats = {}
maximum = 0
for i in range(10000):
    r1 = randrange(1, faces + 1)
    r2 = randrange(1, faces + 1)
    r_max = max(r1, r2)
    r_min = min(r1, r2)
    r = str(r_min) + ":" + str(r_max)
    if r in resultats:
        resultats[r] += 1
        if resultats[r] > maximum:
            maximum = resultats[r]
    else: resultats[r] = 1

print("resultats:", resultats)

init_window ("Lancés de dés", 210, 100)
for index, name in enumerate(resultats):
    current_color(0, 0, int(index / 21 * 254 + 1))
    box (index * 10, 0, index * 10 + 10,
        int(resultats[name] / maximum * 100))
main_loop ()
