#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERREUR_ARGUMENTS 1

/////////////////////////////////////////////////////
//  LES DECLARATIONS DE TYPES
/////////////////////////////////////////////////////

// --------------------------------------------
// Un entier non-signé
// --------------------------------------------
typedef unsigned int uint;

// --------------------------------------------
// Structure pour les jetons. Selon le type
// (operateur unaire/binaire ou nombre), c'est
// le champ <op> ou <nombre> qui sera exploité
// --------------------------------------------
typedef struct{
  float nombre;
  char op;
  enum{OPUNR,OPBIN,NOMBRE} type;
} TJETON;

//---------------------------------------------
// Une expression postfixe est définie comme
// un tableau de jetons.
//---------------------------------------------
typedef TJETON *TEXPR;

// --------------------------------------------
// Structure de cellule pour définir la
// structure de pile qui suit sous forme de
// liste chaînée. Contient deux champs:
// 1. le <nombre> sur la pile
// 2. le pointeur <suiv> vers la cellule suiv.
// --------------------------------------------
typedef struct tcell{
  float nombre;
  struct tcell *suiv;
} TCELL;

typedef TCELL *TPILE;


/////////////////////////////////////////////////////
//  LES FONCTIONS
/////////////////////////////////////////////////////

//---------------------------------------------
// Renvoie la pile après y avoir empilé une
// nouvelle cellule contenant le <nombre>.
//---------------------------------------------
TPILE Empiler(TPILE pile, float nombre){
  TPILE last;

  last = pile;
  while (last->suiv != NULL)
    last = last->suiv;

  TCELL new_cell = {
    nombre,
    NULL
  };

  last->suiv = &new_cell;
  return last;
}

//---------------------------------------------
// Renvoie la pile étêtée.chaine Le <nombre> présent
// sommet de la pile est traité par "adresse"
// pour être récupéré.
//---------------------------------------------
TPILE Depiler(TPILE pile, float *nombre){
  return NULL;
}

//---------------------------------------------
// Convertit une chaîne de caracteres en jeton
//---------------------------------------------
TJETON Chaine2Jeton(char *chaine){
  TJETON jeton;
  float nombre;
  char op;

  if (sscanf(chaine, "%f", &nombre)) {
    // Si la conversion en float fonctionne
    // On dit que le jeton est un nombre.
    jeton.nombre = nombre;
    jeton.type = NOMBRE;
  } else {
    // Sinon: on récupère l'operateur
    // on trouve son type et on set le jeton.
    op = chaine[0];
    if (op == '+' || op == '-' || op == 'x' || op == '/') {
      jeton.type = OPBIN;
    } else {
      jeton.type = OPUNR;
    }
    jeton.op = op;
  }

  return jeton;
}

//---------------------------------------------
// Convertit les arguments (tableau de chaînes
// de caractères) en expression (tableau de
// jetons).
//---------------------------------------------
TEXPR Arg2Expr(char *arguments[], int n){
  int i;
  TEXPR jetons;

  jetons = malloc(n * sizeof(TJETON));
  i = 0;
  while (i < n) {
    // On convertie chaque argument en jeton
    // et on le stock dans la liste.
    jetons[i] = Chaine2Jeton(arguments[i]);
    i++;
  }
  return jetons;
}

//----------------------------------------------
// Affiche les jetons d'une expression postfixe
//----------------------------------------------
void AfficherExpr(TEXPR expr, uint n){
  printf("JETONS : |");
  for (int i = 0; i < n; i++)
  {
    TJETON jeton = expr[i];
    if ((jeton.type == OPUNR) || (jeton.type == OPBIN))
      printf(" %1c |", jeton.op);
    else
      printf(" %3.2f |",jeton.nombre);
  }
  printf("\n");
}

//---------------------------------------------
// Renvoie (x <op> y) si <op> est binaire
// ou (<op> x) si <op> est unaire
//---------------------------------------------
float Operer(float x, float y, char op){
  switch (op) {
    // Les opérateurs binaires:
    case '+': return x + y;
    case '-': return x - y;
    case 'x': return x * y;
    case '/': return x / y;
    // L'opérateur unaire:
    case '_': return -x;
    // Sinon on renvoie zero.
    default:
      return 0;
  }
}

//---------------------------------------------
// Affiche le contenu de la pile
//---------------------------------------------
void AfficherPile(TPILE pile){
  TPILE current;

  current = pile;

  printf("%f\n", current->nombre);
  if (current->suiv) {
    AfficherPile(current->suiv);
  }
}

//---------------------------------------------
// Renvoie l'évaluation d'une expression
// postfixe <expr> calculée à l'aide d'une pile
//---------------------------------------------
float Evaluer(TEXPR expr, uint n){
  return 0;
}

/////////////////////////////////////////////////////
// FONCTION MAIN
/////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  uint n = argc - 1;  // Le nombre de jetons
  TEXPR expr = NULL;

  if (n < 1) {
    // Si aucun argument sur la ligne de commande: arrêt
    printf("Syntaxe: %s expr\n",argv[0]);
    return ERREUR_ARGUMENTS;
  }
  else {
      // Sinon: on convertit les arguments en tableau de jetons
      expr = Arg2Expr(argv + 1, n);
  }

  AfficherExpr(expr, n);
  printf("\n%f\n", Evaluer(expr, n));
  free(expr);
  return 0;
}
