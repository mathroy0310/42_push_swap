/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:52:26 by maroy             #+#    #+#             */
/*   Updated: 2023/07/13 18:59:21 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	delete_content(int32_t *content)
{
	free(content);
}

void	free_string_array(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_stack_and_exit(t_stack **stack_a, t_stack **stack_b,
		int32_t e_code)
{
	if (stack_a != NULL)
	{
		ft_lstclear(stack_a, delete_content);
		free(stack_a);
	}
	if (stack_b != NULL)
	{
		ft_lstclear(stack_b, delete_content);
		free(stack_b);
	}
	exit(e_code);
}
