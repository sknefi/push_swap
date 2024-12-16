/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:04:23 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:04:24 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../../dll/dll.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// handles sa and sb
void	swap(t_dll *dll, int print_flag);
void	swap_both(t_dll *dll1, t_dll *dll2, int print_flag);

// handles push a and b
void	push(t_dll *dest_dll, t_dll *src_dll, int print_flag);

// handles both rx and rrx based of offset
void	rotate(t_dll *dll, int offset, int print_flag);
void	rotate_both(t_dll *dll1, t_dll *dll2, int offset, int print_flag);

// utils
void	iteri_indexes(t_dll *dll);
void	dekrement_indexes(t_node *node);
void	swap_indexes(t_node *x, t_node *y);
t_node	*get_node_from_index(t_dll *dll, int index);

#endif // OPERATIONS_H