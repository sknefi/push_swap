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
		push(stack_b, stack_a);
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
			temp_b->cost = ft_max(stack_a->size - temp_a->index, stack_b->size - temp_b->index);
			temp_b = temp_b->next;
			continue ;
		}
		if (!is_node_above_median(temp_b, stack_b->size))
			temp_b->cost = temp_b->index;
		else
			temp_b->cost = stack_b->size - temp_b->index;
		if (!is_node_above_median(temp_a, stack_a->size))
			temp_b->cost += temp_a->index;
		else
			temp_b->cost += stack_a->size - temp_a->index;
		temp_b = temp_b->next;
	}
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

void handle_rotate_a_b(t_dll *stack_a, t_dll *stack_b)
{
    t_node *temp_a;
    t_node *temp_b;

    temp_b = node_with_best_cost(stack_b);
    temp_a = temp_b->target_node;
	printf("temp_b->data: %d\n", temp_b->data);
	printf("temp_a->data: %d\n", temp_a->data);
    while (temp_a->index != 0 || temp_b->index != 0)
    {
        // Case 1: Rotate both stacks together if beneficial
        if (!is_node_above_median(temp_b, stack_b->size)
            && !is_node_above_median(temp_a, stack_a->size))
        {
            rotate_both(stack_a, stack_b, 1);
            continue;
        }
        if (is_node_above_median(temp_b, stack_b->size)
            && is_node_above_median(temp_a, stack_a->size))
        {
            rotate_both(stack_a, stack_b, -1);
            continue;
        }

        // Case 2: Rotate stack_b to bring temp_b to the top
        if (temp_b->index != 0)
        {
            if (!is_node_above_median(temp_b, stack_b->size))
                rotate(stack_b, 1);
            else
                rotate(stack_b, -1);
        }

        // Case 3: Rotate stack_a to bring temp_a to the top
        if (temp_a->index != 0)
        {
            if (!is_node_above_median(temp_a, stack_a->size))
                rotate(stack_a, 1);
            else
                rotate(stack_a, -1);
        }
    }
}
