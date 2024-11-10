#include "operations.h"

// push the Node from stack "y_dll" to "x_dll"
void	push(t_dll *x_dll, t_dll *y_dll, Node *node)
{
	
	dll_prepend(x_dll, node);
}