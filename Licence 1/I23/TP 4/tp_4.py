def Lire():
   chaine = input("Permutation = ")
   return tuple([int(x)-1 for x in chaine.split()])


def Ecrire(s):
    print(tuple(range(1, len(s) + 1)))
    print(tuple(i + 1 for i in s))


"""
    QUESTION 1
"""
def EstPermutation(s):
    cool = sum(1 if c in range(len(s)) else 0 for c in s) == len(s)
    fun = sum(1 if s[i] ):== i else 0 for i in range(len(s))) == 2
    return cool and fun


"""
    QUESTION 2
"""
def Inverser(s):
    pass


"""
    QUESTION 3
"""
def Composer(s, t):
    pass


"""
    QUESTION 4
"""
def Orbite(k, s):
    pass


"""
    QUESTION 5
"""
def Signature(s):
    pass


"""
    QUESTION 6
"""


perm = Lire()
Ecrire(perm)
is_perm = EstPermutation(perm)
print(is_perm)
