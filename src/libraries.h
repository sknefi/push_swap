#ifndef LIBRARIES_H
# define LIBRARIES_H

# include "../dll/dll.h"
# include "../libft/libft.h"
# include "operations/operations.h"

# define TRUE 1
# define FALSE 0
# define SEPARATOR ' '

// UTILS
int		is_node_above_median(t_node *node, int size_of_stack);
int		ft_abs(int x);
int		ft_max(int x, int y);
t_node	*node_with_best_cost(t_dll *stack_b);
t_node	*find_smallest_node(t_dll *stack);

// ALGO COMPONENTS
void	create_target_nodes(t_dll *stack_a, t_dll *stack_b);
void	prepare_stack_a(t_dll *stack_a, t_dll *stack_b);
void	calc_costs(t_dll *stack_a, t_dll *stack_b);
t_node	*node_with_best_cost(t_dll *stack_b);
void	handle_rotate_a_b(t_dll *stack_a, t_dll *stack_b);
void	rotate_sorted_stack_a(t_dll *stack_a);
int		is_stack_sorted(t_dll *stack_a, t_dll *stack_b);

// ALGO UTILS
void	handle_calc_cost_under_median(t_node *temp_a,
			t_node *temp_b, t_dll *stack_a, t_dll *stack_b);
void	handle_rotate_node(t_node *node, t_dll *stack);
void	res_is_stack_sorted(t_dll *stack_a, t_dll *stack_b);
void	rotate_min_on_top(t_dll *stack_a);

// FAST SORTS
void	sort_elements_3(t_dll *stack_a);
void	fast_sort(t_dll *stack_a, t_dll *stack_b);

// FAST SORTS UTILS
t_node	*get_biggest_val_node(t_dll *stack);
void	put_smallest_node_on_top(t_dll *stack_a);

// ALGO
void	push_swap(t_dll *stack_a, t_dll *stack_b);

// CHECKER UTILS
void	extract_newline(char *line);

// ERROR HANDLER
void	*check_for_errors(t_dll *stack_a);
void	*check_for_separators_only(char *str_2args);
void	*check_for_duplicates(t_dll *stack_a);

// HANDLERS
char	**handle_2args(char *str_2args);

// FREE MEMORY
void	free_complete_stacks(t_dll *stack_a, t_dll *stack_b);
void	free_stack_a(t_dll *stack_a);

#endif // LIBRARIES_H