def pgcd(a, b):
	if b > 0:
		return pgcd(b, a % b)
	return a

def generateurs(n):
    return [i for i in range(n) if pgcd(i, n) == 1]

print(generateurs(6))
