def euler_phi(n):
	Zn = 0
	for i in range(n + 1):
		a, b = i, n
		while b > 0:
			a, b = b, a % b
		if a == 1:
			Zn += 1
	return Zn

print(euler_phi(5))