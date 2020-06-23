def retourner(T, i):
    T[:i] = T[:i]
    T[i:] = T[i:][::-1]

T = [1, 3, 0, 2]
retourner(T,1)
print(T)

def tri_pancake(T):
    tri = [i for i in T]
    indexes = []

    for i in range(len(tri)):
        k, imax = i, i
        while k < len(tri):
            if tri[imax] < tri[k]:
                imax = k
            k += 1

        if not imax == len(T) - 1:
            retourner(tri, imax)
            indexes += [imax]
        retourner(tri, i)
        indexes += [i]

    return indexes
