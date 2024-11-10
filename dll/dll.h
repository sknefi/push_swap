#ifndef DLL_H
# define DLL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// element of the stack
typedef struct Node
{
	int				data;
	int				index;
	struct Node		*next;
	struct Node		*prev;
	struct Node		*target_node; // toto mozno musim ostranit ak sa rozhodne pre t_target_nodes
} Node;

// 
typedef struct target_nodes
{
	Node	*from_a;
	Node	*to_b;
} t_target_nodes;

// stack a, stack b
typedef struct dll
{
	int		size;
	Node	*head;
	Node	*tail;
} t_dll;

t_dll	*dll_init(void);
t_dll	*dll_append(t_dll *dll, Node *new_node);
t_dll	*dll_prepend(t_dll *dll, Node *new_node);
void	dll_clear(t_dll *dll);
void	dll_iteri(t_dll *dll, void (*f)(Node *node));


#endif // DLL_H

//  32	  = 4	 = 41 = 90
//	temp1	temp2