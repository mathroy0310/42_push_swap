/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:28:28 by maroy             #+#    #+#             */
/*   Updated: 2023/06/26 20:05:04 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//
static void	optimise_rotations(t_operations *op);

void	init_operations(t_operations *op)
{
	op->nb_op = 0;
	op->nb_ra = 0;
	op->nb_rb = 0;
	op->nb_rr = 0;
	op->nb_rra = 0;
	op->nb_rrb = 0;
	op->nb_rrr = 0;
}

void	get_op(int32_t i_a, t_stack **stack_a, t_stack **stack_b,
		t_operations *op)
{
	int32_t	index_b;
	int32_t	index_a;
	int32_t	r;

	index_a = i_a;
	op->index_a = index_a;
	index_b = get_sort_index(stack_b, (get_node(index_a, stack_a))->content);
	r = get_nb_rotate(stack_b, index_b);
	if (r < 0)
		op->nb_rrb = -1 * r;
	else
		op->nb_rb = r;
	r = get_nb_rotate(stack_a, index_a);
	if (r < 0)
		op->nb_rra = -1 * r;
	else
		op->nb_ra = r;
	optimise_rotations(op);
	op->nb_op = op->nb_ra + op->nb_rb + op->nb_rr + op->nb_rra + op->nb_rrb
		+ op->nb_rrr + 1;
}

void	exec_op(t_operations *op, t_stack **stack_a, t_stack **stack_b)
{
	while (--op->nb_ra >= 0)
		op_r(stack_a, A);
	while (--op->nb_rb >= 0)
		op_r(stack_b, B);
	while (--op->nb_rr >= 0)
		op_rr(stack_a, stack_b);
	while (--op->nb_rra >= 0)
		op_revr(stack_a, A);
	while (--op->nb_rrb >= 0)
		op_revr(stack_b, B);
	while (--op->nb_rrr >= 0)
		op_revrr(stack_a, stack_b);
}

//optimise rotations for ra and rb
static void	optimise_rotations(t_operations *op)
{
	if (op->nb_ra > 0 && op->nb_rb > 0)
	{
		op->nb_rr = min(op->nb_ra, op->nb_rb);
		op->nb_rb -= op->nb_rr;
		op->nb_ra -= op->nb_rr;
	}
	if (op->nb_rra > 0 && op->nb_rrb > 0)
	{
		op->nb_rrr = min(op->nb_rra, op->nb_rrb);
		op->nb_rrb -= op->nb_rrr;
		op->nb_rra -= op->nb_rrr;
	}
}
