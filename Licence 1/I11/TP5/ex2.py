def som_div_propres(n):
    sum = 0
    for div in range(1, n):
        if n % div == 0: sum += div
    return sum

def est_presque_parfait(n):
    return som_div_propres(n) == n - 1

def affiche_presque_parfait(k):
    for i in range(2**k):
        if est_presque_parfait(i): print(i)

affiche_presque_parfait(10)
