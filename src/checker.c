#include "libraries.h"

static void	operation_handler(char *op, t_dll *stack_a, t_dll *stack_b)
{
	if ((ft_strncmp(op, "sa", 3)) == 0)
		swap(stack_a, FALSE);
	else if (ft_strncmp(op, "sb", 3) == 0)
		swap(stack_b, FALSE);
	else if (ft_strncmp(op, "ss", 3) == 0)
		swap_both(stack_a, stack_b, FALSE);
	else if (ft_strncmp(op, "pa", 3) == 0)
		push(stack_a, stack_b, FALSE);
	else if (ft_strncmp(op, "pb", 3) == 0)
		push(stack_b, stack_a, FALSE);
	else if (ft_strncmp(op, "ra", 3) == 0)
		rotate(stack_a, 1, FALSE);
	else if (ft_strncmp(op, "rb", 3) == 0)
		rotate(stack_b, 1, FALSE);
	else if (ft_strncmp(op, "rr", 3) == 0)
		rotate_both(stack_a, stack_b, 1, FALSE);
	else if (ft_strncmp(op, "rra", 4) == 0)
		rotate(stack_a, -1, FALSE);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		rotate(stack_b, -1, FALSE);
	else if (ft_strncmp(op, "rrr", 4) == 0)
		rotate_both(stack_a, stack_b, -1, FALSE);
	else
		ft_error_basic();
}

int	main(int argc, char *argv[])
{
	char	*line;
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
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
		{
			rotate(stack_a, find_smallest_node(stack_a)->index, FALSE);
			res_is_stack_sorted(stack_a, stack_b);
			free(line);
			break ;
		}
		extract_newline(line);
		operation_handler(line, stack_a, stack_b);
		free(line);
	}
	return (EXIT_SUCCESS);
}
