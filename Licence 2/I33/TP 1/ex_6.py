def som_div_propres(n):
	if n <= 1: return 0
	somme = 1
	i = 2
	while i < n ** .5:
		if n % i == 0:
			somme += i
			somme += n // i
		i += 1
	if n ** .5 % n == 0:
			somme += n ** .5
	return somme

print(som_div_propres(40)) 