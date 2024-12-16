/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:03:15 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:03:16 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_H
# define DLL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

// all functions in dll are handling indexes
// so in main program I don't need to care about indexes

// element of the stack
typedef struct Node
{
	int				data;
	int				cost;
	int				index;
	struct Node		*next;
	struct Node		*prev;
	struct Node		*target_node;
}	t_node;

// 
typedef struct target_nodes
{
	int		cost;
	t_node	*from_dll1;
	t_node	*to_dll2;
}	t_target_nodes;

// stack a, stack b
typedef struct dll
{
	char	name;
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_dll;

t_dll	*dll_init(char name);
t_dll	*dll_create(char **argv, char name);
void	*dll_append(t_dll *dll, t_node *new_node);
void	*dll_prepend(t_dll *dll, t_node *new_node);
void	dll_clear(t_dll *dll);
void	dll_iteri(t_dll *dll, void (*f)(t_node *node));
void	dll_printer(t_dll *dll);

#endif // DLL_H
