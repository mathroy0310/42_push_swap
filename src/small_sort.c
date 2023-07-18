/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:40:39 by maroy             #+#    #+#             */
/*   Updated: 2023/07/13 16:27:42 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Sort when theres 2 numbers in the stack
static void	s_sort_two(t_stack **stack);
//Sort when theres 3 numbers in the stack
static void	s_sort_three(t_stack **stack);
//Sort when theres 4 numbers in the stack_a
static void	s_sort_four(t_stack **stack_a, t_stack **stack_b);
//Sort when theres 5 numbers in the stacK_a
static void	s_sort_five(t_stack **stack_a, t_stack **stack_b);

void	s_sort(t_stack **stack_a, t_stack **stack_b, int32_t size)
{
	if (size == 2)
		s_sort_two(stack_a);
	if (size == 3)
		s_sort_three(stack_a);
	if (size == 4)
		s_sort_four(stack_a, stack_b);
	if (size == 5)
		s_sort_five(stack_a, stack_b);
}

static void	s_sort_two(t_stack **stack)
{
	int32_t	nb1;
	int32_t	nb2;

	nb1 = (*stack)->content;
	nb2 = (*stack)->next->content;
	if (nb1 > nb2)
		op_s(*stack, A);
}

static void	s_sort_three(t_stack **stack)
{
	int32_t	nb1;
	int32_t	nb2;
	int32_t	nb3;

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

static void	s_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack_to_find_min(stack_a);
	op_p(stack_a, stack_b, B);
	s_sort_three(stack_a);
	op_p(stack_a, stack_b, A);
}

static void	s_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack_to_find_min(stack_a);
	op_p(stack_a, stack_b, B);
	rotate_stack_to_find_min(stack_a);
	op_p(stack_a, stack_b, B);
	s_sort_three(stack_a);
	if (is_sorted(*stack_b) == OK)
		op_s(*stack_b, B);
	op_p(stack_a, stack_b, A);
	op_p(stack_a, stack_b, A);
}
