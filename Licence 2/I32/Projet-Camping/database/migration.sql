CREATE TABLE "Client" (
	"id_client" serial NOT NULL,
	"nom" varchar(70) NOT NULL,
	"prenom" varchar(50) NOT NULL,
	"adresse_ville" varchar(40) NOT NULL,
	"adresse_rue" varchar(255) NOT NULL,
	"adresse_cp" int NOT NULL,
	"tel_prefix" int NOT NULL DEFAULT('33'),
	"tel" int NOT NULL,
	"email" varchar(255) NOT NULL,
	"age" int NOT NULL,
	CONSTRAINT "Client_pk" PRIMARY KEY ("id_client")
) WITH (
  OIDS=FALSE
);



CREATE TABLE "Emplacement" (
	"id_emplacement" serial NOT NULL,
	"nb_place" int NOT NULL,
	"type" varchar(30) NOT NULL,
	CONSTRAINT "Emplacement_pk" PRIMARY KEY ("id_emplacement")
) WITH (
  OIDS=FALSE
);



CREATE TABLE "Place_restaurant" (
	"id_place" serial NOT NULL,
	"id_client" int NOT NULL,
	"id_restaurant" int NOT NULL,
	"nb_place" int NOT NULL,
	CONSTRAINT "Place_restaurant_pk" PRIMARY KEY ("id_place")
) WITH (
  OIDS=FALSE
);



CREATE TABLE "Tarif" (
	"id_tarif" serial NOT NULL,
	"nom_tarif" varchar NOT NULL,
	"prix" int NOT NULL,
	"date_duree" varchar(255) NOT NULL,
	"acompte" int NOT NULL,
	CONSTRAINT "Tarif_pk" PRIMARY KEY ("id_tarif")
) WITH (
  OIDS=FALSE
);



CREATE TABLE "Reservation" (
	"id_reservation" serial NOT NULL,
	"id_emplacement" int NOT NULL,
	"id_client" int NOT NULL,
	"id_tarif" int NOT NULL,
	"date_reservation" DATE NOT NULL DEFAULT CURRENT_DATE,
	"date_sejour" DATE NOT NULL,
	"est_annulee" int NOT NULL DEFAULT '0',
	"duree" int NOT NULL,
	CONSTRAINT "Reservation_pk" PRIMARY KEY ("id_reservation")
) WITH (
  OIDS=FALSE
);



CREATE TABLE "Historique" (
	"id_historique" serial NOT NULL,
	"id_facture" int NOT NULL,
	"id_emplacement" int NOT NULL,
	"date_sejour" DATE NOT NULL,
	CONSTRAINT "Historique_pk" PRIMARY KEY ("id_historique")
) WITH (
  OIDS=FALSE
);



CREATE TABLE "Accompagnant" (
	"id_reservation" int NOT NULL,
	"id_accompagnant" varchar(40) NOT NULL
) WITH (
  OIDS=FALSE
);



CREATE TABLE "Facture" (
	"id_facture" serial NOT NULL,
	"id_client" int NOT NULL,
	CONSTRAINT "Facture_pk" PRIMARY KEY ("id_facture")
) WITH (
  OIDS=FALSE
);



CREATE TABLE "Facture_Details" (
	"id_facture" int NOT NULL,
	"id_tarif" int NOT NULL,
	"prix" int NOT NULL
) WITH (
  OIDS=FALSE
);



CREATE TABLE "Restaurant_info" (
	"id_restaurant" serial NOT NULL,
	"nb_placeMax" int NOT NULL,
	"nb_placeRestante" int NOT NULL,
	"nom_restaurant" varchar(255) NOT NULL,
	"description" varchar(255) NOT NULL,
	CONSTRAINT "Restaurant_info_pk" PRIMARY KEY ("id_restaurant")
) WITH (
  OIDS=FALSE
);





ALTER TABLE "Place_restaurant" ADD CONSTRAINT "Place_restaurant_fk0" FOREIGN KEY ("id_client") REFERENCES "Client"("id_client");
ALTER TABLE "Place_restaurant" ADD CONSTRAINT "Place_restaurant_fk1" FOREIGN KEY ("id_restaurant") REFERENCES "Restaurant_info"("id_restaurant");


ALTER TABLE "Reservation" ADD CONSTRAINT "Reservation_fk0" FOREIGN KEY ("id_emplacement") REFERENCES "Emplacement"("id_emplacement");
ALTER TABLE "Reservation" ADD CONSTRAINT "Reservation_fk1" FOREIGN KEY ("id_client") REFERENCES "Client"("id_client");
ALTER TABLE "Reservation" ADD CONSTRAINT "Reservation_fk2" FOREIGN KEY ("id_tarif") REFERENCES "Tarif"("id_tarif");

ALTER TABLE "Historique" ADD CONSTRAINT "Historique_fk0" FOREIGN KEY ("id_facture") REFERENCES "Facture"("id_facture");
ALTER TABLE "Historique" ADD CONSTRAINT "Historique_fk1" FOREIGN KEY ("id_emplacement") REFERENCES "Emplacement"("id_emplacement");
ALTER TABLE "Historique" ADD CONSTRAINT "Historique_fk2" FOREIGN KEY ("date_sejour") REFERENCES "Reservation"("date_sejour");

ALTER TABLE "Accompagnant" ADD CONSTRAINT "Accompagnant_fk0" FOREIGN KEY ("id_reservation") REFERENCES "Reservation"("id_reservation");
ALTER TABLE "Accompagnant" ADD CONSTRAINT "Accompagnant_fk1" FOREIGN KEY ("id_accompagnant") REFERENCES "Client"("id_client");

ALTER TABLE "Facture" ADD CONSTRAINT "Facture_fk0" FOREIGN KEY ("id_client") REFERENCES "Client"("id_client");

ALTER TABLE "Facture_Details" ADD CONSTRAINT "Facture_Details_fk0" FOREIGN KEY ("id_facture") REFERENCES "Facture"("id_facture");
ALTER TABLE "Facture_Details" ADD CONSTRAINT "Facture_Details_fk1" FOREIGN KEY ("id_tarif") REFERENCES "Tarif"("id_tarif");
