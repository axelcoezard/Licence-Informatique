liste = [-1, -34, -8, 2, -2, -5]

max_1 = liste[0]
max_2 = liste[1]
tmp = 0
if max_1 < max_2:
    tmp = max_1
    max_1 = max_2
    max_2 = tmp

for number in liste[1:]:
    if number > max_1:
        max_2, max_1 = max_1, number
    elif number > max_2 and number != max_1:
        max_2 = number

print("Premier maximum:", max_1)
print("Deuxième maximum:", max_2)
