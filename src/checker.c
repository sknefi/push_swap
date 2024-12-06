#include "libraries.h"

static void	checker_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

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
		checker_error();
}

int	main(int argc, char *argv[])
{
	char	*line;
	char	**values;
	t_dll	*stack_a;
	t_dll	*stack_b;

	if (argc < 2)
		return (EXIT_FAILURE);
	(void)argc;
	if (argc == 2)
		values = ft_split(argv[1], ' ');
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
			res_is_stack_sorted(stack_a, stack_b);
			break ;
		}
		extract_newline(line);
		operation_handler(line, stack_a, stack_b);
		free(line);
	}
	return (EXIT_SUCCESS);
}
