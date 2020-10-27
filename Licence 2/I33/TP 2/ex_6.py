def valeur(L,b):
	p, somme = 1, 0
	for i in range(len(L)):
		somme += L[::-1][i] * p
		p *= b
	return somme
