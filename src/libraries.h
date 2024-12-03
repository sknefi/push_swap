#ifndef LIBRARIES_H
# define LIBRARIES_H

# include "../dll/dll.h"
# include "../libft/libft.h"
# include "operations/operations.h"

// UTILS
int	is_node_above_median(t_node *node, int size_of_stack);
int	ft_abs(int x);
int	ft_min(int x, int y);
int	ft_max(int x, int y);

// ALGO UTILS
void	create_target_nodes(t_dll *stack_a, t_dll *stack_b);
void	prepare_stack_a(t_dll *stack_a, t_dll *stack_b);
void	calc_costs(t_dll *stack_a, t_dll *stack_b);
t_node	*node_with_best_cost(t_dll *stack_b);
void	handle_rotate_a_b(t_dll *stack_a, t_dll *stack_b);

// FAST SORTS
void	sort_elements_3(t_dll *stack_a);

// FAST SORTS UTILS
t_node	*get_biggest_val_node(t_dll *stack);

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