def minimum(a, b):
    return a if a < b else b

def maximum(a, b):
    return a if a > b else b

n1 = int(input("n1 = "))
n2 = int(input("n2 = "))

L = ["Bonjour"," ","a"," tout"," le"," monde !!"]

L1 = []
L2 = []
L3 = []

for item in L:
    if len(item) < minimum(n1, n2):
        L1 += [item]
    elif minimum(n1, n2) <= len(item) <= maximum(n1, n2) :
        L2 += [item]
    elif len(item) > maximum(n1, n2) :
        L3 += [item]

print("Chaines de longueur <", minimum(n1, n2), ":", L1)
print("Chaines de longueur entre", minimum(n1, n2), "et", maximum(n1,n2), ":", L2)
print("Chaines de longueur >", maximum(n1, n2), ":", L3)
