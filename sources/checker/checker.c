/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:53:12 by nachin            #+#    #+#             */
/*   Updated: 2021/08/13 16:31:13 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	execute_instructions(char *instruction, t_node **stack_a, \
		t_node **stack_b)
{
	if (ft_strlen(instruction) == 1)
	{
		// printf("invalid instruction: %s\n", instruction);
		exit(1);
	}
	else if (is_swap(instruction) == 1)
		swap_for_checker(instruction, stack_a, stack_b);
	else if (is_push(instruction) == 1)
		push_for_checker(instruction, stack_a, stack_b);
	else if (is_rotate(instruction) == 1)
		rotate_for_checker(instruction, stack_a, stack_b);
	else if (is_reverse(instruction) == 1)
		reverse_for_checker(instruction, stack_a, stack_b);
	else
	{
		printf("invalid instruction: %s\n", instruction);
		exit(1);
	}
}

void	checker(t_node **stack_a, t_node **stack_b)
{
	char	*instruction;

	instruction = NULL;
	get_next_line(0, &instruction);
	if (ft_strlen(instruction) == 1)
	{
		exit(1);
	}
	while (ft_strlen(instruction) > 1)
	{
		execute_instructions(instruction, stack_a, stack_b);
		get_next_line(0, &instruction);
		if (ft_strlen(instruction) == 1)
		{
			exit(1);
		}
	}
}

void	processing_checker_args(int argc, char **argv, t_node **stack_a, \
		int total_nb)
{
	int			i;
	char		*list_nb;

	if (argc == 1)
		error_and_exit();
	else if (argc == 2)
	{
		list_nb = argv[1];
		(*stack_a) = build_stack(list_nb, &total_nb);
		if ((*stack_a)->next == NULL)
			exit(1);
	}
	else if (argc > 2)
	{
		i = 1;
		list_nb = "";
		while (i != argc - 1)
		{
			list_nb = ft_strjoin(list_nb, argv[i]);
			list_nb = ft_strjoin(list_nb, " ");
			i++;
		}
		list_nb = ft_strjoin(list_nb, argv[i]);
		(*stack_a) = build_stack(list_nb, &total_nb);
	}
}

int	main(int argc, char **argv)
{
	int			total_nb;
	t_node		*stack_a;
	t_node		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	total_nb = 0;
	processing_checker_args(argc, argv, &stack_a, total_nb);
	total_nb = (stack_len(stack_a));
	checker(&stack_a, &stack_b);
	if (is_stack_sorted(stack_a) && total_nb == stack_len(stack_a))
	{
		write(1, "OK\n", 3);
		return (0);
	}
	else
	{
		write(1, "KO\n", 3);
		return (1);
	}
}
