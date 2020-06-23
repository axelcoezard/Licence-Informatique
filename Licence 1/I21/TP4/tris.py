from random import randint
import matplotlib.pyplot as plt

def rand_table(n, a, b):
    return [randint(a, b) for i in range(n)]


def tri_insertion(l):
    tri = [i for i in l]
    index = 1
    count = 0
    while index < len(tri):
        j = index - 1
        k = tri[index]
        while j >= 0 and k < tri[j]:
            tri[j + 1] = tri[j]
            j -= 1
            count += 1
        tri[j + 1] = k
        index += 1
    return count


def tri_bulle(T):
    tri = [i for i in T]
    i = len(tri) - 1
    count = 0
    swap = True
    while swap and i > 0:
        j = 0
        swap2 = False
        while not swap2 and j < i - 1:
            if tri[j] > tri[j+1]:
                temp = tri[j+1]
                tri[j+1] = tri[j]
                tri[j] = temp
                swap2 = True
            count += 1
            j += 1
        swap = swap2
        i -= 1
    return count, tri

print(tri_bulle([2, 0, 2, 2]))


def tri_selection(l):
    tri = [i for i in l]
    count = 0
    for i in range(len(tri)):
        k, imin = i, i
        while k < len(tri):
            if tri[imin] > tri[k]:
                imin = k
            k += 1
        tri[imin], tri[i] = tri[i], tri[imin]
        count += 1
    return count


def compare_tris(T):
    return (
        tri_insertion(T),
        tri_bulle(T),
        tri_selection(T)
    )

# moyennes_c1 = [0] * 10
# moyennes_c2 = [0] * 10
# moyennes_c3 = [0] * 10
# for i in range(1, 11):
#     j = i * 50
#     c1, c2, c3 = 0, 0, 0
#     for k in range(100):
#         T = rand_table(j, 1, j)
#         cc1, cc2, cc3 = compare_tris(T)
#         moyennes_c1[i - 1] = cc1
#         moyennes_c2[i - 1] = cc2
#         moyennes_c3[i - 1] = cc3
#     moyennes_c1[i - 1] /= 100
#     moyennes_c2[i - 1] /= 100
#     moyennes_c3[i - 1] /= 100
#
#     print(i / 10 * 100, "%")
#
# I = [i * 50 for i in range(1, 11)]
#
# plt.subplot(221)
# plt.title("Insertion")
# plt.plot(I, moyennes_c1)
# plt.subplot(222)
# plt.title("Bulle")
# plt.plot(I, moyennes_c2)
# plt.subplot(223)
# plt.title("Selection")
# plt.plot(I, moyennes_c3)
# plt.show()
