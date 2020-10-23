def majoritaire(L):
	i = 0
	n = len(L)
	continuer = True
	while i < n and continuer:
		count = 0
		for j in L:
			if j == L[i]:
				count += 1
		continuer = count <= n / 2
		i = i + 1
	if continuer: return False
	else: return L[i - 1]