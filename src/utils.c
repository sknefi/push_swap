#include "libraries.h"

int	is_node_above_median(t_node *node, int size_of_stack)
{
	if (node->index <= (size_of_stack / 2))
		return (0);
	return (1);
}