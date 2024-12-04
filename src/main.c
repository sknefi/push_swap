#include <stdio.h>
#include "libraries.h"

int	main(int argc, char *argv[])
{
	t_dll	*stack_a;
	t_dll	*stack_b;

	if (argc < 2)
		return (EXIT_FAILURE);
	(void)argc;
	stack_a = dll_create(argv, 'a');
	stack_b = dll_init('b');
	// dll_printer(stack_a);
	// dll_printer(stack_b);
	// ft_printf("###################\n");
	push_swap(stack_a, stack_b);
	// dll_printer(stack_a);
	// dll_printer(stack_b);
	ft_printf("%d\n", is_already_sorted(stack_a, stack_b));
	return (EXIT_SUCCESS);
}
