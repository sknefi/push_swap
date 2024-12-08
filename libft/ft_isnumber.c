#include "libft.h"

int	ft_isnumber(char *str)
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
