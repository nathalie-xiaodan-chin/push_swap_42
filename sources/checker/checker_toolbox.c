#include "../../include/push_swap.h"

void	swap_for_checker(char *cmd, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(cmd, "sa", 3) == 0)
	{
		swap_action(stack_a);
	}
	else if (ft_strncmp(cmd, "sb", 3) == 0)
	{
		swap_action(stack_b);
	}
	else if (ft_strncmp(cmd, "ss", 3) == 0)
	{
		swap_action(stack_a);
		swap_action(stack_b);
	}
}

void	push_for_checker(char *cmd, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(cmd, "pa", 3) == 0)
	{
		push_action(stack_b, stack_a);
	}
	else if (ft_strncmp(cmd, "pb", 3) == 0)
	{
		push_action(stack_a, stack_b);
	}
}

void	rotate_for_checker(char *cmd, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(cmd, "ra", 3) == 0)
	{
		rotate_action(stack_a);
	}
	else if (ft_strncmp(cmd, "rb", 3) == 0)
	{
		rotate_action(stack_b);
	}
	else if (ft_strncmp(cmd, "rr", 3) == 0)
	{
		rotate_action(stack_a);
		rotate_action(stack_b);
	}
}

void	reverse_for_checker(char *cmd, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(cmd, "rra", 4) == 0)
	{
		reverse_action(stack_a);
	}
	else if (ft_strncmp(cmd, "rrb", 4) == 0)
	{
		reverse_action(stack_b);
	}
	else if (ft_strncmp(cmd, "rrr", 4) == 0)
	{
		reverse_action(stack_a);
		reverse_action(stack_b);
	}
}



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


