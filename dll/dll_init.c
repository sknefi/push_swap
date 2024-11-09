#include "../src/libraries.h"

t_dll	*dll_init(void)
{
	t_dll	*dll;
    
	dll = (t_dll *)malloc(sizeof(t_dll));
	if (!dll)
		ft_error("malloc failed dll_init()\n");
	dll->size = 0;
	dll->head = NULL;
	dll->tail = NULL;
	return (dll);
}