#include "operations.h"

/**
 * Dekrement value of `node->index`
 * 
 * Used in > after removing `top node` from stack,
 * then dekrement indexes of all nodes in dll
 * @param node Node in dll
*/
static void	dekrement_indexes(t_node *node)
{
	node->index--;
}

/**
 * Unlink the `top Node` from `dll`
 * 
 * Sets the `next` and `prev` pointers of the `unlinked node` to `NULL`
 * 
 * Updates the `dll head` and `tail` pointers as needed
 * 
 * Decrements the `dll size`,
 * Decrement all `indexes of Nodes` 
 * @param dll Pointer to the doubly linked list to modify.
 * @return The `unlinked Node pointer`, or `NULL` if the list was empty.
 */
static t_node	*unlink_first_node(t_dll *dll)
{
	t_node	*first_node;
	t_node	*unlinked_node;

	if (!dll || !dll->head)
		return (NULL);
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

/**
 * Push Node from top of stack `srcl_dll` to top of stack `dest_dll`
 * 
 * if there is no `Node` left on `src_dll` nothing will happen
 * @param dest_dll Pointer to `dest_dll` struct
 * @param src_dll Pointer to `src_dll` struct
*/
void	push(t_dll *dest_dll, t_dll *src_dll)
{
	t_node	*unlinked_node;

	unlinked_node = unlink_first_node(src_dll);
	if (unlinked_node) // Node was successfuly removed from $src_dll
		dll_prepend(dest_dll, unlinked_node);
}
