#include "operations.h"

/**
 * Dekrement value of `node->index`
 * 
 * Used in > after removing `top node` from stack,
 * then dekrement indexes of all nodes in dll
 * @param node Node in dll
*/
void	dekrement_indexes(t_node *node)
{
	node->index--;
}

/**
 * Helper function to swap `Nodes indexes`
 * @param x Node1
 * @param y Node2
*/
void	swap_indexes(t_node *x, t_node *y)
{
	int		temp;

	temp = x->index;
	x->index = y->index;
	y->index = temp;
}

/**
 * Get node from index
 * 
 * `NULL` in my algo should be never returned
 * @param dll Stack a or b
 * @param index Index of node I want
 * @return `Node` on `index`
*/
t_node	*get_node_from_index(t_dll *dll, int index)
{
	t_node	*temp;

	temp = dll->head;
	while (temp)
	{
		if (temp->index == index)
			return (temp);
		temp = temp->next;
	}
	return (NULL); // but this shouldnt happen in this algorithm handle_rotate
}

/**
 * Iterates through all nodes in dll and 
 * sets each index from <0, size)
 * @param dll Stack a or b
*/
void	iteri_indexes(t_dll *dll)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = dll->head;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}