#include "../include/push_swap.h"


// void	sorting_five(t_node ** stack_a, t_node ** stack_b)
// {
// 	int biggest_nb_value;
// 	int biggest_nb_pos;
// 	int smallest_nb_value;
// 	int smallest_nb_pos;
// 	find_biggest_nb((*stack_a), &biggest_nb_value, &biggest_nb_pos);
// 	five_nb_sort(stack_a, stack_b, biggest_nb_pos);
// 	find_smallest_nb((*stack_a), &smallest_nb_value, &smallest_nb_pos);
// 	four_nb_sort(stack_a, stack_b, smallest_nb_pos);
// 	three_nb_sort(stack_a);
// 	get_push("pa",stack_a, stack_b);
// 	get_push("pa", stack_a, stack_b);
// 	get_rotate("ra", stack_a, stack_b);
// }

// int		get_last_value(t_node *stack)
// {
// 	while(stack->next != NULL)
// 	{
// 		stack = stack->next;
// 	}
// 	// pint(stack->data);
// 	return(stack->data);
// }


// int 	compare_extremities(t_node**stack_a, t_node **stack_b)
// {
// 	if ((*stack_b)->data < (*stack_a)->data)
// 	{
// 		get_push("pa", stack_a, stack_b);
// 		return(0);
// 	}
// 	else if (((*stack_b)->data > get_last_value((*stack_a))))
// 	{
// 		get_push("pa", stack_a, stack_b);
// 		get_rotate("ra", stack_a, stack_b);
// 		return(0);
// 	}
// 	return(0);
// }

// void	compare_middles(t_node**stack_a, t_node **stack_b)
// {
// 	// printf("(*stack_b)->data %d\n", (*stack_b)->data);
// 	// printf("(*stack_a)->data %d\n", (*stack_a)->data);
// 	int i = 0;
// 	while ((*stack_b)->data > (*stack_a)->data)
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

// void	comparing_nb(t_node **stack_a, t_node **stack_b)
// {
// 		if ((*stack_b)->data < (*stack_a)->data || (*stack_b)->data > get_last_value((*stack_a)))
// 			compare_extremities(stack_a, stack_b);
// 		else
// 			compare_middles(stack_a, stack_b);
// }

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


void test_find_smallest_number_above(){

	int result;
	char * str_vals= "30 17 20 24 26";
	int total;
	t_node * stack = build_stack(str_vals, &total);
	int total_node;
	result = find_smallest_nb_above_x(stack , 25, &total_node);
	if (result != 4)
	{
		printf("%d result should be 4 and is now %d", __LINE__, result);
		exit(1);
	}

	char * str_vals_2 = "5 7 9 11";
	stack = build_stack(str_vals_2, &total);
	result = find_smallest_nb_above_x(stack , 8,&total_node);
	if (result != 2)
	{
		printf("line %d - result should be 2 and is now %d\n", __LINE__, result);
		exit(1);
	}
}

void test_insertion_sort()
{
	t_node * stack_a;
	t_node * stack_b;
	int total_nb;
	// stack_a = build_stack("123 2 19899 -1 8 0 3 1 19898", &total_nb);
	// stack_a = build_stack("-163 412 189 414 300 136 -117 19 471 393 364 259 404 217 213 152 134 13 358 43 111 268 415 476 35 317 381 448 296 229 429 409 -320 231 255 119 103 427 468 176 284 -482 372 41 321 478 91 319 153 -484", &total_nb);
	stack_a = build_stack("10 4 5 1 2 3 11", &total_nb);
	// stack_a = build_stack("3 -2 -9 13 6 5", &total_nb);
	t_node *tmp_a = stack_a;
	stack_b = NULL;
	insertion_sort(&stack_a, total_nb);
	// if (is_stack_sorted(stack_a) == 0)
	// {
	// 	printf("%d stack_a is not sorted\n", __LINE__);
	// 	exit(0);
	// }

	// printf("\nstack_a\n");display_stack(stack_a);
	// printf("\nstack_b\n");display_stack(stack_b);
}

void	test_compare_middles()
{
	t_node * stack_a;
	t_node * stack_b;
	int total_nb;
	stack_a = build_stack("1 3 5 7 9", &total_nb);
	stack_b = build_stack("8", &total_nb);

	compare_middles(&stack_a, &stack_b);
	// printf("\nstack_a\n");display_stack(stack_a);
	// printf("\nstack_b\n");display_stack(stack_b);
}

void test_rotate_number_to_top()
{
	t_node * stack_a;
	int total_nb;
	stack_a = build_stack("1 3 5 7 9", &total_nb);
	rotate_number_to_top(&stack_a, 2, total_nb);
	int expected_res = 5;
	if (stack_a->data != expected_res)
	{
		printf("%d WRONG. It's %d and it should be %d\n",
		__LINE__, stack_a->data, expected_res);
		exit(1);
	}


	stack_a = build_stack("1 3 5 7 9 10", &total_nb);
	rotate_number_to_top(&stack_a, 4, total_nb);
	expected_res = 9;
	if (stack_a->data != expected_res)
	{
		printf("%d WRONG. It's %d and it should be %d\n",
		__LINE__, stack_a->data, expected_res);
		exit(1);
	}
}

int		main()
{
	printf("test_insertion_sort\n");
	// test_find_smallest_number_above();
	// test_insertion_sort();
	// test_compare_middles();
	test_rotate_number_to_top();

	printf("all test ok\n");






}
