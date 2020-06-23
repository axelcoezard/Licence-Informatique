liste = [1, 34, 8, 9, 72, -5, 2]

max_1, index_1 = liste[0], 0
max_2, index_2 = liste[], 0
tmp = 0
if max_1 < max_2:
    tmp = max_1
    max_1 = max_2
    max_2 = tmp

i = 0
while i < len(liste):
    if liste[i] > max_1:
        max_2 = max_1
        max_1, index_1 = liste[i], i
    elif liste[i] > max_2 and liste[i] != max_1:
        max_2, index_2 = liste[i], i
    i += 1

print("Premier maximum:", max_1, "| Index:", index_1)
print("Deuxième maximum:", max_2, "| Index:", index_2)
