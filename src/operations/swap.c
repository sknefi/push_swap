/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:04:20 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:04:21 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries.h"

/**
 * Swaps the first two nodes in dll
 * 
 * Init `temp1` and `temp2` and asign them as `dll->head` and `dll->head->next`
 * 
 * Change their `next` and `prev` => swap them
 * 
 * If in stack are only two Nodes, set `node1` as new `tail`
 * 
 * Swap their `indexes`
 * @param dll Pointer to the doubly linked list (t_dll) structure
 */
void	swap(t_dll *dll, int print_flag)
{
	t_node	*temp1;
	t_node	*temp2;

	if (dll->size < 2)
		return ;
	temp1 = dll->head;
	temp2 = dll->head->next;
	temp1->next = temp2->next;
	temp1->prev = temp2;
	temp2->next = temp1;
	temp2->prev = NULL;
	swap_indexes(temp1, temp2);
	if (temp1->next)
		temp1->next->prev = temp1;
	if (dll->size == 2)
		dll->tail = temp1;
	dll->head = temp2;
	if (print_flag)
		ft_printf("s%c\n", dll->name);
}

/**
 * Swap first two elements in both stacks
 * @param dll1 Stack a
 * @param dll2 Stack b
*/
void	swap_both(t_dll *dll1, t_dll *dll2, int print_flag)
{
	swap(dll1, FALSE);
	swap(dll2, FALSE);
	if (print_flag)
		ft_printf("ss\n");
}
