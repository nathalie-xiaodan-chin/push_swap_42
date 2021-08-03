#include "../include/push_swap.h"

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

	char * str_vals_3 = "1 3 5 7 9";
	stack = build_stack(str_vals_3, &total);
	result = find_smallest_nb_above_x(stack , 8,&total_node);
	int expected_result = 4;
	if (result != expected_result)
	{
		printf("line %d - result should be %d and is now %d\n", __LINE__,expected_result, result);
		exit(1);
	}

	char * str_vals_4 = "1 3 5 7 9";
	stack = build_stack(str_vals_4, &total);
	result = find_smallest_nb_above_x(stack , 2,&total_node);
	expected_result = 1;
	if (result != expected_result)
	{
		printf("line %d - result should be %d and is now %d\n", __LINE__,expected_result, result);
		exit(1);
	}
}

void test_insertion_sort()
{

	printf("test_insertion_sort..\n\n");
	t_node * stack_a;
	t_node * stack_b;
	int total_nb;

	stack_a = build_stack("151 17 566 697 571 349", &total_nb);
	insertion_sort(&stack_a, total_nb);
	if (! is_stack_sorted(stack_a)){
		printf("stack should be sorted");
		display_stack(stack_a);
		exit(1);
	}

	stack_a = build_stack("974 435 716 425 13 910 658 167 311 642", &total_nb);
	insertion_sort(&stack_a, total_nb);
	if (! is_stack_sorted(stack_a)){
		printf("stack should be sorted");
		display_stack(stack_a);
		exit(1);
	}





	stack_a = build_stack("800 400 200", &total_nb);
	insertion_sort(&stack_a, total_nb);

	if(stack_a->data != 200 ||
	   stack_a->next->data != 400 ||
	   stack_a->next->next->data != 800
	   ){
	 	printf(
			"insertion sort error: first elemts should be 200, 400, 800 and are %i %i %i\n",
			stack_a->data,
			stack_a->next->data,
			stack_a->next->next->data
		);
		exit(1);
	}

	// t_node *tmp_a = stack_a;
	// stack_b = NULL;

	stack_a = build_stack("708 409 571 77 412 ", &total_nb);
	insertion_sort(&stack_a, total_nb);

	if(stack_a->data != 77 ||
	   stack_a->next->data != 409 ||
	   stack_a->next->next->data != 412 ||
	   stack_a->next->next->next->data != 571 ||
	   stack_a->next->next->next->next->data != 708

	   ){
	 	printf(
			"insertion sort error: %i %i %i %i %i\n",
			stack_a->data,
			stack_a->next->data,
			stack_a->next->next->data,
			stack_a->next->next->next->data,
			stack_a->next->next->next->next->data

		);
		exit(1);
	}


	// display_stack(stack_a);


}

void	test_insert_nb_in_middles()
{
	t_node * stack_a;
	t_node * stack_b;
	int total_nb;

	stack_a = build_stack("1 3 5 7 9", &total_nb);
	stack_b = build_stack("8", &total_nb);
	insert_nb_in_middles(&stack_a, &stack_b);


	stack_a = build_stack("1 3 5 7 9", &total_nb);
	stack_b = build_stack("2", &total_nb);
	insert_nb_in_middles(&stack_a, &stack_b);



	// printf("\nstack_a\n");display_stack(stack_a);
	// printf("\nstack_b\n");display_stack(stack_b);
}

void test_rotate_number_to_top()
{
	t_node * stack_a;
	int total_nb;
	stack_a = build_stack("1 3 5 7 9", &total_nb);
	rotate_number_to_top(&stack_a, 2, total_nb - 1);
	int expected_res = 5;
	if (stack_a->data != expected_res)
	{
		printf("%d WRONG. It's %d and it should be %d\n",
		__LINE__, stack_a->data, expected_res);
		exit(1);
	}


	stack_a = build_stack("1 3 5 7 9 10", &total_nb);
	rotate_number_to_top(&stack_a, 4, total_nb - 1);
	expected_res = 9;
	if (stack_a->data != expected_res)
	{
		printf("%d WRONG. It's %d and it should be %d\n",
		__LINE__, stack_a->data, expected_res);
		exit(1);
	}


	stack_a = build_stack("1 3 5 7 9", &total_nb);
	// pint(total_nb);
	rotate_number_to_top(&stack_a, 4, total_nb - 1);
	expected_res = 9;
	if (stack_a->data != expected_res)
	{
		printf("%d WRONG. It's %d and it should be %d\n",
		__LINE__, stack_a->data, expected_res);
		exit(1);
	}


}

void	test_move_min_value_to_top()
{
	printf("test_move_min_value_to_top\n");
	t_node * stack;
	int total_nb;

	stack = build_stack("4 5 1 2 3", &total_nb);
	move_min_value_to_top(&stack, total_nb);
	if (stack->data != 1){
		printf("min value should be 1 and is %i", stack->data);
		exit(1);
	}

	stack = build_stack("566 571 697 349", &total_nb);
	move_min_value_to_top(&stack, total_nb);

	if (stack->data != 349){
		printf("min value should be 349 and is %i", stack->data);
		exit(1);
	}
	printf("done.\n");
}

int		main()
{
	test_move_min_value_to_top();
	test_insertion_sort();
	test_is_sorted();

	test_find_smallest_number_above();
	test_insert_nb_in_middles();

	test_rotate_number_to_top();


	// test_sort_in_order();


	printf("all test ok\n");






}
