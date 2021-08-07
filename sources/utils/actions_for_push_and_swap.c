/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_for_push_and_swap.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:26:55 by nachin            #+#    #+#             */
/*   Updated: 2021/08/05 13:27:05 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_action(t_node **stack_pushed, t_node **stack_received)
{
	int	tmp;

	if (is_stack_empty((*stack_pushed)))
		return ;
	tmp = (*stack_pushed)->data;
	pop(stack_pushed);
	push(tmp, stack_received);
}

void	get_push(char *cmd, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(cmd, "pa", 3) == 0)
	{
		push_action(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
	else if (ft_strncmp(cmd, "pb", 3) == 0)
	{
		push_action(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
}

void	swap_action(t_node **stack)
{
	int	tmp_first;
	int	tmp_second;

	if (is_stack_empty((*stack)))
		return ;
	if ((*stack)->next == NULL)
		return ;
	tmp_second = (*stack)->data;
	pop(stack);
	tmp_first = (*stack)->data;
	pop(stack);
	push(tmp_second, stack);
	push(tmp_first, stack);
}

void	get_swap(char *cmd, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(cmd, "sa", 3) == 0)
	{
		swap_action(stack_a);
		write(1, "sa\n", 3);
	}
	else if (ft_strncmp(cmd, "sb", 3) == 0)
	{
		swap_action(stack_b);
		write(1, "sb\n", 3);
	}
	else if (ft_strncmp(cmd, "ss", 3) == 0)
	{
		swap_action(stack_a);
		swap_action(stack_b);
		write(1, "ss\n", 3);
	}
}
