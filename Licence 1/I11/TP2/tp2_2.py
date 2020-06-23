a = int(input("a= "))
b = int(input("b= "))
c = int(input("c= "))

if a == 0:
    if b != 0:
        print("La solution est", -c / b)
    else:
        if c == 0:
            print("INF")
        else:
            print("Aucune solution")
else:
    delta = (b ** 2) - 4 * a * c

    if delta > 0:
        print(
            "Les deux solutions sont ",
            (- b - (delta ** 0.5)) / (2 * a),
            "et",
            (- b + (delta ** 0.5)) / (2 * a),
        )
    elif delta == 0:
        print("La solution est", -b / (2 * a))
    else:
        print("Pas de solutions reelles")
