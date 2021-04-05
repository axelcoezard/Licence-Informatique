import os


def compare_ids(id, menu, menu_title):
    menu_id = menu.get(menu_title).get("id")
    return id == str(menu_id)


def show_basic_menu(title, options):
    os.system('clear')
    print("====================================", title, sep="\n")
    print("====================================", "", sep="\n")
    for option in options.values():
        if "subtitle" in option.keys():
            print("\n***", option.get("title"), "***")
            continue
        print(str(option.get("id")) + ".", option.get("title"))
    print("", "====================================", sep="\n")
    print("\\b: retour en arrière. \\q pour quitter.")
    print("====================================")
    choice = str(input("Choix:"))
    return choice


def show_create_menu(title, options):
    choices = {}
    for option in options:
        key = list(option.keys())[0]
        value = list(option.values())[0]
        os.system('clear')
        print("====================================", title, sep="\n")
        print("====================================", "", sep="\n")
        print("Entrer", value)
        print("====================================")
        choices[key] = str(input("Choix:"))
    return choices


def show_change_menu(title, olds, blacklist):
    news = {}
    keys = list(olds.keys())
    values = list(olds.values())
    for key, value in zip(keys, values):
        if key in blacklist:
            continue
        os.system('clear')
        print("====================================", title, sep="\n")
        print("====================================", "", sep="\n")
        print("Entrer", key)
        print("====================================")
        inp = str(input("Valeur [" + str(value) + "]:"))
        if len(inp) > 0:
            news[key] = inp
    return news


def show_list_menu(title, options):
    os.system('clear')
    print("====================================", title, sep="\n")
    print("====================================", "", sep="\n")
    keys = options[0]._asdict().keys()
    keys_line = " | ".join(keys)
    print(keys_line, "-" * len(keys_line), sep="\n", end="\n")
    for option in options:
        line = " | ".join(str(o) for o in list(option))
        print(line, "-" * len(line), sep="\n", end="\n")
    print("", "====================================", sep="\n")
    print("[Entrer]: retour en arrière.")
    print("====================================")
    choice = str(input("Choix:"))
    return choice


def show_ask_menu(title, message):
    os.system('clear')
    print("====================================", title, sep="\n")
    print("====================================", "", sep="\n")
    print("", message, "", sep="\n")
    print("====================================")
    return str(input("Valeur:"))


def show_ok_menu(message, title="Validation"):
    os.system('clear')
    print("====================================", title, sep="\n")
    print("====================================", "", sep="\n")
    print("", message, "", sep="\n")
    print("====================================")
    input("Appuyez sur [entrer] pour continuer...")
