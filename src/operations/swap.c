#include "../libraries.h"

void static	swap_indexes(Node *x, Node *y)
{
	int		temp;

	temp = x->index;
	x->index = y->index;
	y->index = temp;
}

// swap first two nodes
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

void	swap_both(t_dll *dll1, t_dll *dll2)
{
	swap(dll1);
	swap(dll2);
}