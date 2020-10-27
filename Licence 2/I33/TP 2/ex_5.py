def decompose(n, b):
	T = []
	while n != 0:
		T += [n % b]
		n = n // b
	return T[::-1]

print(decompose(30, 5))