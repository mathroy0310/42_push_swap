/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:53:05 by maroy             #+#    #+#             */
/*   Updated: 2023/06/16 16:38:14 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Operation Rotate
// Shift up all elements of both parameters
// The first element becomes the last one
void	op_rr(t_stack **a, t_stack **b)
{
	op_r(a, 'r');
	op_r(b, 'r');
	write(1, "rr\n", 3);
}
