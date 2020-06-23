note1 = float(input("Entrer la note du UE 1: "))
note2 = float(input("Entrer la note du UE 2: "))
note3 = float(input("Entrer la note du UE 3: "))

moyenne = (note1 + note2 + note3) / 3

if moyenne >= 10:
    if note1 < 10 or note2 < 10 or note3 < 10:
        print("Semestre valide par compensation")
    else:
        print("Semestre valide")
else:
    print("Session de rattrapage")
