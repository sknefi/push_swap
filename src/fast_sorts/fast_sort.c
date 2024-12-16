/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:04:25 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:04:26 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries.h"

static void	sort_elements_2(t_dll *stack_a)
{
	if (stack_a->head->data > stack_a->head->next->data)
		swap(stack_a, TRUE);
}

void	sort_elements_3(t_dll *stack_a)
{
	t_node	*biggest_node;

	biggest_node = get_biggest_val_node(stack_a);
	if (stack_a->head == biggest_node)
		rotate(stack_a, 1, TRUE);
	else if (stack_a->head->next == biggest_node)
		rotate(stack_a, -1, TRUE);
	if (stack_a->head->data > stack_a->head->next->data)
		swap(stack_a, TRUE);
}

void	sort_elements_5(t_dll *stack_a, t_dll *stack_b)
{
	put_smallest_node_on_top(stack_a);
	push(stack_b, stack_a, TRUE);
	put_smallest_node_on_top(stack_a);
	push(stack_b, stack_a, TRUE);
	sort_elements_3(stack_a);
	while (stack_b->size > 0)
	{
		create_target_nodes(stack_a, stack_b);
		calc_costs(stack_a, stack_b);
		handle_rotate_a_b(stack_a, stack_b);
		push(stack_a, stack_b, TRUE);
	}
	rotate_min_on_top(stack_a);
}

/**
 * Sorts the elements of the stack with the 
 * fast sort algorithm for 2, 3 and 5 elements
 * @param stack_a The stack to sort
 * @param stack_b The stack to use for sorting
 */
void	fast_sort(t_dll *stack_a, t_dll *stack_b)
{
	if (stack_a->size == 2)
		sort_elements_2(stack_a);
	else if (stack_a->size == 3)
		sort_elements_3(stack_a);
	else if (stack_a->size == 5)
		sort_elements_5(stack_a, stack_b);
}
