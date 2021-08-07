/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:10:28 by nachin            #+#    #+#             */
/*   Updated: 2021/08/06 16:42:20 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorting_needed(t_node **stack, int total_nb)
{
	if (total_nb == 1)
		return (0);
	else if (total_nb == 2)
		two_nb_sort(stack, total_nb);
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

int	main(int argc, char **argv)
{
	int			i;
	char		*list_nb;
	int			total_nb;
	t_node		*stack;

	stack = NULL;
	total_nb = 0;
	if (argc == 1)
		error_and_exit();
	else if (argc == 2)
	{
		list_nb = argv[1];
		stack = build_stack(list_nb, &total_nb);
		if (stack->next == NULL)
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
		stack = build_stack(list_nb, &total_nb);
	}
	if (is_sorting_needed(&stack, total_nb))
		return (0);
	return (0);
}
