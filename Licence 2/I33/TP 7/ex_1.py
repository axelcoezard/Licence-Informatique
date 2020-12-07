def det(A):
    if len(A) == 2:
        return A[0][0] * A[1][1] - A[0][1] * A[1][0]
    prout = 0
    for j in range(len(A)):
        mat = list(A)
        for i in range(len(A[0])):
            A[j].pop(i)
        print(mat)
    return prout


det([[16, 12, 12], [8, 7, 6], [16, 13, 8]])
