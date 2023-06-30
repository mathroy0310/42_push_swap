/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:19:51 by maroy             #+#    #+#             */
/*   Updated: 2023/06/26 19:54:36 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//rotate the stack to find the best index to push to stack b
static void	exec_rotate_stack(t_stack **stack_a, int32_t index);

int32_t	get_nb_rotate(t_stack **stack, int32_t index)
{
	int32_t	stack_size;
	int32_t	nb_rotate;

	nb_rotate = 0;
	stack_size = get_stack_size(*stack);
	if (stack_size / 2 >= index)
		nb_rotate = (index - 1);
	else if (stack_size / 2 < index)
		nb_rotate = (stack_size - index + 1) * -1;
	if (stack_size == 5 && index == 3)
		nb_rotate = 2;
	return (nb_rotate);
}

void	rotate_stack_to_find_sort(t_stack **stack_a, t_stack **stack_b)
{
	int32_t	index;

	index = get_sort_index(stack_a, (*stack_b)->content) + 1;
	exec_rotate_stack(stack_a, index);
}

void	rotate_stack_to_find_min(t_stack **stack_a)
{
	int32_t	min_index;

	min_index = get_min_number_index(stack_a);
	exec_rotate_stack(stack_a, min_index);
}

static void	exec_rotate_stack(t_stack **stack_a, int32_t index)
{
	int32_t	r;

	r = get_nb_rotate(stack_a, index);
	if (r > 0)
		while (r--)
			op_r(stack_a, A);
	else if (r < 0)
		while (r++)
			op_revr(stack_a, A);
}
