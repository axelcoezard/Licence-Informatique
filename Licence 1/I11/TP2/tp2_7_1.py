value = int(input("Entrer un entier: "))
sqrt_value = int(value ** .5)

dividers_sum = 1

for i in range(2, sqrt_value + 1):
    if value % i == 0:
        dividers_sum += i + value // i

if dividers_sum == value:
    print(value, "est un nombre parfait")
else:
    print(value, "n'est pas un nombre parfait")
