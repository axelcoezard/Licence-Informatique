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

void swap(t_list *L, uint i, uint j);

uint partition(t_list *L, uint p, uint r);

void QuickSort(t_list *L, uint p, uint r);

t_bool sorted(t_list *L);