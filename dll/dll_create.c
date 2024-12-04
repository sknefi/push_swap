#include "dll.h"

static int	ft_isnumber(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if ((str[0] == '-' || str[0] == '+') && ft_isdigit(str[1]))
		i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Initialize node with `data`
 * @param data Integer for node->data
 * @return Initialized node
*/
static t_node	*init_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_node)
		ft_error("Malloc failed - init_node()");
	new_node->data = data;
	new_node->cost = -1;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->target_node = NULL;
	return (new_node);
}

/**
 * Create `dll` with initialazing `nodes` with `data`
 * @param argv Pointer to a pointers of char
 * @return Created `Double Linked List` with `nodes`
*/
t_dll	*dll_create(char **argv, char name)
{
	int		i;
	t_node	*new_node;
	t_dll	*dll;

	dll = dll_init(name);
	i = 1;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		new_node = init_node(ft_atoi(argv[i]));
		dll_append(dll, new_node);
		i++;
	}
	return (dll);
}
