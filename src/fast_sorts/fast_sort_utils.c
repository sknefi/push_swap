#include "../libraries.h"

t_node	*get_biggest_val_node(t_dll *stack)
{
	t_node	*temp;
	t_node	*biggest_node;

	temp = stack->head;
	biggest_node = stack->head;
	while (temp)
	{
		if (temp->data > biggest_node->data)
			biggest_node = temp;
		temp = temp->next;
	}
	return (biggest_node);
}