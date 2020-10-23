def majoritaire(L):
	m, l, i = L[0], 0, 1
	while i < len(L):
		if l == 0:
			m = L[i]
			l = 1
		elif m == L[i]:
			l += 1
		l -= 1
		i += 1
	c = 0
	for e in L:
		if e == m:
			c += 1
	if c <= len(L) / 2:
		return False
	else: return m