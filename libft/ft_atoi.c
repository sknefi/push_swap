/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:58:32 by fkarika           #+#    #+#             */
/*   Updated: 2024/09/24 20:23:47 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		res;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '-')
		neg = -1;
	else
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
}

/**
 * Better version of ft_atoi with error checking (-1 if error, 1 if success)
 * @param str String to convert to integer
 * @param check_flag Pointer to integer to check if conversion was successful
 * @return Converted integer
*/
int	ft_atoii(const char *str, int *check_flag)
{
	int			i;
	int			neg;
	long		res;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '-')
		neg = -1;
	else
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		if ((res * neg) > INT_MAX || (res * neg) < INT_MIN)
		{
			*check_flag = -1;
			return (0);
		}
		i++;
	}
	*check_flag = 1;
	return ((int)res * neg);
}
