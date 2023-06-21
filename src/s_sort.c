/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:40:39 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 19:54:08 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s_sort_two(t_stack **stack)
{
	int	nb1;
	int	nb2;

	nb1 = (*stack)->content;
	nb2 = (*stack)->next->content;
	if (nb1 > nb2)
		op_s(*stack, A);
}

void	s_sort_three(t_stack **stack)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = (*stack)->content;
	nb2 = (*stack)->next->content;
	nb3 = (*stack)->next->next->content;
	if (nb1 < nb2 && nb2 < nb3 && nb3 > nb1)
		return ;
	else if (nb1 > nb2 && nb2 < nb3 && nb3 > nb1)
		op_s(*stack, A);
	else if (nb1 > nb2 && nb2 > nb3 && nb3 < nb1)
	{
		op_s(*stack, A);
		op_revr(stack, A);
	}
	else if (nb1 > nb2 && nb2 < nb3 && nb3 < nb1)
		op_r(stack, A);
	else if (nb1 < nb2 && nb2 > nb3 && nb3 > nb1)
	{
		op_revr(stack, A);
		op_s(*stack, A);
	}
	else if (nb1 < nb2 && nb2 > nb3 && nb3 < nb1)
		op_revr(stack, A);
}

void	s_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack_to_find_min(stack_a);
	op_p(stack_a, stack_b, B);
	s_sort_three(stack_a);
	op_p(stack_a, stack_b, A);
}

void s_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack_to_find_min(stack_a);
    op_p(stack_a, stack_b, B);
	rotate_stack_to_find_min(stack_a);
    op_p(stack_a, stack_b, B);
	s_sort_three(stack_a);
	if (is_sorted(stack_b))
		op_s(*stack_b, B);
    op_p(stack_a, stack_b, A);
    op_p(stack_a, stack_b, A);
}
