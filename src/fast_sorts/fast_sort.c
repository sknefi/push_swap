#include "../libraries.h"

static void	sort_elements_2(t_dll *stack_a)
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

/**
 * Sorts the elements of the stack
 * @param stack_a The stack to sort
 * @param sort_type The type of sort to perform (2 or 3)
 */
void	fast_sort(t_dll *stack_a, int sort_type)
{
	if (sort_type == 2)
		sort_elements_2(stack_a);
	else if (sort_type == 3)
		sort_elements_3(stack_a);
}
