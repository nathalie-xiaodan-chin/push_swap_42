/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:16:33 by nachin            #+#    #+#             */
/*   Updated: 2021/08/05 13:22:27 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_sa_and_rra(t_node **stack_a, t_node **stack_b)
{
	get_swap("sa", stack_a, stack_b);
	get_reverse("rra", stack_a, stack_b);
}

void	get_sa_and_ra(t_node **stack_a, t_node **stack_b)
{
	get_swap("sa", stack_a, stack_b);
	get_rotate("ra", stack_a, stack_b);
}
