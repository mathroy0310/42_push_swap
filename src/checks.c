/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:03:17 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 20:28:42 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_number_min(int number, t_stack **stack)
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

int	is_sorted(t_stack **stack)
{
	t_stack	*current_node;
	int		current_value;

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
