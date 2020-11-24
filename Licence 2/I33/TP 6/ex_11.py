def matvec(M, V):
    if len(M[0]) != len(V):
        return False
    matrix = []
    for i in range(len(M)):
        e = 0
        for k in range(len(M[0])):
            e += M[i][k] * V[k]
        matrix.append(e)
    return matrix


print(matvec([[2, 1, 2], [2, 1, 2], [2, 1, 0]], [1, 0, 2]))
