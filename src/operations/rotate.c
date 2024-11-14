#include "operations.h"

// find index of new_head after rotation
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

// find index of new_tail after rotation
static int	calc_new_tail(int index_new_head, int size)
{
	if (index_new_head == 0)
		return (size - 1);
	return (index_new_head - 1);
}

static void	handle_rotate(t_dll *dll, int offset, int i_nh, int i_nt)
{
	Node	*temp;


}

/**
 * 
 * offset = 0 => - ;
 * offset > 0 => r ;
 * offset < 0 => rr ;
 * for example [ra, ra, ra, pb] => 3 rotations
 * @param dll stack a/b
 * @param offset how many rotations we should do in a row
*/
void	rotate(t_dll *dll, int offset)
{
	int		i;
	int		index_new_head;
	int		index_new_tail;
	Node	*temp;

	if (!dll || dll->size < 2)
		return ;
	index_new_head = calc_new_head(offset, dll->size);
	if (index_new_head == 0)
		return ; // no change needed
	index_new_tail = calc_new_tail(index_new_head, dll->size);

}
