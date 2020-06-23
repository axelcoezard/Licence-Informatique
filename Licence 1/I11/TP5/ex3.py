def som_div_propres(n):
    sum = 0
    for div in range(1, n):
        if n % div == 0: sum += div
    return sum

def amicaux(n, m):
    return n == som_div_propres(m) and m == som_div_propres(n)

print(220, 284, amicaux(220, 284)) # Verification

def affiche_amicaux(k):
    for n in range(2**k):
        if amicaux(n, som_div_propres(n)):
            print(n, som_div_propres(n))


affiche_amicaux(11)
