def minimum(L):
	minimum = L[0]
	i = 1
	while i < len(L):
		if L[i] < minimum:
			minimum = L[i]
		i += 1
	return minimum

print(minimum([3,2,5,7,2]))
