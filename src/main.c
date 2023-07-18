/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:32:59 by maroy             #+#    #+#             */
/*   Updated: 2023/07/14 15:27:42 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//malloc both stacks and initialize stack_a
static void	setup_stacks(t_stack ***stack_a, t_stack ***stack_b, int32_t argc,
				char **argv);
//print32_t error on stderr
static void	print32_t_error(void);

int32_t	main(int32_t argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (EXIT_SUCCESS);
	if (validate_input(argc, argv) == KO)
		print32_t_error();
	setup_stacks(&stack_a, &stack_b, argc, argv);
	if (is_sorted(*stack_a) == KO)
	{
		b_sort(stack_a, stack_b);
		while (is_sorted(*stack_a) == KO)
			op_revr(stack_a, A);
	}
	free_stack_and_exit(stack_a, stack_b, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static void	print32_t_error(void)
{
	write(2, "\033[1;31m ERROR\n", ft_strlen("\033[1;31m ERROR\n"));
	exit(EXIT_FAILURE);
}

static void	setup_stacks(t_stack ***stack_a, t_stack ***stack_b, int32_t argc,
		char **argv)
{
	*stack_a = malloc(sizeof(t_stack));
	if (*stack_a == NULL)
		free_stack_and_exit(*stack_a, *stack_b, EXIT_FAILURE);
	*stack_b = malloc(sizeof(t_stack));
	if (*stack_b == NULL)
		free_stack_and_exit(*stack_a, *stack_b, EXIT_FAILURE);
	**stack_a = NULL;
	**stack_b = NULL;
	if (initialize_stack(*stack_a, argc, argv) == KO)
		free_stack_and_exit(*stack_a, *stack_b, EXIT_FAILURE);
}
