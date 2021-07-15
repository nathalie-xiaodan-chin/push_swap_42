#include "../include/push_swap.h"
// #include "../include/sort.h"

// void	three_nb_sort(t_node **stack_a, int n_elem)
// {
// 	int a;
// 	int b;
// 	int c;
// 	t_node * tmp = (*stack_a);

// 	t_node *stack_b = NULL;
// 	init_linked_list(stack_b);

// 	a = tmp->data;
// 	tmp = tmp->next;
// 	b = tmp->data;
// 	tmp = tmp->next;
// 	c = tmp->data;

// 	if (a > b && b < c && c > a)
// 	{
// 		get_swap("sa", stack_a, stack_b);
// 	}
// 	else if (a > b && b > c && c < a)
// 	{
// 		get_swap("sa", stack_a, stack_b);
// 		get_reverse("rra", stack_a, stack_b);
// 	}
// 	else if (a > b && b < c && c < a)
// 	{
// 		get_rotate("ra", stack_a, stack_b);
// 	}
// 	else if (a < b && b > c && c > a)
// 	{
// 		get_swap("sa", stack_a, stack_b);
// 		get_rotate("ra", stack_a, stack_b);
// 	}
// 	else if (a < b && b > c && c < a)
// 	{
// 		get_reverse("rra", stack_a, stack_b);
// 	}

// 	display_stack((*stack_a));

// }

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
void		find_smallest_nb(t_node *list, int *s_value, int *s_pos, int biggest_nb)
{
	t_node *tmp = NULL;
	tmp = list;
	int smallest_value =  biggest_nb;
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


int		main()
{
	t_node* stack_a = NULL;
	init_linked_list(stack_a);
	int count = 0; //from 1
	stack_a = build_stack("10 12 42  15 10000", &count);
	int smallest_nb_value = 0;
	int smallest_nb_pos = 0;

	int biggest_nb_value = 0;
	int biggest_nb_pos = 0;

	find_biggest_nb(stack_a, &biggest_nb_value, &biggest_nb_pos);
	delete_node(&stack_a, biggest_nb_pos);
	find_smallest_nb(stack_a, &smallest_nb_value, &smallest_nb_pos, biggest_nb_value);
	delete_node(&stack_a, smallest_nb_pos);

	// "12 15 42 10 10000"

	// printf("smallest nb value: %d\n", smallest_nb_value);
	// printf("smallest nb pos: %d\n", smallest_nb_pos);
	// printf("biggest nb value: %d\n", biggest_nb_value);
	// printf("biggest nb pos: %d\n", biggest_nb_pos);


	t_node *stack_b = NULL;
	init_linked_list(stack_b);
	push(biggest_nb_value, &stack_b);
	push(smallest_nb_value, &stack_b);

	printf("stack_a :\n");display_stack(stack_a);
	printf("stack_b :\n");display_stack(stack_b);

	// three_nb_sort(&stack_a, count);
	printf("stack_a :\n");display_stack(stack_a);

	return(0);
}


