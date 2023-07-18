/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:03:17 by maroy             #+#    #+#             */
/*   Updated: 2023/07/18 13:43:50 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int32_t	get_array_length(char **array)
{
	int32_t	length;

	length = 0;
	while (array[length] != NULL)
		length++;
	return (length);
}

t_stack	*get_node(int32_t index, t_stack **stack)
{
	int32_t	i;
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

int32_t	min(int32_t a, int32_t b)
{
	if (a < b)
		return (a);
	return (b);
}
