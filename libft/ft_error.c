#include "libft.h"

void	ft_error(char *str)
{
	ft_printf("Error: %s\n", str);
	exit(EXIT_FAILURE);
}

void	ft_error_basic(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}