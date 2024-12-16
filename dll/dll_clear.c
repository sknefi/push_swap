/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:03:27 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:03:28 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/libraries.h"

/**
 * Free all `nodes` from `dll`
 * 
 * Then set `dll->heal = dll->tail = NULL`,
 * 
 * `dll->size = 0`
 * @param dll Double linked list
*/
void	dll_clear(t_dll *dll)
{
	t_node	*temp;
	t_node	*head;

	head = dll->head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	dll->head = NULL;
	dll->tail = NULL;
	dll->size = 0;
}
