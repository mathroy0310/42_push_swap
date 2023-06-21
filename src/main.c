/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:32:59 by maroy             #+#    #+#             */
/*   Updated: 2023/06/20 20:19:59 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (validate_input(argc, argv) == KO)
	{
		write(2, "\033[1;31m ERROR\n", ft_strlen("\033[1;31m ERROR\n"));
		return (EXIT_FAILURE);
	}
	stack_a = malloc(sizeof(t_stack));
	if (stack_a == NULL)
		free_stack_and_exit(stack_a, stack_b, EXIT_FAILURE);
	stack_b = malloc(sizeof(t_stack));
	if (stack_b == NULL)
		free_stack_and_exit(stack_a, stack_b, EXIT_FAILURE);
	*stack_a = NULL;
	*stack_b = NULL;
	if (initialize_stack(stack_a, argc, argv) == KO)
		free_stack_and_exit(stack_a, stack_b, EXIT_FAILURE);
	if (is_sorted(stack_a) == KO)
	{
		algo(stack_a, stack_b);
		while (is_sorted(stack_a) == KO)
		 	op_revr(stack_a, A);
	}
	free_stack_and_exit(stack_a, stack_b, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
