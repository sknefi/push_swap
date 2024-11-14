#include <stdio.h>
#include "../src/libraries.h"

/**
 * init stack `a`, `b`
 * 
 * `printer`
 * 
 * `pb`
 * 
 * `printer`
 * 
 * `pb`
 * 
 * `printer`
 * 
 * `pa`
 * 
 * `printer`
*/
void	test1(int argc, char *argv[])
{
	t_dll	*dll_a;
	t_dll	*dll_b;

	(void) argc;
	dll_a = dll_create(argv);
	dll_b = dll_init();

	dll_printer(dll_a);
	dll_printer(dll_b);
	push(dll_b, dll_a);

	ft_printf("###################\n");

	dll_printer(dll_a);
	dll_printer(dll_b);

	push(dll_b, dll_a);

	ft_printf("###################\n");

	dll_printer(dll_a);
	dll_printer(dll_b);

	push(dll_a, dll_b);

	ft_printf("###################\n");

	dll_printer(dll_a);
	dll_printer(dll_b);
}

