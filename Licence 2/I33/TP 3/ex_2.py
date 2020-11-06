def eval_poly(P, b):
    index, P_b = 0, 0
    while index < len(P) - 1:
        P_b += P[index]
        P_b *= b
        index += 1
    P_b += P[index]
    return P_b


print(eval_poly([3, 5, 4], 2))
