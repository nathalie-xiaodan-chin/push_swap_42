/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_toolbox_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:02:07 by nachin            #+#    #+#             */
/*   Updated: 2021/08/07 10:02:16 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_struct_sorting_toolbox(t_sorting_toolbox *init, int total_node)
{
	init->smallest_nb_value = 0;
	init->smallest_nb_pos = 0;
	init->ith_digit_pos = 0;
	init->ith_digit_value = 0;
	init->biggest_nb_value = 0;
	init->current_node_value = 0;
	init->i_node = 0;
	init->total_node = total_node;
	init->i_chunk = 0;
	init->n_chunk = 5;
}

int	compute_chunk_interval(int smallest_nb, int biggest_nb)
{
	return (biggest_nb - smallest_nb);
}

void	find_biggest_and_smallest(t_node *list, int *min, int *max)
{
	t_node	*tmp;
	int		min_value;
	int		max_value;

	tmp = list;
	min_value = list->data;
	max_value = list->data;
	while (tmp != NULL)
	{
		if (tmp->data < min_value)
		{
			min_value = tmp->data;
		}
		if (tmp->data > max_value)
		{
			max_value = tmp->data;
		}
		tmp = tmp->next;
	}
	*min = min_value;
	*max = max_value;
}

void	multiple_push_on_b(t_node **s_a, t_node **s_b, int number_of_time)
{
	int	i;

	i = 0;
	while (i < number_of_time)
	{
		push_action(s_a, s_b);
		write(1, "pb\n", 3);
		i++;
	}
}
