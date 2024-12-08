#include <stdio.h>
#include "libraries.h"

int	main(int argc, char *argv[])
{
	int		dynamic_alloc;
	char	**values;
	t_dll	*a;
	t_dll	*b;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		check_for_separators_only(argv[1]);
		values = ft_split(argv[1], SEPARATOR);
		dynamic_alloc = TRUE;
	}
	else
	{
		values = argv + 1;
		dynamic_alloc = FALSE;
	}
	if (!values)
		ft_error_basic();
	a = create_stack_a(values, dynamic_alloc);
	b = create_stack_b(a);
	push_swap(a, b);
	return (free_complete_stacks(a, b), EXIT_SUCCESS);
}
