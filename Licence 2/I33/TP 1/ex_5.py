def minimum_posi(L): 
	M = [0]
	minimum = L[0]
	i = 1
	while i < len(L):
		if L[i] < minimum:
			minimum = L[i]
			M = [i]
		elif L[i] == minimum:
			M.append(i)
		i += 1
	return M

print(minimum_posi([3,2,5,7,2]))