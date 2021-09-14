/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:37:31 by nachin            #+#    #+#             */
/*   Updated: 2021/09/13 15:48:01 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	is_duplicate_in_stack(t_node *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack;
	while (i->next != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->data == j->data)
			{
				return (1);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	is_empty(char *str)
{
	if (str == NULL || !ft_strncmp("", str, 1))
	{
		return (1);
	}
	return (0);
}
