#include "../include/push_swap.h"

// "4 67 3 87 23"

int		is_stack_empty(t_node *stack)
{
	if (stack == NULL)
	{
		pstr("stack is empty");
		return(1);
	}
	return(0);
}

//décale d’une position vers le bas tous les élements de
//la pile a. Le dernier élément devient le premier.
void	reverse_action(t_node **stack_reversed)
{
	if 	(is_stack_empty((*stack_reversed)))
		return;
	else if((*stack_reversed)->next == NULL)
	{
		free((*stack_reversed));
		(*stack_reversed) = NULL;
		return;
	}
	else if ((*stack_reversed) != NULL)
	{
		//used to go through the while loop
    	t_node *tmp = (*stack_reversed);
		//second to last node
		t_node *penultimate = NULL;
		while (tmp->next != NULL)
    	{
			penultimate = tmp;
    	    tmp = tmp->next;
    	}
		//push data of the last node to the top of the stack
		(*stack_reversed) = push(tmp->data, (*stack_reversed));
		//delete last node
		free(penultimate->next);
		penultimate->next = NULL;
	}
}

void	get_reverse(char *cmd, t_node *stack_a, t_node *stack_b)
{
	if (ft_strncmp(cmd, "rra", 4) == 0)
	{
		reverse_action(&stack_a);
		display_stack(stack_a);

	}
	else if (ft_strncmp(cmd, "rrb", 4) == 0)
	{
		reverse_action(&stack_b);
		display_stack(stack_b);

	}
	else if (ft_strncmp(cmd, "rrr", 4) == 0)
	{
		reverse_action(&stack_a);
		reverse_action(&stack_b);
		// display_stack(stack_a);
		// display_stack(stack_b);
	}
}

// Rotate : décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
// rr : ra et rb en même temps.
void	rotate_action(t_node **stack_rotated)
{
	if (is_stack_empty((*stack_rotated)))
		return;
	//used to go through the while loop
    t_node *tmp =(*stack_rotated);
	//new node is going to be the last one
	t_node *new_node = NULL;
	new_node = (t_node*)malloc(sizeof(t_node));
	new_node->data = (*stack_rotated)->data;
	pop(stack_rotated);
	while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
	tmp->next = new_node;
	new_node->next = NULL;
}

void	get_rotate(char *cmd, t_node *stack_a, t_node *stack_b)
{
	if (ft_strncmp(cmd, "ra", 3) == 0)
	{
		rotate_action(&stack_a);
	}
	else if (ft_strncmp(cmd, "rb", 3) == 0)
	{
		rotate_action(&stack_b);
	}
	else if (ft_strncmp(cmd, "rr", 3) == 0)
	{
		rotate_action(&stack_a);
		rotate_action(&stack_b);
	}
}

void push_action(t_node **stack_pushed, t_node **stack_received)
{
	if (is_stack_empty((*stack_pushed)))
		return;
	int tmp = (*stack_pushed)->data;
	pop(stack_pushed);
	(*stack_received) = push(tmp, (*stack_received));
}

void	get_push(char *cmd, t_node *stack_a, t_node *stack_b)
{
	if (ft_strncmp(cmd, "pa", 3) == 0)
	{
		push_action(&stack_b, &stack_a);
		display_stack(stack_a);
		display_stack(stack_b);
	}
	else if (ft_strncmp(cmd, "pb", 3) == 0)
	{
		push_action(&stack_a, &stack_b);
	}
}

void swap_action(t_node **stack)
{
	if (is_stack_empty((*stack)))
		return;
	int tmp_first;
	int tmp_second = (*stack)->data;
	pop(stack);
	tmp_first = (*stack)->data;
	pop(stack);
	(*stack) = push(tmp_second, (*stack));
	(*stack) = push(tmp_first, (*stack));
}

void	get_swap(char *cmd, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(cmd, "sa", 3) == 0)
	{
		swap_action(&stack_a);
	}
	else if (ft_strncmp(cmd, "sb", 3) == 0)
	{
		swap_action(&stack_b);

	}
	else if (ft_strncmp(cmd, "ss", 3) == 0)
	{
		pint(1);
		swap_action(&stack_a);
		pint(2);

		swap_action(&stack_b);
		pint(3);

	}
}

t_node *	build_stack_a(char *str, int argc)
{
	t_node *stack_a = NULL;
	init_linked_list(stack_a);
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && !is_invisible_char(str[i]))
			pstr("not a digit and not a space");
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		while(is_invisible_char(str[i]))
			i++;
		stack_a = push(ft_atoi(&str[i]), stack_a);
		while(ft_isdigit(str[i]))
			i++;
	}
	reverse_stack(&stack_a);
	return(stack_a);
}

int		main(int argc, char **argv)
{
	printf(RED"I am the main of "PURPLE"test_actions\n"NO_COLOR);
	//to do : If no argument is given checker stops and displays nothing.

	/**
	 * test swap
	*/
	pstr("testing sa...");
	t_node *stack_a = NULL;
	t_node *stack_b = NULL;
	init_linked_list(stack_a);
	// stack_a = build_stack_a("", 0);
	// get_swap("sa", stack_a, stack_b);
	// display_stack(stack_a);
	stack_a = build_stack_a("1 2", 0);
	// swap_action(&stack_a);

	get_swap("sa", stack_a, stack_b);
	display_stack(stack_a);
	// pstr("testing sb...");
	// char *cmd = "sb";
	// t_node *stack_b = NULL;
	// stack_b = init_linked_list(stack_b);
	// stack_b = build_stack_b("4 67 3 87 23", 0);




	// //create and fill stack_a
	// t_node *stack_a = NULL;
	// init_linked_list(stack_a);
	// stack_a = build_stack_a(argv[1], argc);
	// //create stack_b
	// t_node *stack_b = NULL;
	// stack_b = init_linked_list(stack_b);

	// //dealing with the commands
	// char *cmd;
	// while (get_next_line(0, &cmd) > 0)
	// {
	// 	if (ft_strncmp(cmd, "sa", 3) == 0 || ft_strncmp(cmd, "sb", 3) == 0 || strncmp(cmd, "ss", 3) == 0)
	// 	{
	// 		get_swap(cmd, stack_a, stack_b);
	// 	}
	// 	else if (ft_strncmp(cmd, "pa", 3) == 0 || ft_strncmp(cmd, "pb", 3) == 0)
	// 	{
	// 		get_push(cmd, stack_a, stack_b);
	// 	}
	// 	else if (ft_strncmp(cmd, "ra", 3) == 0 || ft_strncmp(cmd, "rb", 3) == 0 || ft_strncmp(cmd, "rr", 3) == 0)
	// 	{
	// 		get_rotate(cmd, stack_a, stack_b);
	// 	}
	// 	else if (ft_strncmp(cmd, "rra", 4) == 0 || ft_strncmp(cmd, "rrb", 4) == 0 || ft_strncmp(cmd, "rrr", 4) == 0)
	// 	{
	// 		get_reverse(cmd, stack_a, stack_b);
	// 	}
	// 	// else
	// 	// 	exit(0);
	// }
	return (0);
}
