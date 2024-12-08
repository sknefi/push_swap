#include "libraries.h"

int	is_stack_sorted(t_dll *stack_a, t_dll *stack_b)
{
	t_node	*node;

	if (stack_b->size > 0)
		return (0);
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
	if (is_stack_sorted(stack_a, stack_b))
		return ;
	if (stack_a->size <= 3)
	{
		fast_sort(stack_a, stack_a->size);
		return ;
	}
	prepare_stack_a(stack_a, stack_b);
	sort_elements_3(stack_a);
	while (stack_b->size > 0)
	{
		create_target_nodes(stack_a, stack_b);
		calc_costs(stack_a, stack_b);
		handle_rotate_a_b(stack_a, stack_b);
		push(stack_a, stack_b, TRUE);
	}
	rotate_min_on_top(stack_a);
}
