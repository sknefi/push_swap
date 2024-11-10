#include "../src/libraries.h"

// all functions in dll are handling indexes
// so in main program I don't need to care about indexes
t_dll	*dll_append(t_dll *dll, Node *new_node)
{
	if (!dll || !new_node)
		return (NULL);
	new_node->index = dll->size;
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