/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:36:41 by maroy             #+#    #+#             */
/*   Updated: 2023/06/26 20:05:28 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//push all the numbers to stack b
static void	push_to_b(t_stack **stack_a, t_stack **stack_b);
//find the best number to push to stack b, and calls get_op
static void	find_cheapest_push_b(t_stack **a, t_stack **b, t_operations *best);
//push all the numbers back to stack a
static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);

void	algo(t_stack **stack_a, t_stack **stack_b)
{
	int32_t	stack_a_size;

	stack_a_size = get_stack_size(*stack_a);
	if (stack_a_size == 1)
		return ;
	if (stack_a_size <= 5)
	{
		s_sort(stack_a, stack_b, stack_a_size);
		return ;
	}
	op_p(stack_a, stack_b, B);
	push_to_b(stack_a, stack_b);
	s_sort(stack_a, stack_b, 3);
	push_back_to_a(stack_a, stack_b);
}

static void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int32_t			stack_a_size;
	t_operations	best_op;

	stack_a_size = get_stack_size(*stack_a);
	while (stack_a_size > 3)
	{
		find_cheapest_push_b(stack_a, stack_b, &best_op);
		exec_op(&best_op, stack_a, stack_b);
		op_p(stack_a, stack_b, B);
		stack_a_size--;
	}
}

static void	find_cheapest_push_b(t_stack **stack_a, t_stack **stack_b,
		t_operations *best)
{
	t_operations	op;
	t_stack			*node;
	int32_t			i;

	node = *stack_a;
	i = 1;
	best->nb_op = INT_MAX;
	while (node != NULL)
	{
		init_operations(&op);
		get_op(i, stack_a, stack_b, &op);
		if (op.nb_op < best->nb_op)
			*best = op;
		i++;
		node = node->next;
	}
}

static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int32_t	stack_b_size;

	stack_b_size = get_stack_size(*stack_b);
	while (stack_b_size > 0)
	{
		rotate_stack_to_find_sort(stack_a, stack_b);
		op_p(stack_a, stack_b, A);
		stack_b_size--;
	}
}
