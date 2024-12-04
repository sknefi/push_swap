#include "../src/libraries.h"

/**
 * Initialize `Double Linked List` with default settings
 * @return Initialized `Double Linked List`
*/
t_dll	*dll_init(char name)
{
	t_dll	*dll;
    
	dll = (t_dll *)malloc(sizeof(t_dll));
	if (!dll)
		ft_error("malloc failed dll_init()\n");
	dll->name = name;
	dll->size = 0;
	dll->head = NULL;
	dll->tail = NULL;
	return (dll);
}