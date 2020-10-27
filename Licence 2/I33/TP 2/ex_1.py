def pgcd(a, b):
	while b > 0:
		a, b = b, a % b
	return a

print(pgcd(5, 0))
print(pgcd(5, 36))