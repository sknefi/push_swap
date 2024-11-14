#include "../src/libraries.h"

void	dll_iteri(t_dll *dll, void (*f)(t_node *node))
{
	t_node	*temp;

	if (!dll || !f)
		return ;
	temp = dll->head;
	while (temp)
	{
		f(temp);
		temp = temp->next;
	}
}
