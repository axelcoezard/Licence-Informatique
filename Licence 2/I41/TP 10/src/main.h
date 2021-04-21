typedef unsigned int uint;

typedef struct
{
    uint n;
    uint *values;
} t_list;

typedef enum
{
    FALSE = 0,
    TRUE = 1
} t_bool;

void minMax(t_list L, uint *min, uint *max);

t_list histogram(t_list L);

void LinearSort(t_list L);

t_bool sorted(t_list *L);

typedef struct t_cell
{
    int value;
    struct t_cell *next;
} t_cell;

typedef t_cell *t_listc;

t_listc Enfiler(t_listc L, int value);

t_listc Empiler(t_listc L, int value);

t_listc Eteter(t_listc *L);

t_listc Repartir(t_listc L);

void TriRepartition(t_listc L);