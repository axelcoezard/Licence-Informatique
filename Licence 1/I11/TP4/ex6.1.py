u = (1.0, 2.0, -1.0, 0.5)
v = (2.0, 5.0, 9.5, -2.0)

somme = ()
i = 0
while i < len(u):
    somme += (u[i] + v[i],)
    i += 1

print(somme)
