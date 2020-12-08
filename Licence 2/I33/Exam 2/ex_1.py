log_table = []
alpha_table = []


def multiplie(x, y, P):
    if (x == 0) or (y == 0):
        return 0
    m_ = len(bin(P)) - 3
    i = log_table[x]
    j = log_table[y]
    return alpha_table[(i+j) % ((1 << m_)-1)]
