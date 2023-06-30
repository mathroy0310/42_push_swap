/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:53:05 by maroy             #+#    #+#             */
/*   Updated: 2023/06/26 16:29:25 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	op_r(t_stack **a, char c)
{
	t_stack	*node;
	t_stack	*first_node;

	first_node = *a;
	*a = (*a)->next;
	first_node->next = NULL;
	node = *a;
	while (node->next != NULL)
		node = node->next;
	node->next = first_node;
	if (c == A)
		write(1, "ra\n", 3);
	else if (c == B)
		write(1, "rb\n", 3);
	else
		return ;
}
