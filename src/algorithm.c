#include "libraries.h"

static void	fast_sort(t_dll *stack_a, int sort_type)
{
	if (sort_type == 2)
		sort_elements_2(stack_a);
	else if (sort_type == 3)
		sort_elements_3(stack_a);
}

int	is_already_sorted(t_dll *stack_a)
{
	t_node	*node;

	node = stack_a->head;
	while (node->next)
	{
		if (node->next->data && node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

void	push_swap(t_dll *stack_a, t_dll *stack_b)
{
	if (stack_a->size <= 3)
	{
		fast_sort(stack_a, stack_a->size);
		return ;
	}
	if (is_already_sorted(stack_a))
		return ;
	prepare_stack_a(stack_a, stack_b);
	sort_elements_3(stack_a);
	while (stack_b->size > 0)
	{
		create_target_nodes(stack_a, stack_b);
		calc_costs(stack_a, stack_b);
		handle_rotate_a_b(stack_a, stack_b);
		push(stack_a, stack_b);
	}
	rotate(stack_a, find_smallest_node(stack_a)->index, TRUE);
}
