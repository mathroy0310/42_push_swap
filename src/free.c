/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:52:26 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 19:18:17 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	delete_content(int *content)
{
	free(content);
}

void	free_string_array(char **tab)
{
	if (*tab)
	{
		free(tab);
		tab++;
	}
}

void	free_stack_and_exit(t_stack **stack_a, t_stack **stack_b, int exit_code)
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
	exit(exit_code);
}
