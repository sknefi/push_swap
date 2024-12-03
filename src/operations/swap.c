#include "../libraries.h"

/**
 * Swaps the first two nodes in dll
 * 
 * Init `temp1` and `temp2` and asign them as `dll->head` and `dll->head->next`
 * 
 * Change their `next` and `prev` => swap them
 * 
 * If in stack are only two Nodes, set `node1` as new `tail`
 * 
 * Swap their `indexes`
 * @param dll Pointer to the doubly linked list (t_dll) structure
 */
void	swap(t_dll *dll)
{
	t_node	*temp1;
	t_node	*temp2;

	if (dll->size < 2)
		return ;
	temp1 = dll->head;
	temp2 = dll->head->next;
	temp1->next = temp2->next;
	temp1->prev = temp2;
	temp2->next = temp1;
	temp2->prev = NULL;
	swap_indexes(temp1, temp2);
	if (temp1->next)
		temp1->next->prev = temp1;
	if (dll->size == 2)
		dll->tail = temp1;
	dll->head = temp2;
}

/**
 * Swap first two elements in both stacks
 * @param dll1 Stack a
 * @param dll2 Stack b
*/
void	swap_both(t_dll *dll1, t_dll *dll2)
{
	swap(dll1);
	swap(dll2);
}
