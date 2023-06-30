/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:24:31 by maroy             #+#    #+#             */
/*   Updated: 2023/06/26 20:29:15 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Include des headers Libft et operations.h
# include "../libft/libft.h"
# include "operations.h"

//include du header externe limits.h pour les int32_t max et min
# include <limits.h>

//-- Defines -------------------------------------------------------------------
//Success
# define OK 1

//Failed
# define KO 0

//Stack A
# define A 'a'

//Stack B
# define B 'b'
//-----------------------------------------------------------------------------

//-- utils.c -------------------------------------------------------------------

//return the length of an array
int32_t	get_array_length(char **array);
//return the size of a stack
int32_t	get_stack_size(t_stack *stack);
//return the index of the min number in a stack
int32_t	get_sort_index(t_stack **stack, int32_t number);
//return the min number between a and b
int32_t	min(int32_t a, int32_t b);
//return the node at the index in the stack
t_stack	*get_node(int32_t index, t_stack **stack);
//-----------------------------------------------------------------------------
//-- checks.c ------------------------------------------------------------------

//check if the number in the stack is the smallest of the stack
//return OK if it is KO if not
int32_t	is_number_min(int32_t number, t_stack **stack);

//check if the stack is sorted
//return OK if sorted KO if not
int32_t	is_sorted(t_stack **stack);
//-----------------------------------------------------------------------------
//-- rotate.c -----------------------------------------------------------------

//get the number of rotate to find , negatives means reverse rotate
int32_t	get_nb_rotate(t_stack **stack, int32_t index);
//rotate the stack to find the min number
void	rotate_stack_to_find_min(t_stack **stack_a);
//rotate the stack to find the number to sort
void	rotate_stack_to_find_sort(t_stack **stack_a, t_stack **stack_b);
//-----------------------------------------------------------------------------
//--free.c --------------------------------------------------------------------
//free a string array
void	free_string_array(char **str_array);
//free stack(s) and exit the program using the exit code
void	free_stack_and_exit(t_stack **stack_a, t_stack **stack_b,
			int32_t e_code);
//-----------------------------------------------------------------------------
//-- init.c -------------------------------------------------------------------

//initialize the stack(s) with the input return KO if it failed OK if not
int32_t	initialize_stack(t_stack **stack, int32_t argc, char **argv);
//-----------------------------------------------------------------------------
//-- validate_Input.c ---------------------------------------------------------

//check if the input is valid return OK if it is KO if not
int32_t	validate_input(int32_t argc, char **argv);
//-----------------------------------------------------------------------------

//-- algo.c -------------------------------------------------------------------

//main algo
void	algo(t_stack **stack_a, t_stack **stack_b);
//-----------------------------------------------------------------------------
//-- s_sort.c -----------------------------------------------------------------

//small sort (2, 3, 4 and 5 numbers)
void	s_sort(t_stack **stack_a, t_stack **stack_b, int32_t size);
//-----------------------------------------------------------------------------
//-- get.c --------------------------------------------------------------------

//get the min number index in the stack
int32_t	get_min_number_index(t_stack **stack);
//get the max number index in the stack
int32_t	get_max_number_index(t_stack **stack);
//-----------------------------------------------------------------------------
#endif