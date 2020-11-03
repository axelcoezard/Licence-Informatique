/* 
	TO-DO: Faire la recherche pas dichotomie
*/

/*
	On part d’une liste triée T et on cherche l’élément v 
	(on suppose qu’il s’y trouve). On procède comme suit :
	On compare v à l’élément du milieu de la liste.
	S’il est égal à v, on a fini.
	Sinon, s’il est inférieur, il faut chercher dans la première 
	moitié de la liste. On retourne à l’étape 1 avec la liste réduite.
	S’il est supérieur, on fait de même avec la seconde moitié de la liste.
*/