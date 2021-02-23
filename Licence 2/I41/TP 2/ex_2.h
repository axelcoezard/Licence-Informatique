typedef enum {
    TRUE=1,
    FALSE=0
} tbool;

uint TailleMot(char * mot);

tbool CommencePar(char * mot, char * deb);

tbool BienParenthesee(char * expr);