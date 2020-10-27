def pgcd(a, b):
	if b > 0:
		return pgcd(b, a % b)
	return a

def inverse(a, p):
	pass