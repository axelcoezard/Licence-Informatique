value = str(input("Entrer un entier: "))
tmp = value

while len(tmp) > 1:
    sum = 0
    sign = 1
    for i in range(0, len(tmp)):
        sum += sign * int(tmp[i])
        sign *= -1
    tmp = str(sum)

if int(tmp) == 0: print(value, "est divisible par 11")
else: print(value, "n'est pas divisible par 11")
