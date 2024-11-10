#include "operations.h"

static void	dekrement_indexes(Node *node)
{
	node->index--;
}

// unlink top node from src = $unlinked_node
// set $unlinked_node next and prev to NULL
static Node	*unlink_first_node(t_dll *dll)
{
	Node 	*first_node;
	Node	*unlinked_node;

	if (!dll || !dll->head)
		return NULL;
	unlinked_node = dll->head;
	first_node = dll->head->next;
	unlinked_node->next = NULL;
	if (first_node) // there could be single node on stack
		first_node->prev = NULL;
	dll->head = first_node;
	dll->size--;
	if (!first_node || !first_node->next)
		dll->tail = first_node;
	dll_iteri(dll, dekrement_indexes);
	return (unlinked_node);
}

// push the Node from stack "src_dll" to "dest_dll"
void	push(t_dll *dest_dll, t_dll *src_dll)
{
	Node	*unlinked_node;

	unlinked_node = unlink_first_node(src_dll);
	if (unlinked_node)
		dll_prepend(dest_dll, unlinked_node);
}