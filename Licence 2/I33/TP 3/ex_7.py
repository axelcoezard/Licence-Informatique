def is_irreducible(P, p):
    is_irr = 0
    for i in range(p):
        index, P_b = 0, 0
        while index < len(P) - 1:
            P_b += P[index]
            P_b *= i
            index += 1
        P_b += P[index]
        is_irr += P_b % 3
    return is_irr >= 0
