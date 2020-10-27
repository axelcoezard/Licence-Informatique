def pgcd(a, b):
	if b > 0:
		return pgcd(b, a % b)
	return a

print(pgcd(5, 0))
print(pgcd(5, 36))