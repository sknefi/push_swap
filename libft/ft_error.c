#include "libft.h"

void	ft_error(char *str)
{
	write(2, "Error: ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_error_basic(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
