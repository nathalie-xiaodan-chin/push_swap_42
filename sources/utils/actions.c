#include "../../include/push_swap.h"

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

// void swap_action(t_node **stack)
// {
// 	if (is_stack_empty((*stack)))
// 		return;
//     pint(20);
// 	int tmp_first;
//     pint(21);

// 	int tmp_second = (*stack)->data;
//     pint(22);

// 	pop(stack);

// 	tmp_first = (*stack)->data;
// 	pop(stack);
// 	(*stack) = push(tmp_second, (*stack));
// 	(*stack) = push(tmp_first, (*stack));
// }

void swap_action(t_node **stack)
{
	if (is_stack_empty((*stack)))
		return;
    pint(20);
	int tmp_first;
    pint(21);
	int tmp_second = (*stack)->data;
    pint(22);

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
        pint(10);
		swap_action(*stack_a);
	    // display_stack(stack_a);
        pint(11);
	}
	// else if (ft_strncmp(cmd, "sb", 3) == 0)
	// {
	// 	swap_action(&stack_b);
	// }
	// else if (ft_strncmp(cmd, "ss", 3) == 0)
	// {
	// 	swap_action(&stack_a);
	// 	swap_action(&stack_b);
	// }
}