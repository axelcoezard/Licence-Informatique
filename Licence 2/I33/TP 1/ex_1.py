def somme_pair(L):
	somme = 0
	for i in L:
		if i % 2 == 0: somme += i
	return somme

print(somme_pair([3,2,5,7,4,1]))