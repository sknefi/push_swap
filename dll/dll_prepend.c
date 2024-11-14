#include "../src/libraries.h"

/**
 * Inkrement index of `node`
 * @param node Initialized node
*/
static void	inkrement_indexes(t_node *node)
{
	node->index++;
}

// ikrement index of each node, then add new_node with index=0
/**
 * Inkrement index of each `node`, then add `new_node` 
 * with `index=0`
 * @param dll Double Linked List
 * @param new_node Node that will be set as new `head`
*/
void	*dll_prepend(t_dll *dll, t_node *new_node)
{
	if (!dll || !new_node)
		return (NULL);
	dll_iteri(dll, inkrement_indexes);
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
