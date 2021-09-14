/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_toolbox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 12:06:06 by nachin            #+#    #+#             */
/*   Updated: 2021/09/13 13:08:38 by nachin           ###   ########.fr       */
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

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
