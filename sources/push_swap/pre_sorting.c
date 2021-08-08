/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:41:41 by nachin            #+#    #+#             */
/*   Updated: 2021/08/08 00:50:25 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Push numbers from stack_a to stack_b by pre-sorting them :
 * - Find the range from the smallest to the biggest number ;
 * - Divide the range into five chunks ;
 * - Find the closet number from the chunk in the extremities (top or bottom) ;
 * - Push this number to stack_b.
 * - Repeat until all numbers are on stack_b.
*/
void	pre_sorting_stack(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	max;
	int	chunk_interval;

	find_biggest_and_smallest((*stack_a), &min, &max);
	chunk_interval = compute_chunk_interval(min, max);
	move_nb_to_b_by_chunk(stack_a, stack_b, chunk_interval);
}

void	push_chunk_numbers_to_b(t_node **stack_a, t_node **stack_b, \
		int chunk_min, int chunk_max)
{
	while (chunk_min < chunk_max)
	{
		push_nb_of_chunk_to_b(stack_a, stack_b, chunk_min, chunk_max);
		chunk_min++;
	}
}

void	push_nb_of_chunk_to_b(t_node **stack_a, t_node **stack_b, \
		int chunk_min, int chunk_max)
{
	int		total_node;
	t_node	*tmp;
	int		i_pos;
	int		does_distance_refer_top;
	int		min_distance_to_border;
	int		tmp_distance;
	int		tmp_does_distance_refer_top;

	total_node = stack_len((*stack_a));
	tmp = (*stack_a);
	i_pos = 0;
	min_distance_to_border = total_node;
	while (tmp != NULL)
	{
		if (tmp->data >= chunk_min && tmp->data < chunk_max)
		{
			compute_number_closest_border(
				i_pos,
				total_node,
				&tmp_distance,
				&tmp_does_distance_refer_top);
			if (min_distance_to_border > tmp_distance)
			{
				min_distance_to_border = tmp_distance;
				does_distance_refer_top = tmp_does_distance_refer_top;
			}
		}
		i_pos ++;
		tmp = tmp->next;
	}
	if (min_distance_to_border == total_node)
	{
		return ;
	}
	if (does_distance_refer_top)
	{
		multiple_rotations_on_a(stack_a, "ra", min_distance_to_border);
	}
	else
	{
		multiple_rotations_on_a(stack_a, "rra", min_distance_to_border);
	}
	get_push("pb", stack_a, stack_b);
}

void	push_chunk_nbs_to_b(t_node **sa, t_node **sb, t_sorting_toolbox *the)
{
	while (the->chunk_min < the->chunk_max)
	{
		push_nb_of_chunk_to_b(sa, sb, the->chunk_min, the->chunk_max);
		the->chunk_min++;
	}
}

/**
 * 1. For each chunk, compute the smallest and the biggest number of the chunk
 * 2. Push the remaining of the numbers from stack_a to stack_b
*/
void	move_nb_to_b_by_chunk(t_node **stack_a, t_node **stack_b, int interval)
{
	int			i_chunk;
	int			n_chunk;
	int			chunk_min;
	int			chunk_max;
	int			total_node;
	t_node		*tmp;
	int			chunk_range;

	find_biggest_and_smallest((*stack_a), &chunk_min, &chunk_max);
	chunk_range = interval / 5;
	chunk_max = chunk_min + chunk_range;
	tmp = (*stack_a);
	n_chunk = 5;
	i_chunk = 0;
	while (i_chunk < n_chunk)
	{
		push_chunk_numbers_to_b(stack_a, stack_b, chunk_min, chunk_max);
		chunk_min = chunk_min + chunk_range;
		chunk_max = chunk_max + chunk_range;
		i_chunk++;
	}
	total_node = stack_len((*stack_a));
	if (total_node != 1)
	{
		multiple_push_on_b(stack_a, stack_b, total_node - 1);
	}
}
