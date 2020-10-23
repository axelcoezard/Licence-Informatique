def minimum2(L):
	min_1 = L[0]
	min_2 = L[1]
	if min_1 < min_2:
			min_1, min_2 = min_2, min_1
	i = 0
	while i < len(L):
			if L[i] < min_1:
					min_2, min_1 = min_1, L[i]
			elif L[i] < min_2 and L[i] > min_1:
					min_2 = L[i]
			i += 1
	return min_2

print(minimum2([3,2,5,7,2]))
