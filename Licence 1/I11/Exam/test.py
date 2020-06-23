def fusion(l1, l2):
    tmp = l1 + l2
    l3 = tmp

    op = 0
    i = 0
    while i < len(tmp):
        a = tmp[i]
        if i + 1 >= len(tmp):
            break
        j = i + 1
        b = tmp[j]

        if b < a and i < j:
            l3[i], l3[j] = b, a
            i = 0
        i += 1

    return l3

print(fusion([1,3,6,7],[2,3,9]))
