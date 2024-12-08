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
	a = dll_create(values, 'a');
	if (dynamic_alloc)
		free_split(values);
	if (!a)
		return (ft_error_basic(), EXIT_FAILURE);
	if (!check_for_errors(a))
		return (ft_error_basic(), EXIT_FAILURE);
	b = dll_init('b');
	if (!b)
		return (dll_clear(a), free(a), ft_error_basic(), EXIT_FAILURE);
	push_swap(a, b);
	
	dll_clear(a);
	dll_clear(b);
	free(a);
	free(b);
	return (EXIT_SUCCESS);
}
