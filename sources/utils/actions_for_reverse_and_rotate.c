/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_for_reverse_and_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:27:44 by nachin            #+#    #+#             */
/*   Updated: 2021/08/12 21:22:45 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_action(t_node **stack_reversed)
{
	t_node	*tmp;
	t_node	*penultimate;

	if (is_stack_empty((*stack_reversed)))
		return ;

	if ((*stack_reversed)->next == NULL)
		return ;


	tmp = (*stack_reversed);
	penultimate = NULL;
	while (tmp->next != NULL)
	{
		penultimate = tmp;
		tmp = tmp->next;
	}

	t_node *tmp_last_node = tmp;
	t_node *tmp_first_node = (*stack_reversed);
	tmp_last_node->next = tmp_first_node;
	(*stack_reversed) = tmp_last_node;

	penultimate->next = NULL;

}

void	get_reverse(char *cmd, t_node **stack_a, t_node **stack_b)
{

	if (ft_strncmp(cmd, "rra", 4) == 0)
	{
		reverse_action(stack_a);
		write(1, "rra\n", 4);
	}
	else if (ft_strncmp(cmd, "rrb", 4) == 0)
	{
		reverse_action(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (ft_strncmp(cmd, "rrr", 4) == 0)
	{
		reverse_action(stack_a);
		reverse_action(stack_b);
		write(1, "rrr\n", 4);
	}
}

void	rotate_action(t_node **stack_rotated)
{
	t_node	*tmp;
	t_node	*previous_head;

	if (is_stack_empty((*stack_rotated)) || (*stack_rotated)->next == NULL)
		return ;
	previous_head = (*stack_rotated);
	tmp = (*stack_rotated);
	// new_node = (t_node *)malloc(sizeof(t_node));
	// new_node->data = (*stack_rotated)->data;
	pop(stack_rotated);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = previous_head;
	previous_head->next = NULL;

}

void	get_rotate(char *cmd, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(cmd, "ra", 3) == 0)
	{
		rotate_action(stack_a);
		write(1, "ra\n", 3);
	}
	else if (ft_strncmp(cmd, "rb", 3) == 0)
	{
		rotate_action(stack_b);
		write(1, "rb\n", 3);
	}
	else if (ft_strncmp(cmd, "rr", 3) == 0)
	{
		rotate_action(stack_a);
		rotate_action(stack_b);
		write(1, "rr\n", 3);
	}
}
