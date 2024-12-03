#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "../../dll/dll.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	swap(t_dll *dll);
void	swap_both(t_dll *dll1, t_dll *dll2);
void	push(t_dll *dest_dll, t_dll *src_dll);

// handles both rx and rrx based of offset
void	rotate(t_dll *dll, int offset); 
void	rotate_both(t_dll *dll1, t_dll *dll2, int offset);

// utils
void	iteri_indexes(t_dll *dll);
void	dekrement_indexes(t_node *node);
void	swap_indexes(t_node *x, t_node *y);
t_node	*get_node_from_index(t_dll *dll, int index);

// printers
void	rotate_printer(t_dll *dll, int offset, int both);
void	push_printer(t_dll *dest_dll);
void	swap_printer(t_dll *dll, int both);

#endif // OPERATIONS_H