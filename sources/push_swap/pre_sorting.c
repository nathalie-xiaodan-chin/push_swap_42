/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:41:41 by nachin            #+#    #+#             */
/*   Updated: 2021/08/07 10:16:04 by nachin           ###   ########.fr       */
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

void	push_nb_of_chunk_to_b(t_node **stack_a, t_node **stack_b, \
		t_sorting_toolbox *the)
{
	int		chunk_nb;
	float	stack_divided_by_2;

	chunk_nb = the->chunk_min;
	stack_divided_by_2 = (float)the->total_node / 2;
	the->total_node = stack_len((*stack_a));
	the->i_pos = 0;
	the->min_distance_to_border = the->total_node;
	if (the->min_distance_to_border == the->total_node)
		return ;
	if (the->does_distance_refer_top)
		multiple_rotations_on_a(stack_a, "ra", the->min_distance_to_border);
	else
		multiple_rotations_on_a(stack_a, "rra", the->min_distance_to_border);
	get_push("pb", stack_a, stack_b);
}

void	compute_distance_for_pushing_nb_of_chunk_to_b(t_node **stack_a, \
		t_sorting_toolbox *the)
{
	t_node	*tmp;

	tmp = (*stack_a);
	while (tmp != NULL)
	{
		if (tmp->data >= the->chunk_min && tmp->data < the->chunk_max)
		{
			compute_number_closest_border(
				the->i_pos,
				the->total_node,
				&the->tmp_distance,
				&the->tmp_does_distance_refer_top);
			if (the->min_distance_to_border > the->tmp_distance)
			{
				the->min_distance_to_border = the->tmp_distance;
				the->does_distance_refer_top = the->tmp_does_distance_refer_top;
			}
		}
		the->i_pos++;
		tmp = tmp->next;
	}
}

void	push_chunk_nbs_to_b(t_node **sa, t_node **sb, t_sorting_toolbox *the)
{
	while (the->chunk_min < the->chunk_max)
	{
		push_nb_of_chunk_to_b(sa, sb, the);
		the->chunk_min++;
	}
}

/**
 * 1. For each chunk, compute the smallest and the biggest number of the chunk
 * 2. Push the remaining of the numbers from stack_a to stack_b
*/
void	move_nb_to_b_by_chunk(t_node **stack_a, t_node **stack_b, int interval)
{
	t_sorting_toolbox	the;
	t_node				*tmp;

	init_struct_sorting_toolbox(&the, 0);
	tmp = (*stack_a);
	the.chunk_range = interval / 5;
	find_biggest_and_smallest((*stack_a), &the.chunk_min, &the.chunk_max);
	the.chunk_max = the.chunk_min + the.chunk_range;
	while (the.i_chunk < the.n_chunk)
	{
		push_chunk_nbs_to_b(stack_a, stack_b, &the);
		the.chunk_min = the.chunk_min + the.chunk_range;
		the.chunk_max = the.chunk_max + the.chunk_range;
		the.i_chunk++;
	}
	the.total_node = stack_len((*stack_a));
	if (the.total_node != 1)
	{
		multiple_push_on_b(stack_a, stack_b, the.total_node - 1);
	}
}
