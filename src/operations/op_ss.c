/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:12:50 by maroy             #+#    #+#             */
/*   Updated: 2023/06/16 16:38:32 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//Swap the first 2 elements at the top of both parameters.
//Do nothing if there is only one or no elements).
void	op_ss(t_stack *stack_a, t_stack *stack_b)
{
	op_s(stack_a, 's');
	op_s(stack_b, 's');
	write(1, "ss\n", 3);
}
