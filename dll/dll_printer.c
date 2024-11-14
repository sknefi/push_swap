#include "dll.h"

static void	node_info_print(Node *node)
{
	ft_printf("--------------\n");
	ft_printf("| %p|\n", &node);
	if (0 <= node->index && node->index <= 9)
		ft_printf("| i[0%d]: ", node->index);
	else
		ft_printf("| i[%d]: ", node->index);

	if (0 <= node->data && node->data <= 9)
		ft_printf("[0%d]|\n", node->data);
	else
		ft_printf("[%d]|\n", node->data);
	ft_printf("==============\n\\    |  |    /\n");
}

void	dll_printer(t_dll *dll)
{
	ft_printf("     NULL     ");
	dll_iteri(dll, node_info_print);
	if (dll->head != dll->tail)
		ft_printf("     NULL     ");
}



//      NULL     
// --------------
// | 0x91bccff19|
// | i[00]: [17]|
// ==============
// \    |  |    /
// --------------
// | 0x16ba4f158|
// | i[01]: [42]|
// ==============
//      NULL     