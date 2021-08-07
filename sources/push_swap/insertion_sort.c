/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:31:18 by nachin            #+#    #+#             */
/*   Updated: 2021/08/07 10:05:22 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Insertion sort algorithm adapted for push_swap:
 * - Pre-sorting algorithm that allows me to push numbers from stack_a to
 * stack_b by chunk of five ;
 * - Then, push pre-sorted numbers from stack_b to stack_a by finding the
 * smallest number above the current one in stack_a and rotate it to the top.
 * - Finally, push the number from stack_b to stack_a
*/
int	insertion_sort(t_node **stack_a, int total_nb)
{
	t_node	*stack_b;
	t_node	*tmp_a;
	int		i;

	stack_b = NULL;
	tmp_a = (*stack_a);
	i = total_nb;
	pre_sorting_stack(stack_a, &stack_b);
	total_nb = stack_len(*stack_a);
	while (stack_b != NULL)
	{
		insert_nb_from_b_to_a(stack_a, &stack_b, &total_nb);
	}
	total_nb = stack_len(*stack_a);
	move_min_value_to_top(stack_a, total_nb);
	return (0);
}

int	find_smallest_nb_above_x(t_node *stack, int x, int *total_node)
{
	int	b_pos;
	int	smallest;
	int	i_smallest;
	int	i_node;

	i_smallest = 0;
	i_node = 0;
	find_biggest_nb(stack, &smallest, &b_pos);
	while (stack != NULL)
	{
		if (stack->data <= smallest && stack->data > x)
		{
			smallest = stack->data;
			i_smallest = i_node;
		}
		i_node++;
		stack = stack->next;
	}
	*total_node = i_node - 1;
	return (i_smallest);
}

int	insert_nb_in_extremities(t_node **stack_a, t_node **stack_b, int total_nb)
{
	move_min_value_to_top(stack_a, total_nb);
	if ((*stack_b)->data < (*stack_a)->data)
	{
		get_push("pa", stack_a, stack_b);
		return (0);
	}
	else if (((*stack_b)->data > get_last_value((*stack_a))))
	{
		get_push("pa", stack_a, stack_b);
		get_rotate("ra", stack_a, stack_b);
		return (0);
	}
	return (0);
}

void	insert_nb_in_middles(t_node**stack_a, t_node **stack_b)
{
	int	i;
	int	total_node;
	int	pos;

	i = 0;
	pos = find_smallest_nb_above_x((*stack_a), (*stack_b)->data, &total_node);
	rotate_number_to_top(stack_a, pos, total_node);
	get_push("pa", stack_a, stack_b);
}

void	insert_nb_from_b_to_a(t_node **stack_a, t_node **stack_b, int *total_nb)
{
	int	number_to_insert;
	int	min;
	int	max;

	number_to_insert = (*stack_b)->data;
	find_biggest_and_smallest((*stack_a), &min, &max);
	if (number_to_insert < min || number_to_insert > max)
		insert_nb_in_extremities(stack_a, stack_b, *total_nb);
	else
		insert_nb_in_middles(stack_a, stack_b);
	*total_nb = *total_nb + 1;
}
