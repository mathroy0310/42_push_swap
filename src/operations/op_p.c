/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:31:49 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 15:12:19 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Operation Push
// if c == B
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// if c == A
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
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
