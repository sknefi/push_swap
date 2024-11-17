#include "libraries.h"

int	is_node_above_median(t_node *node, int size_of_stack)
{
	if (node->index <= (size_of_stack / 2))
		return (0);
	return (1);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	ft_max(int x, int y)
{
	if (x < y)
		return (y);
	return (x);
}