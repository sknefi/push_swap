#include <stdio.h>
#include "libraries.h"

int	main(int argc, char *argv[])
{
	char	**values;
	t_dll	*stack_a;
	t_dll	*stack_b;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		check_for_separators_only(argv[1]);
		values = ft_split(argv[1], SEPARATOR);
	}
	else
		values = argv + 1;
	stack_a = dll_create(values, 'a');
	check_for_errors(stack_a);
	stack_b = dll_init('b');
	push_swap(stack_a, stack_b);
	return (EXIT_SUCCESS);
}
