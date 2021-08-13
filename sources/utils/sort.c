/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:38:07 by nachin            #+#    #+#             */
/*   Updated: 2021/08/13 17:24:20 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	find_smallest_nb(t_node *list, int *s_value, int *s_pos)
{
	t_node	*tmp;
	int		smallest_value;
	int		smallest_pos;

	tmp = list;
	smallest_value = list->data;
	smallest_pos = 0;
	while (tmp != NULL)
	{
		if (tmp->data < smallest_value)
		{
			smallest_value = tmp->data;
			smallest_pos++;
		}
		tmp = tmp->next;
	}
	*s_value = smallest_value;
	*s_pos = find_pos(list, smallest_value);
}

int		is_all_stack_negative(t_node *stack)
{
	int i;
	i = 0;
	int max = stack_len(stack);
	while (i < max)
	{
		if (stack->data >= 0)
			return (0);
		i++;
		stack = stack->next;
	}
	return(1);
}

void	find_biggest_nb(t_node *list, int *b_value, int *b_pos)
{
	int		biggest_nb_value;
	int		biggest_nb_pos;
	t_node	*tmp;

	biggest_nb_value = list->data;
	biggest_nb_pos = 0;
	tmp = NULL;
	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->data > biggest_nb_value)
		{
			biggest_nb_value = tmp->data;
			biggest_nb_pos++;
		}
		tmp = tmp->next;
	}
	*b_value = biggest_nb_value;
	*b_pos = find_pos(list, biggest_nb_value);
}

void	sorting_five(t_node **stack_a, t_node **stack_b)
{
	int	biggest_nb_value;
	int	biggest_nb_pos;
	int	smallest_nb_value;
	int	smallest_nb_pos;

	find_biggest_nb((*stack_a), &biggest_nb_value, &biggest_nb_pos);

	// printf("%d| biggest nb value %d and biggest nb pos %d\n", __LINE__, biggest_nb_value, biggest_nb_pos);
	// biggest_nb_pos = 0 ;
	// biggest_nb_value = -35;

	five_nb_sort(stack_a, stack_b, biggest_nb_pos);

	// printf("%d| biggest nb value %d and biggest nb pos %d\n", __LINE__, biggest_nb_value, biggest_nb_pos);

	find_smallest_nb((*stack_a), &smallest_nb_value, &smallest_nb_pos);
	// printf("%d| smallest nb value %d and smallest nb pos %d\n", __LINE__, smallest_nb_value, smallest_nb_pos);

	four_nb_sort(stack_a, stack_b, smallest_nb_pos);

	three_nb_sort(stack_a);

	get_push("pa", stack_a, stack_b);
	get_push("pa", stack_a, stack_b);
	get_rotate("ra", stack_a, stack_b);
}

void	sorting_four(t_node **stack_a, t_node **stack_b)
{

	int	biggest_nb_value;
	int	biggest_nb_pos;
	int	smallest_nb_value;
	int	smallest_nb_pos;

	find_biggest_nb((*stack_a), &biggest_nb_value, &biggest_nb_pos);


	find_smallest_nb((*stack_a), &smallest_nb_value, &smallest_nb_pos);
	// display_stack((*stack_a));

	four_nb_sort(stack_a, stack_b, smallest_nb_pos);
	three_nb_sort(stack_a);

	get_push("pa", stack_a, stack_b);

}
