#include <stdio.h>
#include "../src/libraries.h"

// TESTS FOR PUSH_SWAP


void	test21(int argc, char *argv[])
{
	t_dll	*dll_a;
	t_dll	*dll_b;

	(void) argc;
	dll_a = dll_create(argv);
	dll_a->name = 'a';
	dll_b = dll_init();
	dll_b->name = 'b';
	dll_printer(dll_a);
	dll_printer(dll_b);

	ft_printf("###################\n");
	push_swap(dll_a, dll_b);

	dll_printer(dll_a);
	dll_printer(dll_b);
}