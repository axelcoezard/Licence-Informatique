INSERT INTO "Client" (nom,prenom,adresse_ville,adresse_rue,adresse_cp,tel_prefix,tel,email,age)
values ('Coezard','Axel','Toulon','64 rue alex',83000,33,0656564656,'axel@ere.fr',20),('Cortez','Cedric','Marseille','64 rue du marché',13000,33,0465856458,'cortez@sfr.fr',35),
('Dartagnan','william','Marseille','64 avenue de sainte colombe',13000,33,0656564656,'cortez@sfr.fr',35),('Dupont','Cedric','Toulouse','674 rue de pologne',16500,33,0466586458,'dupont@sfr.fr',55)
,('Mortier','Nicolas','Toulouse','674 avenue fauche',65800,33,0656564656,'Mortier@sfr.fr',18),('Dubert','christophe','Paris','38 avenue champs Elysee',09800,33,0625468458,'Dubert@gmail.com',20)
,('Burns','Andrew','Nice','35 avenue de la gare',06140,33,0656564656,'burns.andrew@gmail.com',22),('Bertois','Florian','Cannes','35 avenue Bernard',06140,33,0668975412,'bertois.florian@gmail.com',22),
('Combreas','Hugo','Toulon','69 avenue de Nice',06140,33,0656564656,'combreas.hugo@gmail.com',21);

INSERT INTO public."Restaurant_info" (
    nb_placeMax, nb_placeRestante, nom_restaurant, description
) VALUES (
    200, 200,
    'La marmite fondue',
    'Un endroit chaleureux où se rassemblent les familles pour manger des plats chauds.'
);

INSERT INTO public."Emplacement" (
    type, nb_place
) VALUES
('Bungalow', 8),('Bungalow', 4),('Bungalow', 2),('Bungalow', 2),
('Roulotte', 3),('Roulotte', 3),
('Tente', 2),('Tente', 2),('Tente', 2),('Tente', 2),
('Caravane', 6),('Caravane', 6),('Caravane', 6),('Caravane', 6);

INSERT INTO public."Tarif" (nom_tarif,prix,date_duree,acompte)
	VALUES ('Bungalow4_1j',40,'1',4),('Bungalow4_7j',252,'7',25),('Bungalow4_30j',960,'30',96),
  ('Bungalow2_1j',30,'1',4),('Bungalow2_7j',189,'7',19),('Bungalow2_30j',720,'30',72),
  ('Bungalow8_1j',70,'1',4),('Bungalow8_7j',441,'7',44),('Bungalow8_30j',1680,'30',168),
  ('Roulotte_1j',50,'1',5),('Roulotte_7j',315,'7',31),('Roulotte_30j',1200,'30',120),
  ('Tente_1j',15,'1',1),('Tente_7j',94.5,'7',9),('Tente_30j',360,'30',36),
  ('Caravane_1j',60,'1',4),('Caravane_7j',378,'7',37),('Caravane_30j',1440,'30',144);


INSERT INTO public."Facture" (id_client)
	VALUES (1),(2),(3),(4),(4),(8),(8),(8),(6),(7);

INSERT INTO public."Historique" (id_facture,id_emplacement,date_sejour)
  VALUES (1,4,'2020-12-01'),(2,3,'2020-12-02'),(3,7,'2020-12-05'),(4,4,'2020-12-07'),(5,6,'2020-12-07'),(6,4,'2020-12-09'),(7,1,'2020-12-09'),(8,10,'2020-12-10'),(9,12,'2020-12-10'),(10,14,'2020-12-12');

INSERT INTO public."Reservation" (id_emplacement,id_client,id_tarif,date_reservation,date_sejour,duree)
	VALUES (12,6,17,'2020-12-07','2020-12-10',7),(13,7,18,'2020-12-08','2020-12-12',30);


INSERT INTO public."Facture_Details" (id_facture,id_tarif,prix)
	VALUES (1,3,360),(2,5,425),(3,7,312),(4,9,156),(5,12,159),(6,3,332),(7,8,245),(8,6,235),(9,17,378),(10,18,1440);
