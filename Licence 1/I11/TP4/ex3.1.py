liste = [-1, -2, -3]

max = liste[0]
for number in liste[1:]:
    if number > max:
        max = number

print("Maximum:", max)
