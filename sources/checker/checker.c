/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:53:12 by nachin            #+#    #+#             */
/*   Updated: 2021/09/13 16:28:35 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	execute_instructions(char *instruction, t_node **stack_a, \
		t_node **stack_b)
{
	if (is_swap(instruction) == 1)
		swap_for_checker(instruction, stack_a, stack_b);
	else if (is_push(instruction) == 1)
		push_for_checker(instruction, stack_a, stack_b);
	else if (is_rotate(instruction) == 1)
		rotate_for_checker(instruction, stack_a, stack_b);
	else if (is_reverse(instruction) == 1)
		reverse_for_checker(instruction, stack_a, stack_b);
	else
	{
		error_and_exit();
	}
}

void	check_instruction_errors(char *instruction)
{
	if ((ft_strlen(instruction) == 1) || \
		(ft_strncmp(instruction, "sa", 3) == 1 && \
		ft_strncmp(instruction, "sb", 3) == 1 && \
		ft_strncmp(instruction, "ss", 3) == 1 && \
		ft_strncmp(instruction, "pa", 3) == 1 && \
		ft_strncmp(instruction, "pb", 3) == 1 && \
		ft_strncmp(instruction, "ra", 3) == 1 && \
		ft_strncmp(instruction, "rb", 3) == 1 && \
		ft_strncmp(instruction, "rr", 3) == 1 && \
		ft_strncmp(instruction, "rra", 4) == 1 && \
		ft_strncmp(instruction, "rrb", 4) == 1 && \
		ft_strncmp(instruction, "rrr", 4) == 1))
		error_and_exit();
}

void	checker(t_node **stack_a, t_node **stack_b)
{
	char	*instruction;

	instruction = NULL;
	get_next_line(0, &instruction);
	check_instruction_errors(instruction);
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
		exit(0);
	else if (argc == 2)
	{
		list_nb = argv[1];
		(*stack_a) = build_stack(list_nb, &total_nb);
		if ((*stack_a)->next == NULL)
			print_ok();
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
	if (argc == 2 && (ft_strncmp(argv[1], "", 1) == 0))
		exit(0);
	processing_checker_args(argc, argv, &stack_a, total_nb);
	total_nb = (stack_len(stack_a));
	checker(&stack_a, &stack_b);
	if (is_stack_sorted(stack_a) && total_nb == stack_len(stack_a))
	{
		ft_putendl_fd("OK", 1);
		return (0);
	}
	else
	{
		ft_putendl_fd("KO", 1);
		return (1);
	}
}
