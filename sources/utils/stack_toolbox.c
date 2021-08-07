/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_toolbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:59:14 by nachin            #+#    #+#             */
/*   Updated: 2021/08/07 19:24:39 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(int data, t_node **stack)
{
	t_node	*new_head;

	new_head = (t_node *)malloc(sizeof(t_node));
	new_head->data = data;
	new_head->next = (*stack);
	(*stack) = new_head;
}

void	pop(t_node **stack)
{
	t_node	*tmp;

	if ((*stack) != NULL)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
	}
	else
	{
		return ;
	}
}

int	is_stack_empty(t_node *stack)
{
	if (stack == NULL)
	{
		return (1);
	}
	return (0);
}

int	stack_len(t_node *stack)
{
	int	i;

	i = 0;
	if (stack->next == NULL)
		return (1);
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	is_stack_sorted(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->next->data <= tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
