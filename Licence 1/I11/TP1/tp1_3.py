from math import *

r = float(input("Rayon du cercle : "))
p = 2 * pi * r
a = pi * (r ** 2)

print("Perimetre = " + str(p) + ", Aire = " + str(a) + "\n")

a = float(input("Longueur du premier cote : "))
b = float(input("Longueur du deuxieme cote : "))
c = float(input("Longueur du troisieme cote : "))

s = 0.5 * (a + b + c)
A = sqrt(s * (s - a) * (s - b) * (s - c))

print("Aire = " + str(A)  + "\n")

tc = float(input("Temperature en degre Celsius : "))
tf = tc * 9 / 5 + 32

print("Temperature en degre fahrenheit = " + str(tf) + "\n")

s = float(input("Nombre de secondes : "))
h = s / 3600
m = s % 3600 / 60
s = m * 60 - int(m) * 60

print(
    "Heures / minutes / secondes : "
    + str(int(h)) + "h"
    + str(int(m)) + "m"
    + str(int(s)) + "s"
)
