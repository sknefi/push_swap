/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:04:06 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:04:07 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

t_dll	*create_stack_a(char **values, int dynamic_alloc)
{
	t_dll	*stack_a;

	stack_a = dll_create(values, 'a');
	if (dynamic_alloc)
		free_split(values);
	if (!stack_a)
		ft_error_basic();
	if (!check_for_duplicates(stack_a))
		ft_error_basic();
	return (stack_a);
}

t_dll	*create_stack_b(t_dll *stack_a)
{
	t_dll	*stack_b;

	stack_b = dll_init('b');
	if (!stack_b)
	{
		dll_clear(stack_a);
		free(stack_a);
		ft_error_basic();
	}
	return (stack_b);
}
