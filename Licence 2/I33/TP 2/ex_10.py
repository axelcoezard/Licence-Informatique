import math

def pow(x, y, n):
	return math.pow(x, y) % n

def decompose(n):
	D, i = set(), 2
	while n != 1:
		if n % i == 0:
			n //= i 
			D.add(i)
		else: i += 1 
	return list(sorted(D))

def generateurs(p):
	T, K = [], decompose(p - 1)
	for g in range(p):
		i = 0
		for k in K:
			if pow(g, int((p-1) / k), p) != 1:
				i += 1
		if i == len(K):
			T.append(g)
	return T

print(generateurs(6))