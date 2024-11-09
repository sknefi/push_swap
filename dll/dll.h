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
} Node;

// stack a, stack b
typedef struct dll
{
	int		size;
	Node	*head;
	Node	*tail;
} t_dll;

t_dll	*dll_init(void);


#endif // DLL_H