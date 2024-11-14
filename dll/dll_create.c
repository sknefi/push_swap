#include "dll.h"

static Node	*init_node(int data)
{
	Node	*new_node;

	new_node = (Node *)ft_calloc(1, sizeof(Node));
	if (!new_node)
		ft_error("Malloc failed - init_node()");
	new_node->data = data;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->target_node = NULL;
	return (new_node);
}

t_dll	*dll_create(char **argv)
{
	int	i;
	Node	*new_node;
	t_dll	*dll;

	dll = dll_init();
	i = 1;
	while (argv[i])
	{
		new_node = init_node(ft_atoi(argv[i]));
		dll_prepend(dll, new_node);
		i++;
	}
	return (dll);
}