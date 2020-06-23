""" LECTURE ET ECRITURE BINAIRE """

"""
    QUESTION 1
"""
with open("valeurs", "rb+") as f:
        print(f.read(4))
