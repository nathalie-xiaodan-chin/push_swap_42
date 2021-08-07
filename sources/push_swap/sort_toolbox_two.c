/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_toolbox_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:02:12 by nachin            #+#    #+#             */
/*   Updated: 2021/08/07 10:05:56 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	compute_number_closest_border(int i_pos, int stack_size, \
		int *distance, int *refers_top)
{
	if ((float)i_pos < (float)stack_size / 2)
	{
		*distance = i_pos;
		*refers_top = 1;
	}
	else
	{
		*distance = stack_size - i_pos;
		*refers_top = 0;
	}
}

void	move_min_value_to_top(t_node **stack, int total_node)
{
	int		smallest_pos;
	int		smallest_value;
	float	stack_divided_by_2;
	int		n_move;

	smallest_pos = 0;
	smallest_value = 0;
	stack_divided_by_2 = (float)total_node / 2;
	find_smallest_nb((*stack), &smallest_value, &smallest_pos);
	if (smallest_pos < stack_divided_by_2)
	{
		multiple_rotations_on_a(stack, "ra", smallest_pos);
	}
	else
	{
		n_move = total_node - smallest_pos;
		multiple_rotations_on_a(stack, "rra", n_move);
	}
}

int	get_last_value(t_node *stack)
{
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack->data);
}

void	multiple_rotations_on_a(t_node **s_a, char *action, int number_of_time)
{
	int	i;

	i = 0;
	while (i < number_of_time)
	{
		if (ft_strncmp(action, "rra", 4) == 0)
		{
			reverse_action(s_a);
			write(1, "rra\n", 4);
		}
		else
		{
			rotate_action(s_a);
			write(1, "ra\n", 3);
		}
		i++;
	}
}

void	rotate_number_to_top(t_node **stack_a, int pos, int total_node)
{
	float	stack_divided_by_2;
	int		n_move;

	stack_divided_by_2 = (float)total_node / 2;
	total_node = total_node + 1;
	if (pos < stack_divided_by_2)
	{
		multiple_rotations_on_a(stack_a, "ra", pos);
	}
	else
	{
		n_move = total_node - pos;
		multiple_rotations_on_a(stack_a, "rra", n_move);
	}
}
