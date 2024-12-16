/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:03:26 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:03:27 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/libraries.h"

/**
 * Append `node` to to the end of `dll`,
 * set `index=dll->size`
 * 
 * If there is no `dll` or `new_node` NULL will be returned
 * @param dll Double linked list
 * @param new_node Initialized node
*/
void	*dll_append(t_dll *dll, t_node *new_node)
{
	if (!dll || !new_node)
		return (NULL);
	new_node->index = dll->size;
	if (!dll->head)
	{
		dll->head = new_node;
		dll->tail = new_node;
	}
	else
	{
		dll->tail->next = new_node;
		new_node->prev = dll->tail;
		dll->tail = new_node;
	}
	dll->size++;
	return (dll);
}
