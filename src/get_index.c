/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:17:16 by maroy             #+#    #+#             */
/*   Updated: 2023/06/26 20:05:36 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int32_t	get_min_number_index(t_stack **stack)
{
	t_stack	*node;
	int32_t	min;
	int32_t	index;
	int32_t	i;

	index = 0;
	min = INT_MAX;
	i = 1;
	node = *stack;
	while (node != NULL)
	{
		if (node->content <= min)
		{
			min = node->content;
			index = i;
		}
		i++;
		node = node->next;
	}
	return (index);
}

int32_t	get_max_number_index(t_stack **stack)
{
	t_stack	*node;
	int32_t	max;
	int32_t	index;
	int32_t	i;

	index = 0;
	max = INT_MIN;
	i = 1;
	node = *stack;
	while (node != NULL)
	{
		if (node->content >= max)
		{
			max = node->content;
			index = i;
		}
		i++;
		node = node->next;
	}
	return (index);
}

int32_t	get_sort_index(t_stack **stack, int32_t number)
{
	t_stack	*node;
	int32_t	min;
	int32_t	index;
	int32_t	i;

	if (is_number_min(number, stack) == OK)
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
