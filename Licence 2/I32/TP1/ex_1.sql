CREATE DOMAIN DOM_SEXE AS CHARACTER(1) CHECK (VALUE IN (`F`, `M`));

DROP TABLE IF EXISTS cours CASCADE;
DROP TABLE IF EXISTS intervenant CASCADE;
DROP TABLE IF EXISTS participant CASCADE;
DROP TABLE IF EXISTS inscription CASCADE;
DROP TABLE IF EXISTS atelier CASCADE;

CREATE TABLE cours (
  id_cours INT PRIMARY KEY NOT NULL,
  danse VARCHAR(10) NOT NULL
);

INSERT INTO cours VALUES
(1, 'Salsa'),
(2, 'Salsa'),
(3, 'Rock'),
(4, 'Rock'),
(5, 'Rock'),
(6, 'Tango'),
(7, 'Tango');

CREATE TABLE intervenant (
  id_intervenant INT PRIMARY KEY NOT NULL,
  nom VARCHAR(10) NOT NULL
);

INSERT INTO intervenant VALUES
(1, 'Rey'),
(2, 'Gilles'),
(3, 'Denis'),
(4, 'Amandine');

CREATE TABLE participant (
  id_participant INT PRIMARY KEY NOT NULL,
  nom VARCHAR(10) NOT NULL,
  age INT NOT NULL,
  sexe DOM_SEXE NOT NULL
);

INSERT INTO participant VALUES
(1, 'Roger', 30, 'M'),
(2, 'Melanie', 33, 'F'),
(3, 'Suzanne', 39, 'F'),
(4, 'Henri', 28, 'M');

CREATE TABLE inscription (
  id_cours INT PRIMARY KEY REFERENCES cours(id_cours),
  id_participant INT PRIMARY KEY REFERENCES participant(id_participant)
);

INSERT INTO inscription VALUES
  (1, 1), (2, 2), (1, 4),
  (3, 4), (4, 3), (4, 2),
  (4, 1), (5, 4), (6, 4),
  (7, 3), (6, 2), (6, 1),
  (7, 4), (6, 3);

CREATE TABLE atelier (
  id_cours INT PRIMARY KEY REFERENCES cours(id_cours),
  id_intervenant INT PRIMARY KEY REFERENCES intervenant(id_intervenant)
);

INSERT INTO atelier VALUES
  (1, 1), (1, 2), (2, 1),
  (3, 4), (4, 4), (4, 3),
  (5, 2), (6, 1), (7, 4),
  (7, 3);

INSERT INTO cours VALUES (5, 'valse');

INSERT INTO atelier VALUES (1, 5);

DELETE FROM cours WHERE id_cours = 1;

INSERT INTO cours VALUES (8, 'slow'), (9, 'chachacha');
INSERT INTO intervenant VALUES (8, 'Quentin');
INSERT INTO atelier VALUES (9, 5);
