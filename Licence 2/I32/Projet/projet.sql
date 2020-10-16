-- La table qui liste toutes les agences spatiales 
-- avec leur nom et leur pays.
CREATE TABLE AGENCIES (
	agency_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	agency_name VARCHAR(100) PRIMARY KEY NOT NULL,
	agency_country VARCHAR(100) NOT NULL
);

-- La table  qui liste tous les pas de tir avec leur
-- nom et leur pays.
CREATE TABLE LAUNCH_PADS (
	launchpad_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	launchpad_name VARCHAR(100) PRIMARY KEY NOT NULL,
	launchpad_country VARCHAR(100)
);

-- La table qui liste tous les pas d'aterrisage avec
-- leur nom.
CREATE TABLE LANDING_PADS (
	landingpad_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	landingpad_name VARCHAR(100) PRIMARY KEY NOT NULL
);

-- La table qui liste tous les boosters
CREATE TABLE BOOSTERS (
	booster_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
);

-- La table qui liste toutes les coiffres.
CREATE TABLE FAIRINGS (
	fairing_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
);

-- La table qui liste toutes les fusées et leur nom. 
-- Une fusée est composée d'un booster et d'une coiffe.
CREATE TABLE ROCKETS (
	rocket_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	rocket_name VARCHAR(100) NOT NULL,
	booster_id INT NOT NULL REFERENCES BOOSTERS(booster_id)
	fairing_id INT NOT NULL REFERENCES FAIRINGS(fairing_id)
);

-- La table qui liste toutes les charges utiles.
CREATE TABLE PAYLOADS (
	payload_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT
);

-- La table qui liste toutes les équipes qui vont
-- embarquer dans une fusée.
CREATE TABLE CREWS (
	crew_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT
);

-- La table qui liste chaque mission.
CREATE TABLE MISSION (
	mission_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	mission_date TIMESTAMP PRIMARY KEY DEFAULT CURRENT_TIMESTAMP(),
	agency_id INT PRIMARY KEY NOT NULL REFERENCES AGENCIES(agency_id),
	rocket_id INT PRIMARY KEY NOT NULL REFERENCES ROCKETS(rocket_id),
	payload_id INT REFERENCES PAYLOADS(payload_id),
	crew_id INT REFERENCES CREWS(crew_id),
	launchpad_id INT NOT NULL REFERENCES LAUNCH_PADS(launchpad_id)
	landingpad_id INT REFERENCES LANDING_PADS(landingpad_id)
);
