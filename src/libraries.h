#ifndef LIBRARIES_H
# define LIBRARIES_H

# include "../dll/dll.h"
# include "../libft/libft.h"
# include "operations/operations.h"

void	swap(t_dll *dll);
void	swap_both(t_dll *dll1, t_dll *dll2);
void	push(t_dll *dest_dll, t_dll *src_dll);

// TESTS
void	test1(int argc, char *argv[]);
void	test2(int argc, char *argv[]);
void	test3(int argc, char *argv[]);

#endif // LIBRARIES_H