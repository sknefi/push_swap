#include "libraries.h"

void	handle_calc_cost_under_median(t_node *temp_a,
			t_node *temp_b, t_dll *stack_a, t_dll *stack_b)
{
	if (!is_node_above_median(temp_b, stack_b->size))
		temp_b->cost = temp_b->index;
	else
		temp_b->cost = stack_b->size - temp_b->index;
	if (!is_node_above_median(temp_a, stack_a->size))
		temp_b->cost += temp_a->index;
	else
		temp_b->cost += stack_a->size - temp_a->index;
}

void	handle_rotate_node(t_node *node, t_dll *stack)
{
	if (!is_node_above_median(node, stack->size))
		rotate(stack, 1, TRUE);
	else
		rotate(stack, -1, TRUE);
}

void	res_is_stack_sorted(t_dll *stack_a, t_dll *stack_b)
{
	if (is_stack_sorted(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	rotate_min_on_top(t_dll *stack_a)
{
	int		min_index;
	t_node	*min_node;

	min_node = find_smallest_node(stack_a);
	min_index = min_node->index;
	if (min_index <= stack_a->size / 2)
	{
		while (min_index-- > 0)
			rotate(stack_a, 1, TRUE);
	}
	else
	{
		while (min_index++ < stack_a->size)
			rotate(stack_a, -1, TRUE);
	}
}