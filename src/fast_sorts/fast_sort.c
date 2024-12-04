#include "../libraries.h"

void	sort_elements_2(t_dll *stack_a)
{
	if (stack_a->head->data > stack_a->head->next->data)
		swap(stack_a, TRUE);
}

void	sort_elements_3(t_dll *stack_a)
{
	t_node	*biggest_node;

	biggest_node = get_biggest_val_node(stack_a);
	if (stack_a->head == biggest_node)
		rotate(stack_a, 1, TRUE);
	else if (stack_a->head->next == biggest_node)
		rotate(stack_a, -1, TRUE);
	if (stack_a->head->data > stack_a->head->next->data)
		swap(stack_a, TRUE);
}
