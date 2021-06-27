



typedef struct {
	Node* next;
	void* value;
} t_Node;

typedef struct {
	t_Node* head;
       	t_Node* tail;
	int length;	
} t_List;

t_Node* stack(t_List* list, void* value);
t_Node* unstack(t_List* list, int index);
t_Node* head(t_List* list);
t_Node* tail(t_List* list);

int main (int argc, char** argv) 
{
	
}

t_Node* stack(t_List* list, void* value)
{
	Node node;

	node = malloc(sizeof(Node));	
	node.next = 0;
	node.value = value;

	list->tail->next = &node;
	list->tail = &node;
	list->length++; 

	return &node;
}

t_Node* unstack(t_List* list, int index) 
{
	t_Node* head;

	if (index < list->length) 
	{
		return NULL;
	}

	head = list->head;
	while (index > 0)
	{
		head = head->next;
		index--;
	}
	
	
}

