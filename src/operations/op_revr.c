/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:54:07 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 15:12:19 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Operation Reverse Rotate
// shift down all elements of the stack determined by 'c'  by 1.
// The last element becomes the first one.
void	op_revr(t_stack **a, char c)
{
	t_stack	*node;
	t_stack	*last_node;

	if (get_stack_size(*a) < 2)
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
	if (c == A)
		write(1, "rra\n", 4);
	else if (c == B)
		write(1, "rrb\n", 4);
	else
		return ;
}
