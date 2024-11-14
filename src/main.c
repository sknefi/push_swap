#include <stdio.h>
#include "operations/operations.h"

int	main(int argc, char *argv[])
{
	t_dll	*dll;

	(void) argc;
	dll = dll_create(argv);
	if (dll->head)
		dll->head->data = 99;
	dll_printer(dll);
	return (0);
}
