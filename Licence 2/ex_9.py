def tri_bulle(L):
	pointer = 0
	while pointer < len(L):
		left = 0
		right = 1
		while right < len(L) - pointer:
			if L[right] < L[left]:
				L[left], L[right] = L[right], L[left]
			left += 1
			right += 1
		pointer += 1
	return L

print(tri_bulle([8, -1, 2, 5, 3, -2]))