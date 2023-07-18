/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:26:49 by maroy             #+#    #+#             */
/*   Updated: 2023/07/13 16:46:48 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

//-----------------------------------------------------------------------------
//-- Struct Operations --------------------------------------------------------
typedef struct s_operations
{
	int32_t	nb_ra;
	int32_t	nb_rb;
	int32_t	nb_rra;
	int32_t	nb_rrb;
	int32_t	nb_rrr;
	int32_t	nb_rr;
	int32_t	nb_op;
}			t_operations;
//-----------------------------------------------------------------------------

//Swap the first 2 elements at the top of stack determined by 'c'.
//Do nothing if there is only one or no elements).
void		op_s(t_stack *stack, char c);
//-----------------------------------------------------------------------------
//Swap the first 2 elements at the top of both parameters.
//Do nothing if there is only one or no elements).
void		op_ss(t_stack *stack_a, t_stack *stack_b);
//-----------------------------------------------------------------------------
// Operation Rotate
// Shift up all elements of stack determined by 'c' by 1.
// The first element becomes the last one
void		op_r(t_stack **a, char c);
//-----------------------------------------------------------------------------
// Operation Rotate
// Shift up all elements of both parameters
// The first element becomes the last one
void		op_rr(t_stack **a, t_stack **b);
//-----------------------------------------------------------------------------
// Operation Reverse Rotate
// shift down all elements of the stack determined by 'c'  by 1.
// The last element becomes the first one.
void		op_revr(t_stack **a, char c);
//-----------------------------------------------------------------------------
// Operation Reverse Rotate
// shift down all elements of both parameters
// The last element becomes the first one.
void		op_revrr(t_stack **a, t_stack **b);
//-----------------------------------------------------------------------------
// Operation Push
// if c == B
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// if c == A
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void		op_p(t_stack **a, t_stack **b, char c);
//-----------------------------------------------------------------------------

//initializes the t_operations struct all to zero (0)
void		init_operations(t_operations *op);
//determines the operations to execute to sort the stack
void		get_op(int32_t i_a, t_stack **stack_a, t_stack **stack_b,
				t_operations *op);
//executes the operations determined by the t_operations struct
void		exec_op(t_operations *op, t_stack **stack_a, t_stack **stack_b);
//-----------------------------------------------------------------------------
#endif