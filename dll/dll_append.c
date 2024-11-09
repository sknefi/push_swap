#include "../src/libraries.h"

t_dll	*dll_append(t_dll *dll, Node *new_node)
{
	if (!dll || !new_node)
		return (NULL);
	if (!dll->head)
	{
		dll->head = new_node;
		dll->tail = new_node;
	}
	else
	{
		dll->tail->next = new_node;
		new_node->prev = dll->tail;
		dll->tail = new_node;
	}
	dll->size++;
	return (dll);
}