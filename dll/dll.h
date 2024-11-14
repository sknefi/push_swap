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
	int				index;
	struct Node		*next;
	struct Node		*prev;
	struct Node		*target_node; // toto mozno musim ostranit ak sa rozhodne pre t_target_nodes
}	t_node;

// 
typedef struct target_nodes
{
	t_node	*from_a;
	t_node	*to_b;
}	t_target_nodes;

// stack a, stack b
typedef struct dll
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_dll;

t_dll	*dll_init(void);
t_dll	*dll_create(char **argv);
void	*dll_append(t_dll *dll, t_node *new_node);
void	*dll_prepend(t_dll *dll, t_node *new_node);
void	dll_clear(t_dll *dll);
void	dll_iteri(t_dll *dll, void (*f)(t_node *node));
void	dll_printer(t_dll *dll);

#endif // DLL_H
