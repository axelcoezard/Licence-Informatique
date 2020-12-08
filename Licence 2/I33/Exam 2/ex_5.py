def det(A):
    signe, d, p = 1, 1, 1
    for j in range(len(A)-1):
        k = j
        while k < len(A) and A[k][j] == 0:
            k = k + 1
        if k == len(A):
            return 0
        if (k != j):
            A[k], A[j] = A[j], A[k]
            signe = -signe
        d = d * A[j][j]
        for k in range(j+1, len(A)):
            p, s = p * A[j][j], A[k][j]
            for c in range(0, len(A)):
                A[k][c] = A[k][c]*A[j][j]-A[j][c]*s
    d = d * A[len(A)-1][len(A)-1]*signe
    if abs(d) == 0:
        d = 0
    return d / p % 26
