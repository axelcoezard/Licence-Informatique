def inverse(a, p):
	u, v = 1, 0
	u1, v1 = 0, 1
	p1 = p
	while a != 0:
		u2 = u - (p1 // a) * u1
		v2 = v - (p1 // a) * v1
		u, v = u1, v1
		u1, v1 = u2, v2
		p1, a = a, p1 % a
	return v%p