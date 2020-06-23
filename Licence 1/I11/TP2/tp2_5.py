next = True
sum_pairs = 0
sum_impairs = 0

while next:
    value = int(input("Entrer un nombre entier: "))

    if value == 0: next = False
    else:
        if value % 2 == 0: sum_pairs += value
        else: sum_impairs += value

print("Sommes des pairs:", sum_pairs)
print("Sommes des impairs:", sum_impairs)
