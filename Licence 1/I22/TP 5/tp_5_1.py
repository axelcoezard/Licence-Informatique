""" LECTURE D'UN FICHIER TEXTE """

"""
    QUESTION 1
"""
with open("texte1", "r+") as f:
    print(f.read(11), end="\n\n")

"""
    QUESTION 2
"""
with open("texte1", "r+") as f:
    print(f.readline(), end="\n\n")
    f.readline()
    print(f.readline(), end="\n\n")

"""
    QUESTION 3
"""
with open("texte1", "r+") as f:
    lines = f.readlines()
    print(lines[1], lines[3])

"""
    QUESTION 1
"""
with open("texte1", "r+") as f:
    for i in range(3):
        print(f.readline())

"""
    QUESTION 2
"""
with open("texte1", "r+") as f:
        print(f.read(3))
