semaine = [
    "lundi",
    "mardi",
    "mercredi",
    "jeudi",
    "vendredi",
    "samedi",
    "dimanche"
]

calendNov18 = []

for i in range(1, 31):
    calendNov18 += [semaine[i % 7 - 5] + " " + str(i) + " novembre"]

print(calendNov18)
