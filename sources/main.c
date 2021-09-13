/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:10:28 by nachin            #+#    #+#             */
/*   Updated: 2021/09/13 11:05:08 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sorting_stack(t_node **stack, int total_nb)
{
	if (total_nb ==0){
		return 0;
	}
	if (total_nb == 1)
		return (0);
	else if (total_nb == 2)
		two_nb_sort(stack);
	else if (total_nb == 3)
		three_nb_sort(stack);
	else if (total_nb <= 5)
		five_or_four_nb_sort(stack, total_nb);
	else if (total_nb <= 100)
		insertion_sort(stack, total_nb);
	else if (total_nb > 100)

		radix_sort(stack, total_nb);
	else
		return (0);
	return (1);
}

char* concat_argv_to_str(int	argc, char	**argv){
	char	*list_nb;

	int i;
	char * tmp1;
	char * tmp2;

	list_nb  = "";

	i = 1;
	while (i < argc)
	{
		tmp1 = ft_strjoin(list_nb, argv[i]);
		if (i >1)//on free tmp2 de l iteration d avant
			free(tmp2);
		if (i < argc - 1){
			tmp2 = ft_strjoin(tmp1, " ");
			free(tmp1);
			list_nb = tmp2;
		}
		else
			list_nb = tmp1;
		i++;
	}
	return (list_nb);
}

void	processing_push_swap_args(int argc, char **argv, t_node **stack, \
		int *total_nb)
{

	char	*list_nb;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "", 1) == 0)
			exit(0);
		list_nb = argv[1];
		(*stack) = build_stack(list_nb, total_nb);
		// if ((*stack)->next == NULL)
		// 	exit(1);
		if ((*stack)->next == NULL)
			return ;
	}
	else //if (argc > 2)
	{
		list_nb = concat_argv_to_str(argc, argv);
		(*stack) = build_stack(list_nb, total_nb);
		free(list_nb);
	}
}

int	main(int argc, char **argv)
{
	int			total_nb;
	t_node		*stack;

	stack = NULL;
	total_nb = 0;
	processing_push_swap_args(argc, argv, &stack, &total_nb);
	if (!is_stack_sorted(stack))
	{
		sorting_stack(&stack, total_nb);
	}
	free_stack(stack);
	return (0);
}
