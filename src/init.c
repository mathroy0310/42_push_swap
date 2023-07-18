/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:59:20 by maroy             #+#    #+#             */
/*   Updated: 2023/07/18 13:43:33 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// initialize the stack from the arguments, if theres more than one argument
static int8_t	initialize_stack_from_args(t_stack **stack, char **argv,
					int32_t argc);
// initialize the stack from a string, if theres only one argument
static int8_t	initialize_stack_from_str(t_stack **stack, char **argv);

int8_t	initialize_stack(t_stack **stack, int32_t argc, char **argv)
{
	if (argc > 2)
		if (initialize_stack_from_args(stack, argv, argc) == KO)
			return (KO);
	if (argc == 2)
		if (initialize_stack_from_str(stack, argv) == KO)
			return (KO);
	return (OK);
}

static int8_t	check_malloc(void *ptr, char **numbers)
{
	if (ptr == NULL)
	{
		free_string_array(numbers);
		return (KO);
	}
	return (OK);
}

static int8_t	initialize_stack_from_args(t_stack **stack, char **argv,
		int32_t argc)
{
	int32_t	i;
	int32_t	value;
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

static int8_t	initialize_stack_from_str(t_stack **stack, char **argv)
{
	t_stack	*new;
	char	**numbers;
	int32_t	i;
	int32_t	*value;

	numbers = ft_split(argv[1], ' ');
	if (numbers == NULL)
		return (KO);
	i = -1;
	while (numbers[++i] != NULL)
	{
		value = malloc(sizeof(int32_t));
		if (check_malloc(value, numbers) == KO)
			return (KO);
		*value = ft_atoi(numbers[i]);
		new = ft_lstnew(*value);
		free(value);
		if (check_malloc(new, numbers) == KO)
			return (KO);
		ft_lstadd_back(stack, new);
	}
	free_string_array(numbers);
	return (OK);
}
