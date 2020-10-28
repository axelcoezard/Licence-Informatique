-- 1
SELECT nom, age FROM participant;

-- 2
SELECT avg(age) FROM participant;

-- 3
SELECT sexe, count(sexe) FROM participant GROUP BY sexe;

-- 4
SELECT count(*) FROM cours;

-- 5
SELECT id_cours FROM cours WHERE id_cours IN (
  SELECT id_cours FROM inscription
);

SELECT DISTINCT id_cours FROM cours
NATURAL JOIN inscription;

-- 6
SELECT id_cours FROM cours WHERE id_cours NOT IN (
  SELECT id_cours FROM inscription
);

-- 7
SELECT nom FROM intervenant
NATURAL JOIN atelier
WHERE id_cours NOT IN (
 SELECT id_cours FROM atelier
);

-- 8
SELECT DISTINCT nom FROM participant
NATURAL JOIN inscription
NATURAL JOIN cours
WHERE danse IN ('Rock', 'Salsa');

-- 9
SELECT count(id_intervenant) FROM atelier
NATURAL JOIN cours
GROUP BY danse;

-- 10
SELECT id_cours, nom FROM intervenant
NATURAL JOIN atelier;

-- 11
SELECT id_participant, nom
FROM participant
ORDER BY age DESC
LIMIT 1;

-- 12
SELECT danse
FROM cours
GROUP BY danse
ORDER BY count(danse) DESC
LIMIT 1;

-- 13
SELECT id_cours FROM cours
NATURAL JOIN atelier
GROUP BY id_cours
HAVING count(id_cours) = 1;

-- 14
SELECT id_cours FROM atelier
GROUP BY id_cours
HAVING count(id_cours) >= ALL (
  SELECT count(*) FROM atelier GROUP BY id_cours
);

-- 15
SELECT id_cours, count(id_participant)
FROM inscription
GROUP BY id_cours;

--16
SELECT count(*) FROM atelier
NATURAL JOIN intervenant
WHERE nom = 'Gilles';

-- 17
SELECT id_participant, nom
FROM participant
NATURAL JOIN inscription
NATURAL JOIN cours
WHERE danse = 'Salsa'
GROUP BY id_participant
HAVING count(danse) = (
  SELECT count(*)
  FROM cours
  WHERE danse = 'Salsa'
);

-- 18
SELECT id_participant, nom
FROM participant
NATURAL JOIN inscription
NATURAL JOIN cours
GROUP BY id_participant
HAVING count(id_cours) = 2
AND count(DISTINCT danse) = 2;

-- 19
SELECT id_cours, danse
FROM cours
NATURAL JOIN atelier
NATURAL JOIN intervenant
WHERE nom = 'Amandine';

-- 20
SELECT cours.id_cours, count(id_participant)
FROM intervenant
NATURAL JOIN atelier
NATURAL JOIN cours, inscription
WHERE nom = 'Amandine'
AND atelier.id_cours = inscription.id_cours
GROUP BY cours.id_cours;

-- 21
SELECT id_cours, danse
FROM cours
NATURAL JOIN inscription
NATURAL JOIN participant
WHERE nom in ('Melanie', 'Henri')
GROUP BY id_cours
HAVING count(id_cours) = 2;

-- 22
SELECT p.id_participant, p.nom
FROM participant p, intervenant j, inscription i, atelier a
WHERE p.id_participant = i.id_participant
AND i.id_cours = a.id_cours
AND j.id_intervenant = a.id_intervenant
AND j.nom = 'Denis';

-- 23
SELECT count(*)
FROM participant p, intervenant j, inscription i, atelier a
WHERE p.id_participant = i.id_participant
AND i.id_cours = a.id_cours
AND j.id_intervenant = a.id_intervenant
AND j.nom IN ('Amandine', 'Denis');

-- 24
SELECT id_cours, danse
FROM cours c
GROUP BY id_cours
HAVING (
  SELECT count(p.sexe)
  FROM inscription i, participant p
  WHERE c.id_cours = i.id_cours
  AND i.id_participant = p.id_participant
  AND p.sexe = 'M'
) > ALL (
  SELECT count(p.sexe)
  FROM inscription i, participant p
  WHERE c.id_cours = i.id_cours
  AND i.id_participant = p.id_participant
  AND p.sexe = 'F'
);
