def gen_circulante2(k, t):
    L = [k]
    for i in range(1, t):
        a = L[i-1] & 1
        b = a << (t - 1)
        L.append((L[i-1] >> 1) ^ b)
    return L
