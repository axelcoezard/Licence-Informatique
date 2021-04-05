from interface import *
from menus import *
from database import *
import datetime


def main():
    """
        Charge le premier menu et redirige l'utilisateur
        vers le sous-menu qu'il sélectionne.
    """
    choice = show_basic_menu("BIENVENUE", first_menu)
    if compare_ids(choice, first_menu, "CLIENTS"):
        return client_main()
    if compare_ids(choice, first_menu, "CAMPING"):
        return camping_main()
    if compare_ids(choice, first_menu, "STATS"):
        return stats_main()
    elif is_command(choice):
        return exec_command(choice)
    return main()


def is_command(args):
    return str(args) in ["\\q", "\\b"]


def exec_command(args):
    if args == "\\q":
        return quit()
    elif args == "\\b":
        return main()
    return False


"""================================
======= MENUS CLIENTS =============
================================"""


def client_main():
    """
        Charge le menu de gestion des clients
        et redirige l'utilisateur vers l'action
        qu'il souhaite effectuer.
    """
    choice = show_basic_menu("GESTION DES CLIENTS", clients_menu)
    if compare_ids(choice, clients_menu, "AJOUTER_CLIENT"):
        return client_create()
    if compare_ids(choice, clients_menu, "MODIFIER_CLIENT"):
        return client_update()
    if compare_ids(choice, clients_menu, "LISTER_CLIENT"):
        return client_list()
    if compare_ids(choice, clients_menu, "SUPPRIMER_CLIENT"):
        return client_delete()
    if compare_ids(choice, clients_menu, "AFFICHER_CLIENT"):
        return client_list_one()
    if compare_ids(choice, clients_menu, "AJOUTER_RESERVATION"):
        return reservation_create()
    if compare_ids(choice, clients_menu, "ANNULER_RESERVATION"):
        return reservation_delete()
    if compare_ids(choice, clients_menu, "VOIR_RESERVATION"):
        return reservation_list()
    if compare_ids(choice, clients_menu, "RESERVATION_RESTAURANT"):
        return restaurant_reserve()
    if compare_ids(choice, clients_menu, "LIST_FACTURE_CLIENT"):
        return client_list_facture()
    if compare_ids(choice, clients_menu, "SHOW_FACTURE_CLIENT"):
        return client_show_facture()
    elif is_command(choice):
        return exec_command(choice)
    return client_main()


def client_create():
    """
        Demande des informations à l'utilisateur
        pour créer un nouveau client.
    """
    choices = show_create_menu("CREER UN CLIENT", [
        {"nom": "Nom"},
        {"prenom": "Prénom"},
        {"adresse_rue": "Nom de rue"},
        {"adresse_ville": "Ville"},
        {"adresse_cp": "Code postal"},
        {"tel": "Numéro de téléphone"},
        {"email": "Adresse mail"},
        {"age": "Age"},
    ])

    insert_choices("Client", choices)  # Insert les choix dans la BD
    show_ok_menu("Le client a bien été créé!")  # Affiche une confirmation
    client_main()  # Retourne au menu client


def client_update():
    """
        Demande des informations à l'utilisateur
        pour modifier un nouveau client.

        L'utilisateur peut choisir entre garder l'ancienne
        valeur ou la remplacer par une nouvelle.
    """
    id_client = show_ask_menu(
        "MODIFIER UN CLIENT",
        "Quel est l'identifiant du client à modifier?"
    )  # Demande et récupère l'id_client
    result = query(
        "SELECT * FROM \"Client\" WHERE id_client = " + id_client + ";")
    # Affiche le menu de modification
    news = show_change_menu("MODIFIER UN CLIENT",
                            result[0]._asdict(), ["id_client"])
    # Met à jour le client dans la BD
    update_row("Client", "id_client", id_client, news)
    show_ok_menu("Le client a bien été modifié!")  # Affiche une confirmation
    client_main()


def client_list():
    """
        Liste tous les clients.
    """
    # Demande la liste des clients à la BD
    result = query("SELECT * FROM \"Client\" ORDER BY id_client ASC;")
    # Affiche la liste des clients.
    show_list_menu("LISTE DES CLIENTS", result)
    client_main()  # Retourne au menu client


def client_list_one():
    """
        Affiche les données d'un client
    """
    id_client = show_ask_menu(
        "AFFICHER UN CLIENT",
        "Quel est l'identifiant du client à afficher?"
    )
    result = query(
        "SELECT * FROM \"Client\" WHERE id_client = " + id_client + ";")
    show_list_menu("AFFICHER UN CLIENT", result)
    client_main()


def client_delete():
    """
        Supprime un client à partir de l'id_client
    """
    id_client = show_ask_menu(
        "SUPPRIMER UN CLIENT",
        "Quel est l'identifiant du client à supprimer?"
    )
    # SUpprime le client dans la BD
    delete_row("Client", "id_client", id_client)
    show_ok_menu("Le client a bien été supprimé!")  # Affiche une confirmation
    client_main()


def reservation_create():
    """
        Créer une réservation
    """
    # Récupère la date de dans 2 jours
    todayp2 = datetime.date.today() + datetime.timedelta(days=2)
    # Récupère les infos de la nouvelle réservation
    choices = show_create_menu("CREER UNE RESERVATION", [
        {"id_client": "Identifiant du client"},
        {"id_tarif": "Identifiant du tarif"},
        {"id_emplacement": "Identifiant de l'emplacement"},
        {"date_sejour": "Date du séjour (aaaa-mm-jj)"},
        {"duree": "Durée du séjour"}
    ])
    # Converti la date de séjour en datetime
    sejour = datetime.datetime.strptime(
        choices["date_sejour"], "%Y-%m-%d").date()
    # Récupère le nombre d'emplacement du même type déjà réservés.
    emplacement = query("SELECT count(id_emplacement) FROM \"Reservation\" WHERE id_emplacement = " +
                        choices["id_emplacement"])[0]

    if sejour >= todayp2 and int(emplacement[0]) == 0:
        # Ajoute la réservation
        insert_choices("Reservation", choices)
        # Ajoute une facture
        insert_choices("Facture", {"id_client": choices["id_client"]})
        # Récupềre l"id de la facture
        id_facture = select_last_insert("Facture", "id_facture")[0][0]
        # Récupére la durée du tarif
        tarif_duree, tarif_prix = query(
            "SELECT date_duree, prix FROM \"Tarif\" WHERE id_tarif = " + choices["id_tarif"])[0]
        # Calcul du prix final
        prix_final = int(choices["duree"]) / int(tarif_duree) * int(tarif_prix)
        # Ajoute le tarif à la facture
        insert_choices("Facture_Details", {
            "id_facture": id_facture,
            "id_tarif": choices["id_tarif"],
            "prix": prix_final
        })
        # Ajoute une ligne à l'historique
        insert_choices("Historique", {
            "id_facture": id_facture,
            "id_emplacement": choices["id_emplacement"],
            "date_sejour": choices["date_sejour"]
        })
        show_ok_menu("La réservation a bien été créé!")
    else:
        if int(emplacement[0]) > 0:
            show_ok_menu("Choisissez un emplacement disponible!")
        else:
            show_ok_menu("Choisissez une date de réservation plus lointaine!")
    client_main()


def reservation_list():
    result = query(
        "SELECT * FROM \"Reservation\" ORDER BY id_reservation DESC;")
    show_list_menu("LISTE DES RESERVATIONS", result)
    client_main()


def reservation_delete():
    """
        Supprime une réservation
    """
    id_reservation = show_ask_menu(
        "SUPPRIMER UNE RESERVATION",
        "Quel est l'identifiant de la réservation à supprimer?"
    )
    delete_row("Reservation", "id_reservation", id_reservation)
    show_ok_menu("La réservation a bien été supprimé!")
    client_main()


def restaurant_reserve():
    """
        Réserve un restaurant
    """
    choices = show_create_menu("RESERVER RESTAURANT", [
        {"id_client": "Identifiant du client"},
        {"id_restaurant": "Identifiant du restaurant"},
        {"nb_place": "Nombre de places"}
    ])
    # RÉcupère l'id du restaurant
    id_restaurant = choices["id_restaurant"]
    # Récupère le nombre de place
    nb_place = int(choices["nb_place"])
    # Récupère les infos du restaurant
    result = query(
        "SELECT * FROM \"Restaurant_info\" WHERE id_restaurant = " + id_restaurant + ";")[0]

    if result[2] >= nb_place:  # IL y a assez de places ?
        insert_choices("Place_restaurant", choices)  #  Réserve les places
        show_ok_menu("Vos places ont bien été réservées!")
    else:
        show_ok_menu("Il n'y a plus de places dans ce restaurant...")
    client_main()


def client_list_facture():
    """
        Liste les factures d'un client
    """
    id_client = show_ask_menu(
        "LISTE DES FACTURES DU CLIENT", "Quel est l'identifiant du client?")
    result = query(
        "SELECT * FROM \"Facture\" WHERE id_client = " + id_client + " ORDER BY id_facture DESC;")
    show_list_menu("LISTE DES FACTURES DU CLIENT", result)
    client_main()


def client_show_facture():
    """
        Affiche la facture d'un client en détails
    """
    id_facture = show_ask_menu(
        "FACTURE DU CLIENT", "Quel est l'identifiant de la facture?")
    result = query(
        "SELECT \"Tarif\".id_tarif, nom_tarif, \"Facture_Details\".prix " +
        "FROM \"Facture_Details\", \"Tarif\" " +
        "WHERE id_facture = " + id_facture + " AND \"Facture_Details\".id_tarif = \"Tarif\".id_tarif;")

    show_list_menu("FACTURE DU CLIENT id: " + id_facture, result)
    client_main()


"""================================
======= MENUS CAMPING =============
================================"""


def camping_main():
    choice = show_basic_menu("GESTION DU CAMPING", camping_menu)
    if compare_ids(choice, camping_menu, "CREER_TARIF"):
        return tarif_create()
    if compare_ids(choice, camping_menu, "LISTER_TARIF"):
        return tarif_list()
    if compare_ids(choice, camping_menu, "AFFICHER_TARIF"):
        return tarif_list_one()
    if compare_ids(choice, camping_menu, "MODIFIER_TARIF"):
        return tarif_update()
    if compare_ids(choice, camping_menu, "SUPPRIMER_TARIF"):
        return tarif_delete()
    if compare_ids(choice, camping_menu, "CREER_EMPLACEMENT"):
        return emplacement_create()
    if compare_ids(choice, camping_menu, "LISTER_EMPLACEMENT"):
        return emplacement_list()
    if compare_ids(choice, camping_menu, "AFFICHER_EMPLACEMENT"):
        return emplacement_list_one()
    if compare_ids(choice, camping_menu, "MODIFIER_EMPLACEMENT"):
        return emplacement_update()
    if compare_ids(choice, camping_menu, "SUPPRIMER_EMPLACEMENT"):
        return emplacement_delete()
    if compare_ids(choice, camping_menu, "AJOUTER_INFO_RESTAURANT"):
        return restaurant_create()
    if compare_ids(choice, camping_menu, "LISTER_INFO_RESTAURANT"):
        return restaurant_list()
    if compare_ids(choice, camping_menu, "AFFICHER_INFO_RESTAURANT"):
        return restaurant_list_one()
    if compare_ids(choice, camping_menu, "MODIFIER_INFO_RESTAURANT"):
        return restaurant_update()
    if compare_ids(choice, camping_menu, "SUPPRIMER_INFO_RESTAURANT"):
        return restaurant_delete()
    if compare_ids(choice, camping_menu, "HISTORIQUE_EMPLACEMENT"):
        return history_list()
    elif is_command(choice):
        return exec_command(choice)
    return camping_main()


def tarif_create():
    """
        Créer un tarif à partir des infos
        fournies.
    """
    choices = show_create_menu("CREER UN TARIF", [
        {"nom_tarif": "Nom du tarif"},
        {"prix": "Prix"},
        {"date_duree": "Durée (en jours)"},
        {"acompte": "Acompte (en euros)"},
    ])

    insert_choices("Tarif", choices)
    show_ok_menu("Le tarif a bien été créé!")
    camping_main()


def tarif_update():
    """
        Met à jour un tarif à partir des infos
        fournies et des anciennes infos.
    """
    id_tarif = show_ask_menu(
        "MODIFIER UN TARIF",
        "Quel est l'identifiant du tarif à modifier?"
    )
    result = query(
        "SELECT * FROM \"Tarif\" WHERE id_tarif = " + id_tarif + ";")
    news = show_change_menu("MODIFIER UN TARIF",
                            result[0]._asdict(), ["id_tarif"])
    update_row("Tarif", "id_tarif", id_tarif, news)
    show_ok_menu("Le tarif a bien été modifié!")
    camping_main()


def tarif_list():
    """
        Liste tous les tarifs.
    """
    result = query("SELECT * FROM \"Tarif\" ORDER BY id_tarif ASC;")
    show_list_menu("LISTE DES TARIFS", result)
    camping_main()


def tarif_list_one():
    """
        Affiche un seul tarif à partir
        de son id_tarif.
    """
    id_tarif = show_ask_menu(
        "AFFICHER UN TARIF",
        "Quel est l'identifiant du tarif à afficher?"
    )
    result = query(
        "SELECT * FROM \"Tarif\" WHERE id_tarif = " + id_tarif + ";")
    show_list_menu("AFFICHER UN TARRIF", result)
    camping_main()


def tarif_delete():
    """
        Supprime un tarif à partir
        de son id_tarif.
    """
    id_tarif = show_ask_menu(
        "SUPPRIMER UN TARIF",
        "Quel est l'identifiant du tarif à supprimer?"
    )
    delete_row("Tarif", "id_tarif", id_tarif)
    show_ok_menu("Le tarif a bien été supprimé!")
    camping_main()


def emplacement_create():
    """
        Créer un emplacement à partir 
        des infos fournies.
    """
    choices = show_create_menu("CREER UN EMPLACEMENT", [
        {"type": "Type d'emplacement"},
        {"nb_place": "Nombre de places"}
    ])

    insert_choices("Emplacement", choices)
    show_ok_menu("Le emplacement a bien été créé!")
    camping_main()


def emplacement_update():
    """
        Met à jour un emplacement à partir 
        des infos fournies.
    """
    id_emplacement = show_ask_menu(
        "MODIFIER UN EMPLACEMENT",
        "Quel est l'identifiant de l'emplacement à modifier?"
    )
    result = query(
        "SELECT * FROM \"Emplacement\" WHERE id_emplacement = " + id_emplacement + ";")
    news = show_change_menu("MODIFIER UN EMPLACEMENT",
                            result[0]._asdict(), ["id_emplacement"])
    update_row("Emplacement", "id_emplacement", id_emplacement, news)
    show_ok_menu("L'emplacement a bien été modifié!")
    camping_main()


def emplacement_list():
    """
        Liste tous les emplacements.
    """
    result = query(
        "SELECT * FROM \"Emplacement\" ORDER BY id_emplacement ASC;")
    show_list_menu("LISTE DES EMPLACEMENTS", result)
    camping_main()


def emplacement_list_one():
    """
        Affiche un seul emplacement.
    """
    id_emplacement = show_ask_menu(
        "AFFICHER UN EMPLACEMENT",
        "Quel est l'identifiant de l'emplacement à afficher?"
    )
    result = query(
        "SELECT * FROM \"Emplacement\" WHERE id_emplacement = " + id_emplacement + ";")
    show_list_menu("AFFICHER UN EMPLACEMENT", result)
    camping_main()


def emplacement_delete():
    """
        Supprime un emplacement
    """
    id_emplacement = show_ask_menu(
        "SUPPRIMER UN EMPLACEMENT",
        "Quel est l'identifiant de l'emplacement à supprimer?"
    )
    delete_row("Emplacement", "id_emplacement", id_emplacement)
    show_ok_menu("L'emplacement a bien été supprimé!")
    camping_main()


def restaurant_create():
    """
        Créer un restaurant
    """
    choices = show_create_menu("CREER UN RESTAURANT", [
        {"nom_restaurant": "Nom du restaurant"},
        {"description": "Description"},
        {"nb_placeMax": "Nombre maximum de places"},
        {"nb_placeRestante": "Nombre de places de restantes"}
    ])

    insert_choices("Restaurant_info", choices)
    show_ok_menu("Le restaurant a bien été créé!")
    camping_main()


def restaurant_update():
    """
        Met à jour les infos d'un
        restaurant.
    """
    id_restaurant = show_ask_menu(
        "MODIFIER UN RESTAURANT",
        "Quel est l'identifiant du restaurant à modifier?"
    )
    result = query(
        "SELECT * FROM \"Restaurant_info\" WHERE id_restaurant = " + id_restaurant + ";")
    news = show_change_menu("MODIFIER UN RESTAURANT",
                            result[0]._asdict(), ["id_restaurant"])
    update_row("Restaurant_info", "id_restaurant", id_restaurant, news)
    show_ok_menu("Le restaurant a bien été modifié!")
    camping_main()


def restaurant_list():
    """
        Liste tous les restaurants.
    """
    result = query(
        "SELECT * FROM \"Restaurant_info\" ORDER BY id_restaurant ASC;")
    show_list_menu("LISTE DES RESTAURANTS", result)
    camping_main()


def restaurant_list_one():
    """
        Affiche toutes les informations
        d'un seul restaurant.
    """
    id_restaurant = show_ask_menu(
        "AFFICHER UN RESTAURANT",
        "Quel est l'identifiant du restaurant à afficher?"
    )
    result = query(
        "SELECT * FROM \"Restaurant_info\" WHERE id_restaurant = " + id_restaurant + ";")
    show_list_menu("AFFICHER UN RESTAURANT", result)
    camping_main()


def restaurant_delete():
    """
        Supprime un restaurant.
    """
    id_restaurant = show_ask_menu(
        "SUPPRIMER UN RESTAURANT",
        "Quel est l'identifiant du restaurant à supprimer?"
    )
    delete_row("Restaurant_info", "id_restaurant", id_restaurant)
    show_ok_menu("Le restaurant a bien été supprimé!")
    camping_main()


def history_list():
    """
        Liste l'historique.
    """
    id_emplacement = show_ask_menu(
        "HISTORIQUE",
        "Quel est l'identifiant de l'emplacement?"
    )
    result = query("SELECT id_historique, id_facture, date_sejour FROM \"Historique\" WHERE id_emplacement = " +
                   id_emplacement + "ORDER BY date_sejour DESC;")
    show_list_menu("HISTORIQUE", result)
    camping_main()


"""================================
======= MENUS STATISTIQUES ========
================================"""


def stats_main():
    choice = show_basic_menu("STATISTIQUES", stats_menu)
    if compare_ids(choice, stats_menu, "AFFICHER_RECETTE"):
        return recette_show()
    if compare_ids(choice, stats_menu, "AFFICHER_CLIENT_FIDELE"):
        return client_fidele_show()
    if compare_ids(choice, stats_menu, "AFFICHER_CLASSEMENT_EMPLACEMENT"):
        return classement_emplacement_show()
    elif is_command(choice):
        return exec_command(choice)
    return camping_main()


def recette_show():
    """
        Affiche la recette du caming.
    """
    result = query(
        "SELECT SUM(prix) FROM \"Facture_Details\";")[0][0]
    show_ok_menu("Le camping à gagné " + str(result) +
                 "€", "RECETTE DU CAMPING")
    stats_main()


def client_fidele_show():
    """
        Affiche le classement des clients les plus fidèles
    """
    result = query(
        "select \"Client\".id_client as \"Identifiant\", \"Client\".nom as \"Nom\", \"Client\".prenom as \"Prénom\", count(\"Facture\".id_client) AS \"Visites\" from \"Client\",\"Facture\"where \"Client\".id_client = \"Facture\".id_client group by \"Client\".id_client order by count(\"Facture\".id_client) DESC;")
    show_list_menu("Client les plus fidèles", result)
    stats_main()


def classement_emplacement_show():
    """
        Affiche le classement des clients les plus fidèles
    """
    result = query(
        "select \"Emplacement\".id_emplacement as \"Identifiant\", \"Emplacement\".type as \"Type\", count(\"Historique\".id_emplacement) as \"Réservations\" from \"Emplacement\",\"Historique\" where \"Emplacement\".id_emplacement = \"Historique\".id_emplacement group by \"Emplacement\".id_emplacement order by count(\"Historique\".id_emplacement) DESC;")
    show_list_menu("Emplacement les plus visités", result)
    stats_main()


main()  #  Execution de m'interface
