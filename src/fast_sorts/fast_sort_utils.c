#include "../libraries.h"

/**
 * Get the node with the biggest value in the stack
 * @param stack The stack to search in
 * @return The node with the biggest value
*/
t_node	*get_biggest_val_node(t_dll *stack)
{
	t_node	*temp;
	t_node	*biggest_node;

	temp = stack->head;
	biggest_node = stack->head;
	while (temp)
	{
		if (temp->data > biggest_node->data)
			biggest_node = temp;
		temp = temp->next;
	}
	return (biggest_node);
}

/**
 * Put the smallest node on top of the stack
 * @param stack_a The stack to sort
*/
void	put_smallest_node_on_top(t_dll *stack_a)
{
	int		index_smallest;
	t_node	*smallest_node;

	smallest_node = find_smallest_node(stack_a);
	index_smallest = smallest_node->index;
	if (index_smallest <= stack_a->size / 2)
		while (stack_a->head != smallest_node)
			rotate(stack_a, 1, TRUE);
	else
		while (stack_a->head != smallest_node)
			rotate(stack_a, -1, TRUE);
}
