/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:19:51 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 20:20:40 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_nb_rotate(t_stack **stack, int index)
{
	int	stack_size;
	int	nb_rotate;

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

void rotate_stack_to_find_sort(t_stack **stack_a, t_stack **stack_b)
{
    int index;
    int r;

	index = find_sort_index(stack_a, (*stack_b)->content) + 1;
    r = get_nb_rotate(stack_a, index);

    if (r > 0)
        while (r--)
            op_r(stack_a, A);
    else if (r < 0)
        while (r++)
    		op_revr(stack_a, A);
}

void rotate_stack_to_find_min(t_stack **stack_a)
{
    int min_index;
    int r;

    min_index = get_min_number_index(stack_a);
    r = get_nb_rotate(stack_a, min_index);

    if (r > 0)
        while (r--)
            op_r(stack_a, A);
    else if (r < 0)
        while (r++)
    		op_revr(stack_a, A);
}

