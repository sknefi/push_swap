/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:04:04 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:04:05 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	free_complete_stacks(t_dll *stack_a, t_dll *stack_b)
{
	dll_clear(stack_a);
	dll_clear(stack_b);
	free(stack_a);
	free(stack_b);
}

void	free_stack_a(t_dll *stack_a)
{
	dll_clear(stack_a);
	free(stack_a);
}
