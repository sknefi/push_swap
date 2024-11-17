#include "dll.h"

/**
 * Print info about node
 * @param node Initialized node
*/
static void	node_info_print(t_node *node)
{
	ft_printf("------------------\n");
	ft_printf("|    %p |\n", node);
	if (0 <= node->index && node->index <= 9)
		ft_printf("| i[0%d]: ", node->index);
	else
		ft_printf("| i[%d]: ", node->index);
	if (0 <= node->data && node->data <= 9)
		ft_printf("   [0%d] |\n", node->data);
	else
		ft_printf("   [%d] |\n", node->data);
	ft_printf("|  ~~~~~~~~~~~~  |\n");
	if (node->target_node)
	{
		ft_printf("| t: %p |\n", node->target_node);
		if (0 <= node->target_node->data && node->target_node->data <= 9)
			ft_printf("| tVal:     [0%d] |\n", node->target_node->data);
		else
			ft_printf("| tVal:     [%d] |\n", node->target_node->data);
	}
	else
		ft_printf("| t:       (nil) |\n");
	if (0 <= node->cost && node->cost <= 9)
			ft_printf("| cost:     [0%d] |\n", node->cost);
		else
			ft_printf("| cost:     [%d] |\n", node->cost);
	ft_printf("==================\n\\     |  |    /\n");

}

/**
 * All nodes from `dll` will be printed 
 * @param dll Double Linked List
*/
void	dll_printer(t_dll *dll)
{
	ft_printf("\n        NULL     \n");
	if (dll->head)
		ft_printf("/       |  |     \\\n");
	dll_iteri(dll, node_info_print);
	if (dll->head != NULL && dll->tail != NULL)
		ft_printf("        NULL     ");
	printf("\n\n");
}
