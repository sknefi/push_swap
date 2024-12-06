#include "libraries.h"

static void	check_for_duplitcates(t_dll *stack_a)
{
	t_node	*node;
	t_node	*temp;

	node = stack_a->head;
	while (node)
	{
		temp = node->next;
		while (temp)
		{
			if (node->data == temp->data)
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			temp = temp->next;
		}
		node = node->next;
	}
}

void	check_for_errors(t_dll *stack_a)
{
	check_for_duplitcates(stack_a);
}