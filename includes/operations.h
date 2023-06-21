/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:26:49 by maroy             #+#    #+#             */
/*   Updated: 2023/06/13 15:36:54 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

typedef struct s_operations
{
	int	nb_ra;
	int	nb_rb;
	int	nb_rra;
	int	nb_rrb;
	int	nb_rrr;
	int	nb_rr;
	int	nb_op;
	int	index_a;
}	t_operations;

void	op_s(t_stack *stack, char c);
void	op_ss(t_stack *stack_a, t_stack *stack_b);
void	op_r(t_stack **a, char c);
void	op_rr(t_stack **a, t_stack **b);

void	op_revr(t_stack **a, char c);
void	op_revrr(t_stack **a, t_stack **b);

void	op_p(t_stack **a, t_stack **b, char c);

void	exec_op(t_operations *op, t_stack **stack_a, t_stack **stack_b);
void	init_operations(t_operations *op);
void	get_op(int i_a, t_stack **s_a, t_stack **s_b, t_operations *op);
#endif