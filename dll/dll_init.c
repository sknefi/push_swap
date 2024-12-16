/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:03:24 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:03:25 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/libraries.h"

/**
 * Initialize `Double Linked List` with default settings
 * @return Initialized `Double Linked List`
*/
t_dll	*dll_init(char name)
{
	t_dll	*dll;

	dll = (t_dll *)malloc(sizeof(t_dll));
	if (!dll)
		return (NULL);
	dll->name = name;
	dll->size = 0;
	dll->head = NULL;
	dll->tail = NULL;
	return (dll);
}
