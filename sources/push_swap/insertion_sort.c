#include "../../include/push_swap.h"

int	find_smallest_nb_above_x(t_node*stack, int x, int *total_node)
{
	int b_pos;
	int smallest;
	find_biggest_nb(stack, &smallest, &b_pos);
	int i_smallest = 0;
	int i_node = 0;
	// "5 7 9 11" and 8
	while(stack != NULL)
	{
		if (stack->data < smallest && stack->data > x )
		{
			// printf("OUJKLJKDFJKLSDJFKJ\n");
			smallest = stack->data;
			i_smallest = i_node;
		}
		i_node++;
		stack = stack->next;
	}
	// printf("i_smallest %d\n", i_smallest);
	// printf("i_node %d\n", i_node);
	// printf("smallest %d\n", smallest);

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


int 	compare_extremities(t_node**stack_a, t_node **stack_b)
{
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
	//doit avoir get et tout
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

void	compare_middles(t_node**stack_a, t_node **stack_b)
{
	int i = 0; //afin de rembobiner stack a

	//opti begins
	int total_node;
	// printf("POS %d\n", find_smallest_nb_above_x((*stack_a), stack_b->data, &total_node));
	// printf("total_node %d\n", total_node);
	int pos = find_smallest_nb_above_x((*stack_a), (*stack_b)->data, &total_node);
	float stack_divided_by_2 = total_node / 2;
	printf("total_node %d\npos %d \nstack_divided_bytwo %f\n", total_node, pos, stack_divided_by_2);


	//compute pos

	//rotate
	rotate_number_to_top(stack_a);
	//insert to a
	get_push("pa")

	// if (pos < stack_divided_by_2)
	// {
	// 	pstr("top");
	// 	i = 0;
	// 	while (i < pos)
	// 	{
	// 		i++;
	// 		get_rotate("ra", stack_a, stack_b);
	// 	}
	// 	get_push("pa", stack_a, stack_b);
	// 	while(i > 0)
	// 	{
	// 		get_reverse("rra", stack_a, stack_b);
	// 		i--;
	// 	}
	// }
	// else if (pos > stack_divided_by_2)
	// {
	// 	pstr("bottom");
	// 	i = 0;
	// 	int i_pos = total_node - pos;
	// 	while (i < i_pos)
	// 	{
	// 		i++;
	// 		get_rotate("rra", stack_a, stack_b);
	// 	}
	// 	get_push("pa", stack_a, stack_b);
	// 	while(i > 0)
	// 	{
	// 		get_reverse("ra", stack_a, stack_b);
	// 		i--;
	// 	}
	// }


	// printf("\nstack_a\n");display_stack((*stack_a));
	// printf("\nstack_b\n");display_stack(stack_b);
	// //opti ends





	// while ((*stack_b)->data > (*stack_a)->data)
	// {
	// 	i++;
	// 	get_rotate("ra", stack_a, stack_b);
	// }
	// get_push("pa", stack_a, stack_b);
	// while(i > 0)
	// {
	// 	get_reverse("rra", stack_a, stack_b);
	// 	i--;
	// }

}

void	comparing_nb(t_node **stack_a, t_node **stack_b)
{
		if ((*stack_b)->data < (*stack_a)->data || (*stack_b)->data > get_last_value((*stack_a)))
			compare_extremities(stack_a, stack_b);
		else
			compare_middles(stack_a, stack_b);
}


int	insertion_sort(t_node **stack_a, int total_nb)
{
	t_node * stack_b;
	t_node *tmp_a = (*stack_a);
	stack_b = NULL;
	int i = total_nb;
	while (i != 5)
	{
		get_push("pb",stack_a, &stack_b);
		i--;
		tmp_a = tmp_a->next;
	}
	sorting_five(stack_a, &stack_b);

	// //opti begins
	// int total_node;
	// // printf("POS %d\n", find_smallest_nb_above_x((*stack_a), stack_b->data, &total_node));
	// // printf("total_node %d\n", total_node);
	// int pos = find_smallest_nb_above_x((*stack_a), stack_b->data, &total_node);
	// float stack_divided_by_2 = total_node / 2;
	// if (pos < stack_divided_by_2)
	// 	pstr("top");
	// else if (pos > stack_divided_by_2)
	// 	pstr("bottom");


	// //opti ends

	if (stack_b->next == NULL)
	{
		comparing_nb(stack_a, &stack_b);
		return(0);
	}
	while(stack_b != NULL)
	{
		comparing_nb(stack_a, &stack_b);
	}
	printf("\nstack_a\n");display_stack((*stack_a));
	printf("\nstack_b\n");display_stack(stack_b);
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

