class Test: pass

t = Test()

setattr(t, "variable0", "Caca")
setattr(t, "variable1", "Prout")
setattr(t, "variable2", "C'est pas drole")

for i in range(3):
    print(getattr(t, "variable" + str(i)))
