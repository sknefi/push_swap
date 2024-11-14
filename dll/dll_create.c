#include "dll.h"

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
t_dll	*dll_create(char **argv)
{
	int		i;
	t_node	*new_node;
	t_dll	*dll;

	dll = dll_init();
	i = 1;
	while (argv[i])
	{
		new_node = init_node(ft_atoi(argv[i]));
		// dll_prepend(dll, new_node);
		dll_append(dll, new_node);
		i++;
	}
	return (dll);
}
