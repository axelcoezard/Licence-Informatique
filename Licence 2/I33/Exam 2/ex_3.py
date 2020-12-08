def resolution(A, b):
    x = [b[0] / A[0][0]]
    for i in range(1, len(A)):
        somme = b[i]
        for j in range(i):
            somme += A[i][j] * x[j]
        x.append(somme / A[i][i])
    return x


print(resolution([[2, 1, -1], [0, 2, 2], [0, 0, 1]], [1, 2, 3]))
