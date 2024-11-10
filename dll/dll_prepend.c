#include "../src/libraries.h"

static void	update_indexes(Node *node)
{
	node->index++;
}

// ikrement index of each node, then add new_node with index=0
t_dll	*dll_prepend(t_dll *dll, Node *new_node)
{
	if (!dll || !new_node)
		return (NULL);
	dll_iteri(dll, update_indexes);
	if (!dll->head)
	{
		dll->head = new_node;
		dll->tail = new_node;
	}
	else
	{
		dll->head->prev = new_node;
		new_node->next = dll->head;
		dll->head = new_node;
	}
	dll->size++;
	return (dll);
}