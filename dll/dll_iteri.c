/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_iteri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:03:18 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:03:19 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/libraries.h"

/**
 * Iterate through `Double Linked List` and use function `f` 
 * to `node->data`
 * @param dll Double Linked List
 * @param f Function that will be applied to `node->data`
*/
void	dll_iteri(t_dll *dll, void (*f)(t_node *node))
{
	t_node	*temp;

	if (!dll || !f)
		return ;
	temp = dll->head;
	while (temp)
	{
		f(temp);
		temp = temp->next;
	}
}
