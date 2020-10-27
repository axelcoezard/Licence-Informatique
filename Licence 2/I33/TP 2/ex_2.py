def euclide_e(a, n):
	u, v = 1, 0 
	u1, v1 = 0, 1 
	 
	while n > 0:
		u1_t = u - a // n * u1 
		v1_t = v - a // n * v1 
		u, v = u1, v1
		u1, v1 = u1_t, v1_t
		a, n = n, a - a // n * n;
	return  [u, v, a]

print(euclide_e(39, 5))
