#include "libraries.h"

void	operation_handler(char *op, t_dll *stack_a, t_dll *stack_b)
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
}

int	main(int argc, char *argv[])
{
	char	*line;
	t_dll	*stack_a;
	t_dll	*stack_b;

	(void)argc;
	stack_a = dll_create(argv, 'a');
	stack_b = dll_init('b');
	while ((line = get_next_line(STDIN_FILENO)) != NULL)
	{
		if (line[0] == '\n' && line[1] == '\t')
		{
			if (is_already_sorted(stack_a, stack_b))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
			free(line);
			break ;
		}
		extract_newline(line);
		operation_handler(line, stack_a, stack_b);
		free(line);
	}
	return (EXIT_SUCCESS);
}
