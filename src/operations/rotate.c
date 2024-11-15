#include "operations.h"

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
static void	handle_rotate(t_dll *dll, int offset, int i_nh, int i_nt)
{
	t_node	*temp;


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
void	rotate(t_dll *dll, int offset)
{
	int		index_new_head;
	int		index_new_tail;
	t_node	*temp;

	if (!dll || dll->size < 2)
		return ;
	index_new_head = calc_new_head(offset, dll->size);
	if (index_new_head == 0)
		return ; // no change needed
	index_new_tail = calc_new_tail(index_new_head, dll->size);
}

/**
 * Rotate both stacks based on offset
 * @param dll1 Stack a
 * @param dll2 Stack b
 * @param offset How many rotations `(rx/rrx)` we should do in a row
 * on both stacks
*/
void	rotate_both(t_dll *dll1, t_dll *dll2, int offset)
{
	rotate(dll1, offset);
	rotate(dll2, offset);
}
