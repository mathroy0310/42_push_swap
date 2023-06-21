/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:54:07 by maroy             #+#    #+#             */
/*   Updated: 2023/06/16 16:37:47 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Operation Reverse Rotate
// shift down all elements of both parameters
// The last element becomes the first one.
void	op_revrr(t_stack **a, t_stack **b)
{
	op_revr(a, 'r');
	op_revr(b, 'r');
	write(1, "rrr\n", 4);

}
