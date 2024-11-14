#include "../libraries.h"

/**
 * Helper function to swap `Nodes indexes`
 * @param x Node1
 * @param y Node2
*/
void static	swap_indexes(Node *x, Node *y)
{
	int		temp;

	temp = x->index;
	x->index = y->index;
	y->index = temp;
}

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
	Node	*temp1;
	Node	*temp2;

	if (dll->size < 2)
		return ;
	// init pointers on 2 first nodes
	temp1 = dll->head;
	temp2 = dll->head->next;
	//  update first pointer
	temp1->next = temp2->next;
	temp1->prev = temp2;
	//  update second pointer
	temp2->next = temp1;
	temp2->prev = NULL;
	// swap indexes (0, 1) to (1, 0)
	swap_indexes(temp1, temp2);
	if (temp1->next)
		temp1->next->prev = temp1;
	if (dll->size == 2)
		dll->tail = temp1;
	dll->head = temp2;
}

/**
 * Swap first two elements on both stacks
 * @param dll1 Stack a
 * @param dll2 Stack b
*/
void	swap_both(t_dll *dll1, t_dll *dll2)
{
	swap(dll1);
	swap(dll2);
}