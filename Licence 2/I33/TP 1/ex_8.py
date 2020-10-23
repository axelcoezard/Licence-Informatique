def tri(L):
	pointer = 0
	while pointer < len(L):
		minimum = L[pointer]
		minimum_i = pointer

		index = pointer
		while index < len(L):
			if (L[index] < minimum):
				minimum = L[index]
				minimum_i = index
			index += 1
		L[pointer], L[minimum_i] = minimum, L[pointer]
		pointer += 1
	return L

print(tri([8, -1, 2, 5, 3, -2]))