def matmat(A, B):
    if len(A[0]) != len(B):
        return False
    matrix = []
    for i in range(len(A)):
        ligne = []
        for j in range(len(B[0])):
            e = 0
            for k in range(len(A[0])):
                e += A[i][k] * B[k][j]
            ligne.append(e)
        matrix.append(ligne)
    return matrix


print(matmat([[1, 1, 2], [1, 0, 2]], [
      [1, 2, 0, 1], [1, 1, 1, 0], [0, 2, 2, 1]]))
