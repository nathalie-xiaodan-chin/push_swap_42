/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_four_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:54:08 by nachin            #+#    #+#             */
/*   Updated: 2021/08/05 11:09:12 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_pos(t_node *list, int value)
{
	t_node	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->data != value)
		{
			tmp = tmp->next;
			i++;
		}
		else
			break ;
	}
	return (i);
}

void	four_nb_sort(t_node **stack_a, t_node**stack_b, int i)
{
	if (i == 0)
	{
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 1)
	{
		get_rotate("ra", stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 2)
	{
		get_rotate("ra", stack_a, stack_b);
		get_rotate("ra", stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 3)
	{
		get_reverse("rra", stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
}

void	five_nb_sort(t_node **stack_a, t_node**stack_b, int i)
{
	if (i == 0)
		get_push("pb", stack_a, stack_b);
	else if (i == 1)
	{
		get_rotate("ra", stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 2)
	{
		get_rotate("ra", stack_a, stack_b);
		get_rotate("ra", stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 3)
	{
		get_reverse("rra", stack_a, stack_b);
		get_reverse("rra", stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 4)
	{
		get_reverse("rra", stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
}

void	five_or_four_nb_sort(t_node **stack_a, int count)
{
	t_node	*stack_b;
	int		smallest_nb_value;
	int		smallest_nb_pos;
	int		biggest_nb_value;
	int		biggest_nb_pos;

	stack_b = NULL;
	if (count == 4)
	{
		sorting_four(stack_a, &stack_b);
	}
	else if (count == 5)
	{
		sorting_five(stack_a, &stack_b);
	}
}
