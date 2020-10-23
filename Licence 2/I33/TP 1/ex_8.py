def tri(L):
	i = 0
	while (i < len(L)):
		min = L[i]
		j = i
		while j < len(L):
			if L[j] < min:
				min = L[j]
			j += 1
		j -= 1
		L[i], L[j] = L[j], L[i]
		i += 1
	return L

print(tri([5, 6, 8,9, 7, -1, 3]))