/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:09:21 by nachin            #+#    #+#             */
/*   Updated: 2021/08/08 12:02:18 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Radix sort algorithm adapted for push_swap:
 * 1. Handling numbers in base 2 which allows me to use only 2 boxes to sort :
 * 	- No need to convert in binary. Using % 2 to get the last digit in binary
 * 	- Using bitwise operator >> to shift all the bits to the right
 * 	- Break out of the while loop when the ith-digit of the biggest number is 0
 * 2. Handling negatives numbers by subtracting the value of
 * the smallest negative number from all the numbers in the stack.
*/
void	radix_sort(t_node **stack_a, int total_node)
{
	t_node				*stack_b;
	t_sorting_toolbox	the;

	init_struct_sorting_toolbox(&the, total_node, (*stack_a));
	the.biggest_nb_value = (*stack_a)->data;
	stack_b = NULL;
	find_smallest_nb(*stack_a, &the.smallest_nb_value, &the.smallest_nb_pos);
	if (the.smallest_nb_value < 0)
		make_positive_number(stack_a, the.smallest_nb_value);
	while (1)
	{
		the.i_node = 0;
		checking_all_nodes(&the, stack_a, &stack_b);
		while (stack_b != NULL)
			get_push("pa", stack_a, & stack_b);
		the.ith_digit_pos++;
		if (the.biggest_nb_value >> the.ith_digit_pos == 0)
			break ;
	}
}

/**
 * A loop that checks all the nodes of stack_a in order to check the value
 * of ith digit.
 * If it's even (i.e. equal to zero) then I push the number to stack b
*/
void	checking_all_nodes(t_sorting_toolbox *a, t_node **s_a, t_node **s_b)
{
	while (a->i_node < a->total_node)
	{
		a->current_node_value = (*s_a)->data;
		if (a->current_node_value > a->biggest_nb_value)
			a->biggest_nb_value = a->current_node_value;
		a->ith_digit_value = (a->current_node_value >> a->ith_digit_pos) % 2;
		if (a->ith_digit_value == 1)
			get_rotate("ra", s_a, s_b);
		else
			get_push("pb", s_a, s_b);
		a->i_node++;
	}
}

void	make_positive_number(t_node **stack_a, int smallest_nb_value)
{
	t_node	*tmp;

	tmp = (*stack_a);
	while (tmp != NULL)
	{
		tmp->data = tmp->data - smallest_nb_value;
		tmp = tmp->next;
	}
}
