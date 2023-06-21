/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:03:17 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 20:02:07 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdbool.h>

int	get_array_length(char **array)
{
	int	length;

	length = 0;
	while (array[length] != NULL)
		length++;
	return (length);
}

t_stack	*get_node(int index, t_stack **stack)
{
	int		i;
	t_stack	*node;

	i = 1;
	node = *stack;
	while (node != NULL && i < index)
	{
		i++;
		node = node->next;
	}
	return (node);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size ++;
	}
	return (size);
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

int	get_nb_rotate(t_stack **stack, int index)
{
	int	lstsize;
	int	nb_rotate;

	nb_rotate = 0;
	lstsize = get_stack_size(*stack);
	if (lstsize / 2 >= index)
		nb_rotate = (index - 1);
	else if (lstsize / 2 < index)
		nb_rotate = (lstsize - index + 1) * -1;
	if (lstsize == 5 && index == 3)
		nb_rotate = 2;
	return (nb_rotate);
}

int	get_min_number_index(t_stack **stack)
{
	t_stack	*node;
	int		min;
	int		index;
	int		i;

	index = 0;
	min = INT_MAX;
	i = 1;
	node = *stack;
	while (node != NULL)
	{
		if (node->content <= min)
		{
			min = node->content;
			index = i;
		}
		i++;
		node = node->next;
	}
	return (index);
}

int	get_max_number_index(t_stack **stack)
{
	t_stack	*node;
	int		max;
	int		index;
	int		i;

	index = 0;
	max = INT_MIN;
	i = 1;
	node = *stack;
	while (node != NULL)
	{
		if (node->content >= max)
		{
			max = node->content;
			index = i;
		}
		i++;
		node = node->next;
	}
	return (index);
}

int	is_number_min(int number, t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node != NULL)
	{
		if (number > node->content)
			return (KO);
		node = node->next;
	}
	return (OK);
}

int	find_sort_index(t_stack **stack, int number)
{
	t_stack	*node;
	int		min;
	int		index;
	int		i;

	if (is_number_min(number, stack))
		return (get_max_number_index(stack));
	index = 0;
	min = INT_MIN;
	i = 1;
	node = *stack;
	while (node != NULL)
	{
		if (number > node->content && (node->content >= min))
		{
			min = node->content;
			index = i;
		}
		i++;
		node = node->next;
	}
	return (index);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*current_node;
	int		current_value;

	current_node = *stack;
	current_value = current_node->content;
	while (current_node != NULL)
	{
		if (current_value > current_node->content)
			return (KO);
		current_value = current_node->content;
		current_node = current_node->next;
	}
	return (OK);
}
