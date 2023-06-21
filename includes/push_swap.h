/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:24:31 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 19:53:13 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "operations.h"
# include <limits.h>

# define OK 1
# define KO 0
# define A 'a'
# define B 'b'

//utils.c
int		get_array_length(char **array);
int		get_stack_size(t_stack *stack);

int	is_number_min(int number, t_stack **stack);

int	find_sort_index(t_stack **stack, int number);
int	get_nb_rotate(t_stack **stack, int index);
int	get_min_number_index(t_stack **stack);
int	is_sorted(t_stack **stack);
int	min(int a, int b);
t_stack	*get_node(int index, t_stack **stack);
void rotate_stack_to_find_min(t_stack **stack_a);
void rotate_stack_to_find_sort(t_stack **stack_a, t_stack **stack_b);
//free.c

void	free_string_array(char **str_array);
void	free_stack_and_exit(t_stack **stack_a, t_stack **stack_b,
			int exit_code);
//init.c

int		initialize_stack(t_stack **stack, int argc, char **argv);

//validate_Input.c
int		validate_input(int argc, char **argv);

//algo.c
void	algo(t_stack **stack_a, t_stack **stack_b);

//s_sort.c
void	s_sort_two(t_stack **stack);
void	s_sort_three(t_stack **stack);
void	s_sort_four(t_stack **stack_a, t_stack **stack_b);
void	s_sort_five(t_stack **stack_a, t_stack **stack_b);



#endif