#define LIST_LENGTH 100

typedef struct
{
	int values[LIST_LENGTH];
	int length;
} t_list;

t_list Fusionner(t_list A, t_list B);

t_list Trouver(char *A, char *B);

char *S2B(int N, int t);

char *Blocs(int *L, int size_L, int t);

int DansUnite(float x, float y);

float *Flechette();

int Cribler(int n);
