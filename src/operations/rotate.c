#include "../libraries.h"

/**
 * Find index of `new head` after rotation by an `offset`
 * @param offset How many rotations `(rx/rrx)` we should do in a row
 * @param size Size of stack
*/
static int	calc_new_head(int offset, int size)
{
	if (offset < 0)
	{
		offset = -offset % size;
		return ((size - offset) % size);
	}
	else
		return (offset % size);
}

/**
 * Find index of `new tail` after rotation by an `offset`
 * 
 * `Tail` is located behind `head`
 * @param index_new_head Index of new head
 * @param size Size of stack
*/
static int	calc_new_tail(int index_new_head, int size)
{
	if (index_new_head == 0)
		return (size - 1);
	return (index_new_head - 1);
}

/**
 * Function that `rotates` all Nodes in `dll`
 * 
 * "`Rotates`" in this case means changing all `Node indexes` by an offset
 * 
 * After changing `Node indexes`:
 * 
 * >`new_head` is set in `dll->head`
 * 
 * > `new_tail` is set in `dll->tail`
 * 
 * @param dll Stack a or b
 * @param offset How many rotations `(rx/rrx)` we should do in a row
 * @param i_nh Index of a new head (after rotation)
 * @param i_nt Index of a new tail (after rotation)
*/
static void	handle_rotate(t_dll *dll, int i_nh, int i_nt)
{
	t_node	*new_head;
	t_node	*new_tail;

	new_head = get_node_from_index(dll, i_nh);
	new_tail = get_node_from_index(dll, i_nt);
	
	new_head->prev = NULL;
	dll->head->prev = dll->tail;
	dll->tail->next = dll->head;
	new_tail->next = NULL;
	dll->head = new_head;
	dll->tail = new_tail;
}

/**
 * Rotate stack `dll` by offset <=> shift `Nodes` by offset
 * 
 * `offset` = 0 => `-` 
 * 
 * `offset` > 0 => `r`
 * 
 * `offset` < 0 => `rr`
 * 
 * for example [ra, ra, ra, pb] => 3 rotations
 * @param dll Stack a or b
 * @param offset How many rotations `(rx/rrx)` we should do in a row
*/
void	rotate(t_dll *dll, int offset, int print_flag)
{
	int		index_new_head;
	int		index_new_tail;

	if (!dll || dll->size < 2)
		return ;
	index_new_head = calc_new_head(offset, dll->size);
	if (index_new_head == 0)
		return ; // no change needed
	index_new_tail = calc_new_tail(index_new_head, dll->size);
	handle_rotate(dll, index_new_head, index_new_tail);
	iteri_indexes(dll);
	if (print_flag)
	{
		if (offset > 0)
			ft_printf("r%c\n", dll->name);
		else
			ft_printf("rr%c\n", dll->name);
	}
}

/**
 * Rotate both stacks based on offset
 * @param dll1 Stack a
 * @param dll2 Stack b
 * @param offset How many rotations `(rx/rrx)` we should do in a row
 * on both stacks
*/
void	rotate_both(t_dll *dll1, t_dll *dll2, int offset, int print_flag)
{
	rotate(dll1, offset, FALSE);
	rotate(dll2, offset, FALSE);
	if (print_flag)
	{
		if (offset > 0)
			ft_printf("rr\n");
		else
			ft_printf("rrr\n");
	}
}
