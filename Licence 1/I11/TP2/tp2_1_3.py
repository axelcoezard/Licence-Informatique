time = str(input("Entrer une heure au format 'hh:mm': "))

tp_hours = 13
tp_minutes = 0
tp = tp_hours * 60 + tp_minutes

time = int(time.split(":")[0]) * 60 + int(time.split(":")[1])

if time > tp:
    print("Vous etes en retard")
elif time == tp:
    print("Vous etes a l heure")
else:
    print("Vous etes en avance")
