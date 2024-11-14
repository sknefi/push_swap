#include "../src/libraries.h"

void	dll_clear(t_dll *dll)
{
	t_node	*temp;
	t_node	*head;

	head = dll->head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	dll->head = NULL;
	dll->tail = NULL;
	dll->size = 0;
}