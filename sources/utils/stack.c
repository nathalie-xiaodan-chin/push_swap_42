/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:47:02 by nachin            #+#    #+#             */
/*   Updated: 2021/08/06 17:42:13 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_struct_stack_toolbox(t_stack_toolbox *init)
{
	init->i = 0;
	init->size = 0;
	init->nb = 0;
}

void	reverse_stack(t_node **tmp)
{
	t_node	*prev_ptr;
	t_node	*current;
	t_node	*next;

	prev_ptr = NULL;
	current = *tmp;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev_ptr;
		prev_ptr = current;
		current = next;
	}
	*tmp = prev_ptr;
}

void	check_errors_in_str(t_stack_toolbox *a, char *str)
{
	if (is_empty(str) != 0)
		error_and_exit();
	if (is_invisible_str(&str[a->i]) == 1)
		error_and_exit();
	while (str[a->i] != '\0')
	{
		if (!ft_isdigit(str[a->i]) && !is_invisible_char(str[a->i]) && \
			str[a->i] != '-' && str[a->i] != '+')
			error_and_exit();
		a->i++;
	}
	a->i = 0;
	while (str[a->i] != '\0')
	{
		if (!ft_isdigit(str[a->i + 1]) && str[a->i] == '-')
			error_and_exit();
		else if (!ft_isdigit(str[a->i + 1]) && str[a->i] == '+')
			error_and_exit();
		a->i++;
	}
}

void	pushing_nb_in_stack(t_stack_toolbox *a, char *str, t_node **stack_a)
{
	a->i = 0;
	while (str[a->i] != '\0')
	{
		while (is_invisible_char(str[a->i]))
			a->i++;
		if (str[a->i] == '0')
		{
			push(0, stack_a);
			a->size = 1 + a->size;
		}
		while (is_invisible_char(str[a->i]))
			a->i++;
		if (ft_atoi(&str[a->i]) != 0)
		{
			a->nb = long_long_atoi(&str[a->i]);
			if (a->nb > 2147483647 || a->nb < -2147483648)
				error_and_exit();
			push(ft_atoi(&str[a->i]), stack_a);
			a->size = 1 + a->size;
		}
		while (ft_isdigit(str[a->i]) || str[a->i] == '-' || str[a->i] == '+')
			a->i++;
	}
}

t_node	*build_stack(char *str, int *stack_size)
{
	t_node			*stack_a;
	t_stack_toolbox	a;

	stack_a = NULL;
	init_struct_stack_toolbox(&a);
	check_errors_in_str(&a, str);
	pushing_nb_in_stack(&a, str, &stack_a);
	reverse_stack(&stack_a);
	*stack_size = a.size;
	if (is_duplicate_in_stack(stack_a) != 0)
		error_and_exit();
	return (stack_a);
}
