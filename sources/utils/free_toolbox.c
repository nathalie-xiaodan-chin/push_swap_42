/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_toolbox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 12:06:06 by nachin            #+#    #+#             */
/*   Updated: 2021/08/08 12:06:46 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
