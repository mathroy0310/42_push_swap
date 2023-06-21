/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:03:17 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 20:28:52 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdbool.h>

int	get_array_length(char **array)
{
	int	length;

	length = 0;
	while (array[length] != NULL)
		length++;
	return (length);
}

t_stack	*get_node(int index, t_stack **stack)
{
	int		i;
	t_stack	*node;

	i = 1;
	node = *stack;
	while (node != NULL && i < index)
	{
		i++;
		node = node->next;
	}
	return (node);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size ++;
	}
	return (size);
}

int	find_sort_index(t_stack **stack, int number)
{
	t_stack	*node;
	int		min;
	int		index;
	int		i;

	if (is_number_min(number, stack))
		return (get_max_number_index(stack));
	index = 0;
	min = INT_MIN;
	i = 1;
	node = *stack;
	while (node != NULL)
	{
		if (number > node->content && (node->content >= min))
		{
			min = node->content;
			index = i;
		}
		i++;
		node = node->next;
	}
	return (index);
}
