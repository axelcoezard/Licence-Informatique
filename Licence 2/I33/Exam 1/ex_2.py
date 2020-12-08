log_table = []
alpha_table = []


def inverse(x, P):
    return alpha_table[((1 << (len(bin(P)) - 3)) - 1) - log_table[x]]
