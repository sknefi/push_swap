#include "../libraries.h"

void	rotate_printer(t_dll *dll, int offset, int both)
{
	if (both)
	{
		if (offset > 0)
			ft_printf("rr\n");
		else
			ft_printf("rrr\n");
		return ;
	}
	if (offset > 0)
		ft_printf("r%c\n", dll->name);
	else
		ft_printf("rr%c\n", dll->name);
}

void	push_printer(t_dll *dest_dll)
{
	ft_printf("p%c\n", dest_dll->name);
}

void	swap_printer(t_dll *dll, int both)
{
	if (both)
	{
		ft_printf("ss\n");
		return ;
	}
	ft_printf("s%c\n", dll->name);
}