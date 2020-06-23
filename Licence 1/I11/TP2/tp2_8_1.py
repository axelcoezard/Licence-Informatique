value = int(input("Entrer un entier: "))
tmp = value

while tmp >= 10:
    sum = 0
    for i in range(0, len(str(tmp))):
        sum += int(str(tmp)[i])
    tmp = sum

if tmp == 0 or tmp == 3 or tmp == 6 or tmp == 9:
    print(value, "est divisible par 3")
else: print(value, "n'est pas divisible par 3")
