/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:25:52 by maroy             #+#    #+#             */
/*   Updated: 2023/06/13 13:14:49 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	op_s(t_stack *stack, char c)
{
	int32_t	temp;

	temp = stack->next->content;
	stack->next->content = stack->content;
	stack->content = temp;
	if (c == A)
		write(1, "sa\n", 3);
	else if (c == B)
		write(1, "sb\n", 3);
	else
		return ;
}
