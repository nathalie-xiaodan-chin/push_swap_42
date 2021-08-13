/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:10:28 by nachin            #+#    #+#             */
/*   Updated: 2021/08/13 17:34:38 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sorting_stack(t_node **stack, int total_nb)
{
	if (total_nb == 1)
		return (0);
	else if (total_nb == 2)
		two_nb_sort(stack);
	else if (total_nb == 3)
		three_nb_sort(stack);
	else if (total_nb <= 5)
	{
		five_or_four_nb_sort(stack, total_nb);
	}
	else if (total_nb <= 100)
		insertion_sort(stack, total_nb);
	else if (total_nb > 100)
		radix_sort(stack, total_nb);
	else
		return (0);
	return (1);
}

void	processing_push_swap_args(int argc, char **argv, t_node **stack, \
		int *total_nb)
{
	int			i;
	char		*list_nb;

	if (argc == 1)
		error_and_exit();
	else if (argc == 2)
	{
		list_nb = argv[1];
		(*stack) = build_stack(list_nb, total_nb);
		if ((*stack)->next == NULL)
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
		(*stack) = build_stack(list_nb, total_nb);
	}
}

int	main(int argc, char **argv)
{

	int			total_nb;
	t_node		*stack;

	stack = NULL;
	total_nb = 0;
	processing_push_swap_args(argc, argv, &stack, &total_nb);
	//if (is_sorting_needed(&stack, total_nb))
	//	return (0);
	sorting_stack(&stack, total_nb);
	// display_stack(stack);

	free_stack(stack);
	//char *test = malloc(sizeof(char) * 22);
	//test[1] = 'q';
	// system("sudo leaks a.out");
	// while (1)
	// {
	// 	printf("leaks\n");
	// }
	return (0);
}

// int	main(int argc, char **argv)
// {

// 	t_node		*stack_a;
// 	t_node		*stack_b;

// 	stack_a = build_stack("1 2 3", 0);
// 	stack_b = build_stack("4", 0);

// 	push_action(&stack_a, &stack_b);
// 	return (0);
// }


