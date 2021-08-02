#include "../../include/push_swap.h"

//find the smallest nb
//find the biggest nb

int		find_pos(t_node * list, int value)
{
	t_node *tmp = NULL;
	tmp = list;
	int i = 0;
	while(tmp != NULL)
	{
		if (tmp->data != value)
		{
			tmp = tmp->next;
			i++;
		}
		else
			break;
	}
	return(i);
}
void		find_smallest_nb(t_node *list, int *s_value, int *s_pos)
{
	t_node *tmp = NULL;
	tmp = list;
	int smallest_value = list->data;
	int smallest_pos = 0;
	// pint(smallest_value);

	while(tmp != NULL)
	{
		// pint(tmp->data);
		if (tmp->data < smallest_value)
		{
			smallest_value = tmp->data;
			smallest_pos++;
		}
		tmp = tmp->next;
	}
	*s_value = smallest_value;
	*s_pos = find_pos(list, smallest_value);
}

void		find_biggest_nb(t_node *list, int *b_value, int *b_pos)
{
	int biggest_nb_value = 0;
	int biggest_nb_pos = 0;

	t_node *tmp = NULL;
	tmp = list;
	while(tmp != NULL)
	{
		if (tmp->data > biggest_nb_value)
		{
			biggest_nb_value = tmp->data;
			biggest_nb_pos++;
		}
		tmp = tmp->next;
	}
	// *b_pos = biggest_nb_pos;
	*b_value = biggest_nb_value;
	*b_pos = find_pos(list, biggest_nb_value);

}


void	four_nb_sort(t_node **stack_a, t_node**stack_b, int i)
{
	if (i == 0)
	{
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 1)
	{
		get_rotate("ra",stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 2)
	{
		get_rotate("ra",stack_a, stack_b);
		get_rotate("ra",stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 3)
	{
		get_reverse("rra",stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
}

void	five_nb_sort(t_node **stack_a, t_node**stack_b, int i)
{
	if (i == 0)
	{
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 1)
	{
		get_rotate("ra",stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 2)
	{
		get_rotate("ra",stack_a, stack_b);
		get_rotate("ra",stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
	else if (i == 3)
	{
		// display_stack(*stack_a);

		get_reverse("rra",stack_a, stack_b);
		// display_stack(*stack_a);

		get_reverse("rra",stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
		// display_stack(*stack_b);
	}
	else if (i == 4)
	{
		get_reverse("rra",stack_a, stack_b);
		get_push("pb", stack_a, stack_b);
	}
}

void	five_or_four_nb(t_node **stack_a, int count)
{
	t_node *stack_b = NULL;
	init_linked_list(stack_b);

	// int count = 0; //starting from 1
	// stack_a = build_stack("10 12 42  15 10000", &count);
	// stack_a = build_stack("11 12 14 10 13", &count);
	// stack_a = build_stack("10 12 14 13 11", &count);
	// stack_a = build_stack("10 11 14 13 12", &count); //hardest for 5
	// stack_a = build_stack("2 1 3 6 5 8", &count);

	int smallest_nb_value = 0;
	int smallest_nb_pos = 0; //starting from 0

	int biggest_nb_value = 0;
	int biggest_nb_pos = 0; //starting from 0

	if (count == 4)
	{
		find_biggest_nb((*stack_a), &biggest_nb_value, &biggest_nb_pos);
		find_smallest_nb((*stack_a), &smallest_nb_value, &smallest_nb_pos);
		four_nb_sort(stack_a, &stack_b, smallest_nb_pos);
		three_nb_sort(stack_a);
		get_push("pa", stack_a, &stack_b);
	}
	else if (count == 5)
	{
		find_biggest_nb((*stack_a), &biggest_nb_value, &biggest_nb_pos);
		// pint(biggest_nb_pos);
		// printf("biggest_nb_value %d\n", biggest_nb_value);
		five_nb_sort(stack_a, &stack_b, biggest_nb_pos);
		// printf("stack_a :\n");display_stack(*stack_a);
		// printf("stack_b :\n");display_stack(stack_b);

		find_smallest_nb((*stack_a), &smallest_nb_value, &smallest_nb_pos);
		// printf("smallest_nb_value %d\n", smallest_nb_value);
		// display_stack(*stack_a);

		four_nb_sort(stack_a, &stack_b, smallest_nb_pos);
		// printf("stack_a :\n");display_stack(*stack_a);
		three_nb_sort(stack_a);
		// display_stack(*stack_a);
		//push biggest nb and smallest nb

		// printf("stack_b :\n");display_stack(stack_b);

		get_push("pa", stack_a, &stack_b);
		get_push("pa", stack_a, &stack_b);
		get_rotate("ra", stack_a, &stack_b);
	}
}
