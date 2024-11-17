#ifndef LIBRARIES_H
# define LIBRARIES_H

# include "../dll/dll.h"
# include "../libft/libft.h"
# include "operations/operations.h"

// UTILS
int	is_node_above_median(t_node *node, int size_of_stack);

// ALGO UTILS

void	create_target_nodes(t_dll *stack_a, t_dll *stack_b);
void	prepare_stack_a(t_dll *stack_a, t_dll *stack_b);
void	calc_costs(t_dll *stack_a, t_dll *stack_b);
t_node	*node_with_best_cost(t_dll *stack_b);

// ALGO

void	push_swap(t_dll *stack_a, t_dll *stack_b);

// TESTS

void	test1(int argc, char *argv[]);
void	test2(int argc, char *argv[]);
void	test3(int argc, char *argv[]);
void	test4(int argc, char *argv[]);
void	test5(int argc, char *argv[]);

void	test21(int argc, char *argv[]);

#endif // LIBRARIES_H