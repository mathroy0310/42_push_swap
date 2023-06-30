/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:31:49 by maroy             #+#    #+#             */
/*   Updated: 2023/06/26 16:39:55 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	op_p(t_stack **a, t_stack **b, char c)
{
	t_stack	*node;

	if (c == A)
	{
		node = *b;
		*b = (*b)->next;
		ft_lstadd_front(a, node);
		write(1, "pa\n", 3);
	}
	else if (c == B)
	{
		node = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, node);
		write(1, "pb\n", 3);
	}
	else
		return ;
}
