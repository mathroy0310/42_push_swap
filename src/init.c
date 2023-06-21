/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:59:20 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 19:18:38 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_malloc(void *ptr, char **numbers)
{
	if (ptr == NULL)
	{
		free_string_array(numbers);
		return (OK);
	}
	return (KO);
}

static int	initialize_stack_from_str(t_stack **stack, char **argv)
{
	t_stack	*new;
	char	**numbers;
	int		i;
	int		*value;

	numbers = ft_split(argv[1], ' ');
	if (numbers == NULL)
		return (KO);
	i = -1;
	while (numbers[++i] != NULL)
	{
		value = malloc(sizeof(int));
		if (check_malloc(value, numbers))
			return (KO);
		*value = ft_atoi(numbers[i]);
		new = ft_lstnew(*value);
		if (check_malloc(new, numbers))
			return (KO);
		ft_lstadd_back(stack, new);
	}
	free_string_array(numbers);
	return (OK);
}

static int	initialize_stack_from_args(t_stack **stack, char **argv, int argc)
{
	int		i;
	int		value;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new = ft_lstnew(value);
		if (new == NULL)
			return (KO);
		ft_lstadd_back(stack, new);
		i++;
	}
	return (OK);
}

int	initialize_stack(t_stack **stack, int argc, char **argv)
{
	if (argc > 2)
		if (!initialize_stack_from_args(stack, argv, argc))
			return (KO);
	if (argc == 2)
		if (!initialize_stack_from_str(stack, argv))
			return (KO);
	return (OK);
}
