#include "../../include/push_swap.h"

int	find_smallest_nb_above_x(t_node*stack, int x)
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
			smallest = stack->data;
			i_smallest = i_node;
		}
		i_node++;
		stack = stack->next;
	}
	pint(i_node);
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

void	compare_middles(t_node**stack_a, t_node **stack_b)
{
	// printf("(*stack_b)->data %d\n", (*stack_b)->data);
	// printf("(*stack_a)->data %d\n", (*stack_a)->data);
	int i = 0;
	while ((*stack_b)->data > (*stack_a)->data)
	{
		i++;
		get_rotate("ra", stack_a, stack_b);
	}
	get_push("pa", stack_a, stack_b);
	while(i > 0)
	{
		get_reverse("rra", stack_a, stack_b);
		i--;
	}
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


	if (stack_b->next == NULL)
	{
		comparing_nb(stack_a, &stack_b);
		return(0);
	}
	while(stack_b != NULL)
	{
		comparing_nb(stack_a, &stack_b);
	}

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

