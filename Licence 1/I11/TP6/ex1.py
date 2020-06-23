from pocketgl import *

init_window ("premiers pas", 500, 500)
for index, y in enumerate(range(50)):
    color = int(index / 50 * 255)
    current_color(color, color, color)
    box (0, y * 10, 500, y * 10 + 10)
main_loop ()
