log_table = []
alpha_table = []


def multiplie(x, y, P):
    if x == 0 or y == 0:
        return 0
    P_deg = len(bin(P)) - 3
    i, j = log_table[x], log_table[y]
    return alpha_table[(i + j) % ((1 << P_deg)-1)]
