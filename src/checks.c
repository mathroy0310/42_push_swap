/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:03:17 by maroy             #+#    #+#             */
/*   Updated: 2023/07/18 13:43:25 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int8_t	is_number_min(int32_t number, t_stack *stack)
{
	while (stack != NULL)
	{
		if (number > stack->content)
			return (KO);
		stack = stack->next;
	}
	return (OK);
}

int8_t	is_sorted(t_stack *stack)
{
	int32_t	current_value;

	current_value = stack->content;
	while (stack != NULL)
	{
		if (current_value > stack->content)
			return (KO);
		current_value = stack->content;
		stack = stack->next;
	}
	return (OK);
}
