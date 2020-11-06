def decompose(n):
	T = []
	while n != 0:
		T += [n % 2]
		n = n // 2
	return T[::-1]