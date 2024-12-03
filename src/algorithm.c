#include "libraries.h"

void	push_swap(t_dll *stack_a, t_dll *stack_b)
{
	prepare_stack_a(stack_a, stack_b);
	sort_elements_3(stack_a);
	while (stack_b->size > 0)
	{
		create_target_nodes(stack_a, stack_b);
		calc_costs(stack_a, stack_b);
		handle_rotate_a_b(stack_a, stack_b);
		push(stack_a, stack_b);
	}
	rotate_sorted_stack_a(stack_a);
}