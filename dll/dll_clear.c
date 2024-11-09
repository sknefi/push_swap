#include "../src/libraries.h"

void	dll_clear(t_dll *dll)
{
	Node	*temp;
	Node	*head;

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