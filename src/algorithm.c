#include "libraries.h"

void	push_swap(t_dll *stack_a, t_dll *stack_b)
{
	prepare_stack_a(stack_a, stack_b);
	//sort_a (ez_sort_3_elements)
	create_target_nodes(stack_a, stack_b);
	calc_costs(stack_a, stack_b);
}