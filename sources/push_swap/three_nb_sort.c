/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nb_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:53:00 by nachin            #+#    #+#             */
/*   Updated: 2021/08/08 11:49:16 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	two_nb_sort(t_node **stack_a)
{
	int		v1;
	int		v2;
	t_node	*stack_b;

	stack_b = NULL;
	v1 = (*stack_a)->data;
	v2 = (*stack_a)->next->data;
	if (v2 < v1)
	{
		get_rotate("ra", stack_a, &stack_b);
	}
}

void	three_nb_sort(t_node **stack_a)
{
	int			a;
	int			b;
	int			c;
	t_node		*tmp;
	t_node		*stack_b;

	tmp = (*stack_a);
	stack_b = NULL;
	a = tmp->data;
	tmp = tmp->next;
	b = tmp->data;
	tmp = tmp->next;
	c = tmp->data;
	if (a > b && b < c && c > a)
		get_swap("sa", stack_a, &stack_b);
	else if (a > b && b > c && c < a)
		get_sa_and_rra(stack_a, &stack_b);
	else if (a > b && b < c && c < a)
		get_rotate("ra", stack_a, &stack_b);
	else if (a < b && b > c && c > a)
		get_sa_and_ra(stack_a, &stack_b);
	else if (a < b && b > c && c < a)
		get_reverse("rra", stack_a, &stack_b);
}
