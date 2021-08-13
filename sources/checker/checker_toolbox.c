/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_toolbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:50:59 by nachin            #+#    #+#             */
/*   Updated: 2021/08/08 11:52:56 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_swap(char *cmd)
{
	if (ft_strncmp(cmd, "sa", 3) == 0 || ft_strncmp(cmd, "sb", 3) == 0 \
	|| ft_strncmp(cmd, "ss", 3) == 0)
		return (1);
	else
		return (0);
}

int	is_push(char *cmd)
{
	if (ft_strncmp(cmd, "pa", 3) == 0 || ft_strncmp(cmd, "pb", 3) == 0)
		return (1);
	else
		return (0);
}

int	is_rotate(char *cmd)
{
	if (ft_strncmp(cmd, "ra", 3) == 0 || ft_strncmp(cmd, "rb", 3) == 0 \
		|| ft_strncmp(cmd, "rr", 3) == 0)
		return (1);
	else
		return (0);
}

int	is_reverse(char *cmd)
{
	if (ft_strncmp(cmd, "rra", 4) == 0 || ft_strncmp(cmd, "rrb", 4) == 0 \
		|| ft_strncmp(cmd, "rrr", 4) == 0)
		return (1);
	else
		return (0);
}
