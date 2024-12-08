#include "libraries.h"

static void	operation_handler(char *op, t_dll *a, t_dll *b)
{
	if ((ft_strncmp(op, "sa", 3)) == 0)
		swap(a, FALSE);
	else if (ft_strncmp(op, "sb", 3) == 0)
		swap(b, FALSE);
	else if (ft_strncmp(op, "ss", 3) == 0)
		swap_both(a, b, FALSE);
	else if (ft_strncmp(op, "pa", 3) == 0)
		push(a, b, FALSE);
	else if (ft_strncmp(op, "pb", 3) == 0)
		push(b, a, FALSE);
	else if (ft_strncmp(op, "ra", 3) == 0)
		rotate(a, 1, FALSE);
	else if (ft_strncmp(op, "rb", 3) == 0)
		rotate(b, 1, FALSE);
	else if (ft_strncmp(op, "rr", 3) == 0)
		rotate_both(a, b, 1, FALSE);
	else if (ft_strncmp(op, "rra", 4) == 0)
		rotate(a, -1, FALSE);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		rotate(b, -1, FALSE);
	else if (ft_strncmp(op, "rrr", 4) == 0)
		rotate_both(a, b, -1, FALSE);
	else
		ft_error_basic();
}

int	main(int argc, char *argv[])
{
	int		dynamic_alloc;
	char	*line;
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
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
		{
			rotate(a, find_smallest_node(a)->index, FALSE);
			res_is_stack_sorted(a, b);
			free(line);
			break ;
		}
		extract_newline(line);
		operation_handler(line, a, b);
		free(line);
	}
	dll_clear(a);
	dll_clear(b);
	free(a);
	free(b);
	return (EXIT_SUCCESS);
}
