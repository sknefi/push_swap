#include "../src/libraries.h"

t_dll	*dll_prepend(t_dll *dll, Node *new_node)
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
		dll->head->prev = new_node;
		new_node->next = dll->head;
		dll->head = new_node;
	}
	dll->size++;
	return (dll);
}