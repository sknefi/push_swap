#include "libraries.h"

int	is_node_above_median(t_node *node, int size_of_stack)
{
	if (node->index <= (size_of_stack / 2))
		return (0);
	return (1);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_max(int x, int y)
{
	if (x < y)
		return (y);
	return (x);
}

// calc all costs in nodes from stack_b
// return the node with the lowest cost
t_node	*node_with_best_cost(t_dll *stack_b)
{
	t_node	*temp;
	t_node	*cheapest_node;

	temp = stack_b->head;
	cheapest_node = stack_b->head;
	while (temp)
	{
		if (temp->cost == 0 || temp->cost == 1)
			return (temp);
		if (temp->cost < cheapest_node->cost)
			cheapest_node = temp;
		temp = temp->next;
	}
	return (cheapest_node);
}

t_node	*find_smallest_node(t_dll *stack)
{
	t_node	*min;
	t_node	*temp;

	min = stack->head;
	temp = stack->head;
	while (temp)
	{
		if (temp->data < min->data)
			min = temp;
		temp = temp->next;
	}
	return (min);
}