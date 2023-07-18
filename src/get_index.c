/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:17:16 by maroy             #+#    #+#             */
/*   Updated: 2023/07/13 17:55:09 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int32_t	get_min_number_index(t_stack *stack)
{
	int32_t	min;
	int32_t	min_index;
	int32_t	i;

	min_index = 0;
	min = INT_MAX;
	i = 1;
	while (stack != NULL)
	{
		if (stack->content <= min)
		{
			min = stack->content;
			min_index = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_index);
}

int32_t	get_max_number_index(t_stack *stack)
{
	int32_t	max;
	int32_t	max_index;
	int32_t	i;

	max_index = 0;
	max = INT_MIN;
	i = 1;
	while (stack != NULL)
	{
		if (stack->content >= max)
		{
			max = stack->content;
			max_index = i;
		}
		i++;
		stack = stack->next;
	}
	return (max_index);
}

int32_t	get_sort_index(t_stack *stack, int32_t number)
{
	int32_t	min;
	int32_t	index;
	int32_t	i;

	if (is_number_min(number, stack) == OK)
		return (get_max_number_index(stack));
	index = 0;
	min = INT_MIN;
	i = 1;
	while (stack != NULL)
	{
		if (number > stack->content && stack->content >= min)
		{
			min = stack->content;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}
