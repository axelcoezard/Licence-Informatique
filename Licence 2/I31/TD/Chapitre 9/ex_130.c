#include <stdio.h>

typedef struct
{
	int content;
	struct place *succ;
	struct place *prev;
} listNode;
typedef listNode *list;
typedef list *plist;

#define ERR -1

void concat(list l1, list l2);

int main()
{
}

void concat(list l1, list l2)
{
	list ptr = l1;
	int i = 0;
	while (ptr->succ != null)
	{
		ptr = ptr->succ;
		i++;
	}
}