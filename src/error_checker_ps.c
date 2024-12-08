#include "libraries.h"

/**
 * @brief Check for duplicates in the stack
 * @param stack_a The stack to check for duplicates
 */
void	*check_for_duplicates(t_dll *stack_a)
{
	t_node	*node;
	t_node	*temp;

	node = stack_a->head;
	while (node)
	{
		temp = node->next;
		while (temp)
		{
			if (node->data == temp->data)
				return (dll_clear(stack_a), free(stack_a), NULL);
			temp = temp->next;
		}
		node = node->next;
	}
	return (stack_a);
}

void	*check_for_separators_only(char *str_2args)
{
	int		i;
	size_t	count;
	size_t	len_str;

	if (!str_2args)
		ft_error_basic();
	len_str = ft_strlen(str_2args);
	if (len_str == 0)
		ft_error_basic();
	i = 0;
	count = 0;
	while (str_2args[i])
	{
		if (str_2args[i] == SEPARATOR)
			count++;
		else
			return (NULL);
		i++;
	}
	if (count == len_str)
		ft_error_basic();
	return (NULL);
}

char	**handle_2args(char *str_2args)
{
	check_for_separators_only(str_2args);
	return (ft_split(str_2args, SEPARATOR));
}

/**
 * @brief Check for errors in the stack
 * @param stack_a The stack to check for errors
*/
void	*check_for_errors(t_dll *stack_a)
{
	return (check_for_duplicates(stack_a));
}
