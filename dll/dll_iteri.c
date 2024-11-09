#include "../src/libraries.h"

void	dll_iteri(t_dll *dll, void (*f)(Node *node))
{
	Node	*temp;

	if (!dll || !f)
		return ;
	temp = dll->head;
	while (temp)
	{
		f(temp);
		temp = temp->next;
	}
}