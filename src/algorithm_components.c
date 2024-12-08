#include "libraries.h"

/**
 * Push all elements except 3 from `stack a` to `stack b`
 * 
 * Works only for `|a| >= 6`
 * @param stack_a Stack a
 * @param stack_b Stack b
*/
void	prepare_stack_a(t_dll *stack_a, t_dll *stack_b)
{
	while (stack_a->size > 3)
		push(stack_b, stack_a, TRUE);
}

/**
 * Create target nodes from nodes from `stack b` to nodes
 * from `stack a`
 * 
 * Find `b_j` closest bigger number to `a_i`, if `b_j` is
 * biggest number then find the smallest `a_i`
 * 
 * Why are variables in function called so wierd? norminette...(25 lines max)
 * @param stack_a Stack a (nodes are without target_node)
 * @param stack_b Stack b (nodes are with target_node)
*/
void	create_target_nodes(t_dll *stack_a, t_dll *stack_b)
{
	t_node	*min_a;
	t_node	*a_i;
	t_node	*b_j;
	t_node	*best;

	b_j = stack_b->head;
	min_a = stack_a->head;
	while (b_j)
	{
		a_i = stack_a->head;
		best = NULL;
		while (a_i)
		{
			if (a_i->data < min_a->data)
				min_a = a_i;
			if (a_i->data > b_j->data && (!best || a_i->data < best->data))
				best = a_i;
			a_i = a_i->next;
		}
		if (!best)
			b_j->target_node = min_a;
		else
			b_j->target_node = best;
		b_j = b_j->next;
	}
}

/**
 * Calculate all `b_j costs` from `stack b` based on their
 * `target node` from `stack_a`
 * 
 * Caclculating costs only in `nodes` in `stack_b`
 * @param stack_a Stack a 
 * @param stack_b Stack b
*/
void	calc_costs(t_dll *stack_a, t_dll *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_b = stack_b->head;
	while (temp_b)
	{
		temp_a = temp_b->target_node;
		if (!is_node_above_median(temp_b, stack_b->size)
			&& !is_node_above_median(temp_a, stack_a->size))
		{
			temp_b->cost = ft_max(temp_a->index, temp_b->index);
			temp_b = temp_b->next;
			continue ;
		}
		if (is_node_above_median(temp_b, stack_b->size)
			&& is_node_above_median(temp_a, stack_a->size))
		{
			temp_b->cost = ft_max(stack_a->size - temp_a->index,
					stack_b->size - temp_b->index);
			temp_b = temp_b->next;
			continue ;
		}
		handle_calc_cost_under_median(temp_a, temp_b, stack_a, stack_b);
		temp_b = temp_b->next;
	}
}

/**
 * Handle the rotation of `stack a` and `stack b` based on
 * the cost of `temp_a` and `temp_b`
 * 
 * If `temp_a` and `temp_b` are above median, rotate both
 * If `temp_a` and `temp_b` are below median, reverse rotate both
 * If `temp_a` is above median and `temp_b` is below median, rotate `temp_b`
 * If `temp_a` is below median and `temp_b` is above median, rotate `temp_a`
 * @param stack_a Stack a
 * @param stack_b Stack b
*/
void	handle_rotate_a_b(t_dll *stack_a, t_dll *stack_b)
{
	int		temp_a_index;
	int		temp_b_index;
	t_node	*temp_a;
	t_node	*temp_b;

	temp_b = node_with_best_cost(stack_b);
	temp_a = temp_b->target_node;
	temp_a_index = temp_a->index;
	temp_b_index = temp_b->index;
	while (temp_a_index != 0 || temp_b_index != 0)
	{
		if (!is_node_above_median(temp_b, stack_b->size)
			&& !is_node_above_median(temp_a, stack_a->size))
			rotate_both(stack_a, stack_b, 1, TRUE);
		else if (is_node_above_median(temp_b, stack_b->size)
			&& is_node_above_median(temp_a, stack_a->size))
			rotate_both(stack_a, stack_b, -1, TRUE);
		else if (temp_b_index != 0)
			handle_rotate_node(temp_b, stack_b);
		else if (temp_a_index != 0)
			handle_rotate_node(temp_a, stack_a);
		temp_a_index = temp_a->index;
		temp_b_index = temp_b->index;
	}
}


/**
 * Rotate `stack a` to sort it
 * 
 * Rotate `stack a` to sort it
 * @param stack_a Stack a
*/
void	rotate_sorted_stack_a(t_dll *stack_a)
{
	t_node	*smallest_node;

	smallest_node = find_smallest_node(stack_a);
	if (smallest_node->index <= stack_a->size / 2)
	{
		while (stack_a->head != smallest_node)
			rotate(stack_a, 1, TRUE);
	}
	else
	{
		while (stack_a->head != smallest_node)
			rotate(stack_a, -1, TRUE);
	}
}
