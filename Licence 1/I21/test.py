a = 1
b = 2

def operateur(operation):
    global a
    global b
    return operation(a, b)

lambda a, b: [c for c in range(a, b + 1)]

print(c)

list = [
    [1, 2, 3],
    [8, 2, -1],
    [4, 5, 6]
]

print("### SERPENTIN ###")

s_j = len(list[0])
for i in range(len(list)):
    for j in range(s_j):
        print(list[i][s_j - j - 1 if i % 2 == 0 else j])

print("### DIAGONALE ###")

i = 0
j = 0
m = len(list) - 1
while i <= m and j <= m:
    print(list[i][j])
    i += 1
    j += 1

