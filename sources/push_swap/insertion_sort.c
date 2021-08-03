#include "../../include/push_swap.h"

void	move_min_value_to_top(t_node** stack, int total_node)
{
	int smallest_pos = 0;
	int smallest_value = 0;
	find_smallest_nb((*stack), &smallest_value, &smallest_pos);
	// display_stack((*stack));
	// printf("\nsmallest_value %d\nsmallest_pos %d\n\n", smallest_value, smallest_pos);
	float stack_divided_by_2 = (float)total_node / 2;

	// printf("\npos %d\n", pos);printf("stack_divided_by_2 %f\n\n", stack_divided_by_2);
	if (smallest_pos < stack_divided_by_2)
	{
		multiple_rotations_on_a(stack, "ra", smallest_pos);
	}
	else
	{
		int n_move = total_node - smallest_pos;
		multiple_rotations_on_a(stack, "rra", n_move);
	}
}

int	find_smallest_nb_above_x(t_node* stack, int x, int *total_node)
{
	int b_pos;
	int smallest;
	find_biggest_nb(stack, &smallest, &b_pos);
	int i_smallest = 0;
	int i_node = 0;
	// printf("\nx %d\n", x);
	// printf("smallest %d\n", smallest);

	while(stack != NULL)
	{
		// printf("stack->data %d\n", stack->data);
		if (stack->data <= smallest && stack->data > x )
		{
			smallest = stack->data;
			i_smallest = i_node;
		}
		i_node++;
		stack = stack->next;
	}
	// printf("i_smallest %d\n", i_smallest);
	// if (x > smallest)
	// {
	// 	i_smallest = i_node;
	// }
	*total_node = i_node - 1;
	return(i_smallest);
}

void	sorting_five(t_node ** stack_a, t_node ** stack_b)
{
	int biggest_nb_value;
	int biggest_nb_pos;
	int smallest_nb_value;
	int smallest_nb_pos;
	find_biggest_nb((*stack_a), &biggest_nb_value, &biggest_nb_pos);
	five_nb_sort(stack_a, stack_b, biggest_nb_pos);
	find_smallest_nb((*stack_a), &smallest_nb_value, &smallest_nb_pos);
	four_nb_sort(stack_a, stack_b, smallest_nb_pos);
	three_nb_sort(stack_a);
	get_push("pa",stack_a, stack_b);
	get_push("pa", stack_a, stack_b);
	get_rotate("ra", stack_a, stack_b);
}

int		get_last_value(t_node *stack)
{
	while(stack->next != NULL)
	{
		stack = stack->next;
	}
	// pint(stack->data);
	return(stack->data);
}


int 	insert_nb_in_extremities(t_node**stack_a, t_node **stack_b, int total_nb)
{

	move_min_value_to_top(stack_a, total_nb);


	if ((*stack_b)->data < (*stack_a)->data)
	{
		get_push("pa", stack_a, stack_b);
		return(0);
	}
	else if (((*stack_b)->data > get_last_value((*stack_a))))
	{
		get_push("pa", stack_a, stack_b);
		get_rotate("ra", stack_a, stack_b);
		return(0);
	}

	return(0);
}

void	multiple_rotations_on_a(t_node **stack_a, char *action, int number_of_time)
{
	int i = 0;
	while(i < number_of_time)
	{

		if (ft_strncmp(action, "rra", 4) == 0)
		{
			reverse_action(stack_a);
			write(1, "rra\n", 4);
		}
		else
		{
			rotate_action(stack_a);
			write(1, "ra\n", 3);

		}
		i++;
	}
}

void rotate_number_to_top(t_node **stack_a, int pos, int total_node)
{
	float stack_divided_by_2 = (float)total_node / 2;
	total_node = total_node + 1; //like in build stack

	// printf("\npos %d\n", pos);printf("stack_divided_by_2 %f\n\n", stack_divided_by_2);
	if (pos < stack_divided_by_2)
	{
		multiple_rotations_on_a(stack_a, "ra", pos);
	}
	else
	{
		int n_move = total_node - pos;
		multiple_rotations_on_a(stack_a, "rra", n_move);
	}
}

void	insert_nb_in_middles(t_node**stack_a, t_node **stack_b)
{
	int i = 0; //afin de rembobiner stack a

	int total_node;
	// printf("JE N EN PEUX PLUS (*stack_b)->data %d\n",  (*stack_b)->data);
	//compute pos
	int pos = find_smallest_nb_above_x((*stack_a), (*stack_b)->data, &total_node);
	//rotate
	rotate_number_to_top(stack_a, pos, total_node);
	//insert to a
	get_push("pa", stack_a, stack_b);

	// printf("\nstack_a\n");display_stack((*stack_a));
	// printf("\nstack_b\n");display_stack((*stack_b));

}

void	insert_nb_from_b_to_a(t_node **stack_a, t_node **stack_b, int* total_nb)
{
		int number_to_insert = (*stack_b)->data;
		int min;
		int max;

		find_biggest_and_smallest((*stack_a), &min, &max);

		if ( number_to_insert < min || number_to_insert > max )
		{
			// printf("number_to_insert %d\n", number_to_insert);

			insert_nb_in_extremities(stack_a, stack_b, *total_nb);
		}
		else
		{
			insert_nb_in_middles(stack_a, stack_b);
		}
		*total_nb = *total_nb +1;

}


int	insertion_sort(t_node **stack_a, int total_nb)
{
	t_node * stack_b;
	t_node *tmp_a = (*stack_a);
	stack_b = NULL;
	int i = total_nb;
	while (i != 1)
	{
		get_push("pb",stack_a, &stack_b);
		i--;

	}
	total_nb = i;
	//sorting_five(stack_a, &stack_b);
	// printf("\nstack_a\n");display_stack((*stack_a));
	// printf("\nstack_b\n");display_stack(stack_b);
	// exit(0);

	while(stack_b != NULL)
	{
		insert_nb_from_b_to_a(stack_a, &stack_b, &total_nb);
		//printf("\nstack_a\n");display_stack((*stack_a));
		//printf("\nstack_b\n");display_stack(stack_b);
	}

	move_min_value_to_top(stack_a, total_nb);

	// printf("\nstack_a\n");display_stack((*stack_a));
	// printf("\nstack_b\n");display_stack(stack_b);
	return(0);
}


/**
 * DRAFT
*/

// int	insertion_sort(t_node **stack_a, t_node **stack_b)
// {
// 	if ((*stack_b)->next == NULL)
// 	{
// 		comparing_nb(stack_a, stack_b);
// 		return(0);
// 	}
// 	while((*stack_b) != NULL)
// 	{
// 		comparing_nb(stack_a, stack_b);
// 	}
// 	return(0);
// }

