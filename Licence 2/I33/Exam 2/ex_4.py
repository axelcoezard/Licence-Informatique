def elementmedian(M):
    l_M = len(M)
    n_M = sorted(M[i][j] for i in range(l_M) for j in range(l_M))
    l_M = int(len(n_M) / 2)
    return n_M[l_M]


print(elementmedian([[2, 0, 9, 8, 8], [8, 0, 8, 6, 1], [
      4, 3, 3, 2, 7], [0, 0, 0, 5, 2], [3, 5, 7, 6, 4]]))
