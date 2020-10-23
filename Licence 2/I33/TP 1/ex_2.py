def somme_ind_pair(L):
	somme = 0
	i = 0
	while i < len(L):
		somme += L[i]
		i += 2
	return somme

print(somme_ind_pair([3,2,5,7,4,1]))