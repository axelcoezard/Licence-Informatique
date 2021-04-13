typedef unsigned int uint;

typedef struct
{
    uint n;
    int *values;
} t_list;

void copy(t_list X, uint i, t_list Y, uint j, uint n);
void merge(t_list L, uint p, uint q, uint r);

void MergeSort(t_list L, uint p, uint r);