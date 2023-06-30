/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:56:14 by maroy             #+#    #+#             */
/*   Updated: 2023/06/26 20:05:21 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//checks if the numbers are valid, returns OK if true, KO if false
static int32_t	is_valid_numbers(char **numbers, int32_t size);
//checks if the numbers are duplicates, returns OK if true, KO if false
static int32_t	has_duplicate_values(char **argv);
//checks if the string is a valid int32_tegers, returns OK if true, KO if false
static int32_t	is_valid_int32_teger(char *str);

int32_t	validate_input(int32_t argc, char **argv)
{
	char	**split_num;
	int32_t	exit_status;

	if (argc == 1)
		return (KO);
	if (argc == 2)
	{
		split_num = ft_split(argv[1], ' ');
		if (split_num == NULL)
			return (OK);
		if (*split_num == NULL)
		{
			free_string_array(split_num);
			return (KO);
		}
		exit_status = is_valid_numbers(split_num, get_array_length(split_num));
		free_string_array(split_num);
		return (exit_status);
	}
	return (is_valid_numbers(argv + 1, argc - 1));
}

static int32_t	is_valid_numbers(char **numbers, int32_t size)
{
	int32_t	i;

	i = 0;
	if (has_duplicate_values(numbers) == KO)
		return (KO);
	while (i < size)
	{
		if (is_valid_int32_teger(numbers[i]) == KO)
			return (KO);
		i++;
	}
	return (OK);
}

static int32_t	has_duplicate_values(char **argv)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[j] != NULL)
		{
			if (i != j && ft_strcmp(argv[i], argv[j]) == 0)
				return (KO);
			j++;
		}
		i++;
	}
	return (OK);
}

static int32_t	is_valid_int32_teger(char *str)
{
	int32_t	i;
	long	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == '-' && i == 0) && ft_isdigit(str[i]) == KO)
			return (KO);
		if (str[i] == '-' && ft_isdigit(str[i + 1]) == KO)
			return (KO);
		i++;
	}
	num = ft_atol(str);
	if (num >= INT_MIN && num <= INT_MAX && i <= 11)
		return (OK);
	else
		return (KO);
}
