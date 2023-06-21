/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:17:16 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 20:31:50 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_number_index(t_stack **stack)
{
	t_stack	*node;
	int		min;
	int		index;
	int		i;

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

int	get_max_number_index(t_stack **stack)
{
	t_stack	*node;
	int		max;
	int		index;
	int		i;

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
