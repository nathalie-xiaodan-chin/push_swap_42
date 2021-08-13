/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:16:54 by nachin            #+#    #+#             */
/*   Updated: 2021/08/13 18:24:20 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_struct_stack_toolbox(t_stack_toolbox *init)
{
	init->i = 0;
	init->size = 0;
	init->nb = 0;
}

long long	long_long_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	result;

	i = 0;
	neg = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t' \
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	if (neg == 1)
		return (result * (-1));
	else
		return (result);
}

int	is_invisible_char(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	is_invisible_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_invisible_char(str[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

/**
 * DEBUG TOOLS
 *
*/
// int	ft_check_sep(char c, char *sep)
// {
// 	int	i;

// 	i = 0;
// 	while (sep[i])
// 	{
// 		if (c == sep[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void	ff(void)
// {
// 	fflush(stdout);
// }

// void	pint(int integer)
// {
// 	printf("int |%d|\n", integer);
// 	fflush(stdout);
// }

// void	pstr(char *str)
// {
// 	printf("str |%s|\n", str);
// 	fflush(stdout);
// }

// void	pchar(char c)
// {
// 	printf("c |%c|\n", c);
// 	fflush(stdout);
// }

// void	pfloat(float c)
// {
// 	printf("float |%f|\n", c);
// 	fflush(stdout);
// }

// void	display_stack(t_node *head)
// {
// 	t_node	*current;

// 	current = head;
// 	if (current == NULL)
// 	{
// 		printf("stack is empty\n");
// 		exit(1);
// 	}
// 	while (current != NULL)
// 	{
// 		printf("stack : %d\n", current->data);
// 		current = current->next;
// 	}
// }

// void	display_head(t_node *stack)
// {
// 	if (stack != NULL)
// 	{
// 		printf("element on top: %d\n", stack->data);
// 	}
// 	else
// 	{
// 		printf("stack is empty.\n");
// 	}
// }
