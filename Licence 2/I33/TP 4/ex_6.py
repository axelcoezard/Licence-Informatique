def transpose(M):
    N = []
    for i in range(len(M[0])):
        L = []
        for j in range(len(M)):
            L.append(M[j][i])
        N.append(L)
    return N


print(transpose([[1, 2, 3], [4, 5, 6]]))
