#include "../../include/push_swap.h"
// "4 67 3 87 23"


int		main(int argc, char **argv)
{
	printf(RED"I am the main of "PURPLE"checker\n"NO_COLOR);
	//to do : If no argument is given checker stops and displays nothing.

	//create and fill stack_a
	t_node *stack_a = NULL;
	init_linked_list(stack_a);
	stack_a = build_stack_a(argv[1], argc);
	//create stack_b
	t_node *stack_b = NULL;
	stack_b = init_linked_list(stack_b);

	//dealing with the commands
	char *cmd;
	while (get_next_line(0, &cmd) > 0)
	{
		if (ft_strncmp(cmd, "sa", 3) == 0 || ft_strncmp(cmd, "sb", 3) == 0 || strncmp(cmd, "ss", 3) == 0)
		{
			// stack_a = get_swap(cmd, stack_a, stack_b);
			get_swap(cmd, &stack_a, &stack_b);
			display_stack(stack_a);
		}
		else if (ft_strncmp(cmd, "pa", 3) == 0 || ft_strncmp(cmd, "pb", 3) == 0)
		{
			get_push(cmd, &stack_a, &stack_b);
		}
		else if (ft_strncmp(cmd, "ra", 3) == 0 || ft_strncmp(cmd, "rb", 3) == 0 || ft_strncmp(cmd, "rr", 3) == 0)
		{
			get_rotate(cmd, &stack_a, &stack_b);
		}
		else if (ft_strncmp(cmd, "rra", 4) == 0 || ft_strncmp(cmd, "rrb", 4) == 0 || ft_strncmp(cmd, "rrr", 4) == 0)
		{
			get_reverse(cmd, &stack_a, &stack_b);
		}
		// else
		// 	exit(0);
	}
	return (0);
}
