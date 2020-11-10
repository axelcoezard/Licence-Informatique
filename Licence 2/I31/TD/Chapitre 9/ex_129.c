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

int max(list l)
{
	if (l == NULL)
		return ERR;
	int max = l->content;
	while (l->succ != NULL)
	{
		l = l->succ;
		if (l->content > max)
			max = l->content;
	}
	return max;
}