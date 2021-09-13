/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:41:41 by nachin            #+#    #+#             */
/*   Updated: 2021/09/13 11:02:02 by nachin           ###   ########.fr       */
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

/**
 * 1. For each chunk, compute the smallest and the biggest number of the chunk
 * 2. Push the remaining of the numbers from stack_a to stack_b
*/
void	move_nb_to_b_by_chunk(t_node **stack_a, t_node **stack_b, int interval)
{
	t_sorting_toolbox	t;
	int					i_chunk;
	int					n_chunk;
	int					total_node;

	n_chunk = 15;//11 better pour 100 nombres
	init_struct_sorting_toolbox(&t, 0, (*stack_a));
	find_biggest_and_smallest((*stack_a), &t.chunk_min, &t.chunk_max);
	t.chunk_range = interval / n_chunk;
	t.chunk_max = t.chunk_min + t.chunk_range;

	i_chunk = 0;
	while (i_chunk < n_chunk)
	{
		push_chunk_numbers_to_b(stack_a, stack_b, t.chunk_min, t.chunk_max);
		t.chunk_min = t.chunk_min + t.chunk_range;
		t.chunk_max = t.chunk_max + t.chunk_range;
		i_chunk++;
	}
	total_node = stack_len((*stack_a));
	if (total_node != 1)
	{
		multiple_push_on_b(stack_a, stack_b, total_node - 1);
	}
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
	t_sorting_toolbox	t;

	init_struct_sorting_toolbox(&t, stack_len((*stack_a)), (*stack_a));
	while (t.tmp != NULL)
	{
		if (t.tmp->data >= chunk_min && t.tmp->data < chunk_max)
		{
			compute_number_closest_border(t.i_pos, t.total_node, \
			&t.tmp_distance, &t.tmp_does_distance_refer_top);
			if (t.min_distance_to_border > t.tmp_distance)
			{
				t.min_distance_to_border = t.tmp_distance;
				t.does_distance_refer_top = t.tmp_does_distance_refer_top;
			}
		}
		t.i_pos ++;
		t.tmp = t.tmp->next;
	}
	if (t.min_distance_to_border == t.total_node)
		return ;
	if (t.does_distance_refer_top)
		multiple_rotations_on_a(stack_a, "ra", t.min_distance_to_border);
	else
		multiple_rotations_on_a(stack_a, "rra", t.min_distance_to_border);
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
