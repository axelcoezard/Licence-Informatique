def decompose(n):
	D, i = set(), 2
	while n != 1:
		if n % i == 0:
			n //= i 
			D.add(i)
		else: i += 1 
	return list(sorted(D))

print(decompose(99999876400))
