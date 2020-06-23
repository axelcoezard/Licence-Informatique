semaine = [
    "lundi",
    "mardi",
    "mercredi",
    "jeudi",
    "vendredi",
    "samedi",
    "dimanche"
]

calendOct18 = []

for i in range(1, 32):
    calendOct18 += [semaine[i % 7 - 1] + " " + str(i) + " octobre"]

print(calendOct18)
