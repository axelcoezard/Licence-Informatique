import struct

# with open("prog_1.pyc", "rb") as file:
#     file.read(2)
#     content = file.read()
#     version = struct.pack('H', 3379)
#
#     n_file = open("prog_1_n.pyc", "xb")
#     n_file.write(version + content)
#     n_file.close()


def affiche_structure(fichier):
    with open(fichier, "rb+") as file:
        mn = struct.unpack('H', file.read(2))[0]
        file.read(31) # on saute dans le fichier
        file.read(1) # on saute le type du code

        code_taille = struct.unpack('H', file.read(2))[0]
        code_pos = 34

        file.read(code_taille)

        constant_taille = struct.unpack('H', file.read(2))[0]
        # constant_pos = code_pos + code_taille +

    print("Magic number:", mn)
    print("Partie code:", "pos=", code_pos, ",", "longueur=", code_taille, "octets")

affiche_structure("prog_2.pyc")
