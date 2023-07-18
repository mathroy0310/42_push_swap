/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:54:07 by maroy             #+#    #+#             */
/*   Updated: 2023/07/13 16:42:39 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	op_revr2(char c);

void	op_revr(t_stack **a, char c)
{
	t_stack	*node;
	t_stack	*last_node;

	if (ft_lstsize(*a) < 2)
		return ;
	node = *a;
	last_node = NULL;
	while (node->next != NULL)
	{
		if (node->next->next == NULL)
		{
			last_node = node->next;
			node->next = NULL;
			break ;
		}
		node = node->next;
	}
	if (last_node != NULL)
	{
		last_node->next = *a;
		*a = last_node;
	}
	op_revr2(c);
	return ;
}

static void	op_revr2(char c)
{
	if (c == A)
		write(1, "rra\n", 4);
	if (c == B)
		write(1, "rrb\n", 4);
}
