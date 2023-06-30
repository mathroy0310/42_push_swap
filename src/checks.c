/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:03:17 by maroy             #+#    #+#             */
/*   Updated: 2023/06/26 20:05:43 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int32_t	is_number_min(int32_t number, t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node != NULL)
	{
		if (number > node->content)
			return (KO);
		node = node->next;
	}
	return (OK);
}

int32_t	is_sorted(t_stack **stack)
{
	t_stack	*current_node;
	int32_t	current_value;

	current_node = *stack;
	current_value = current_node->content;
	while (current_node != NULL)
	{
		if (current_value > current_node->content)
			return (KO);
		current_value = current_node->content;
		current_node = current_node->next;
	}
	return (OK);
}
