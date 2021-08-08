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
	int total_nb;


	stack_a = build_stack("995 101 613 738 994 495 37 749  ", &total_nb);
	insertion_sort(&stack_a, total_nb);
		display_stack(stack_a);

	if (! is_stack_sorted(stack_a)){
		printf("line %d stack should be sorted\n", __LINE__);
		display_stack(stack_a);
		exit(1);
	}

	stack_a = build_stack("928 230 327 394 112 466 76 554 370 745 73 284 231 959 996 412 261 515 524 201 ", &total_nb);
	insertion_sort(&stack_a, total_nb);
	if (! is_stack_sorted(stack_a)){
		printf("line %d stack should be sorted\n", __LINE__);
		display_stack(stack_a);
		exit(1);
	}

	stack_a = build_stack("151 17 566 697 571 349", &total_nb);
	insertion_sort(&stack_a, total_nb);
	if (! is_stack_sorted(stack_a)){
		printf("line %d stack should be sorted\n", __LINE__);
		display_stack(stack_a);
		exit(1);
	}

	stack_a = build_stack("974 435 716 425 13 910 658 167 311 642", &total_nb);
	insertion_sort(&stack_a, total_nb);
	if (! is_stack_sorted(stack_a)){
		printf("line %d stack should be sorted\n", __LINE__);
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

void	test_compute_chunk_interval()
{
	pstr("test_compute_chunk_interval");
	t_node * stack;
	int total_nb;
	stack = build_stack("-5000 10000 2 5934 89 3 1", &total_nb);
	int min = 0;
	int max = 0;
	find_biggest_and_smallest(stack, &min, &max);

	int res = compute_chunk_interval(min, max);
	int expected_res = 15000;
	if (res != expected_res)
	{
		printf("%d TRY AGAIN. It's %d and should be %d\n", __LINE__, res, expected_res);
		exit(1);
	}


	stack = build_stack("-1100 -3 -5 -13432 -19340 -2", &total_nb);
	find_biggest_and_smallest(stack, &min, &max);
	res = compute_chunk_interval(min, max);

	expected_res = 19338;
	if (res != expected_res)
	{
		printf("%d TRY AGAIN. It's %d and should be %d\n", __LINE__, res, expected_res);
		exit(1);
	}
}

	void	test_move_nb_to_b_by_chunk()
	{
		t_node * stack_a;
		t_node * stack_b;
		int total_nb;
		int interval;
		int smallest_nb;
		int biggest_nb;

		// stack_a = build_stack("-5000 10000 2 5934 89 3 1", &total_nb);
		stack_a = build_stack("0 2000 1 2 3 4 5", &total_nb);
		find_biggest_and_smallest(stack_a, &smallest_nb, &biggest_nb);
		interval = compute_chunk_interval(smallest_nb, biggest_nb);
		move_nb_to_b_by_chunk(&stack_a, &stack_b, interval);

		// printf("\nstack_a:\n");display_stack(stack_a);
		// printf("stack_b:\n");display_stack(stack_b);
	}

void	test_stack_len()
{
	t_node * stack;
	int total_nb;
	stack = build_stack("-5000 10000 2 5934 89 3 1", &total_nb);
	int res = stack_len(stack);
	int expected_res = 7;
	if (res != expected_res)
	{
		printf("%d TRY AGAIN. It's %d and should be %d\n", __LINE__, res, expected_res);
		exit(1);
	}

	stack = build_stack("-5000", &total_nb);
	res = stack_len(stack);
	expected_res = 1;
	if (res != expected_res)
	{
		printf("%d TRY AGAIN. It's %d and should be %d\n", __LINE__, res, expected_res);
		exit(1);
	}

	stack = build_stack("-5000 1", &total_nb);
	res = stack_len(stack);
	expected_res = 2;
	if (res != expected_res)
	{
		printf("%d TRY AGAIN. It's %d and should be %d\n", __LINE__, res, expected_res);
		exit(1);
	}
}

void	test_pre_sorting_stack()
{
	printf("test_insertion_sort..\n\n");
	t_node * stack_a;
	t_node * stack_b = NULL;
	int total_nb;

	stack_a = build_stack("151 17 1 2 3 4 18 566 697 571 349 1000 100000", &total_nb);

	pre_sorting_stack(&stack_a, &stack_b);

	printf("\nstack_a:\n");display_stack(stack_a);
	printf("stack_b:\n");display_stack(stack_b);
}

void	test_move_nb_of_chunk_to_top()
{
	pstr("test_push_chunks_nbs_to_b");
	t_node * stack;
	t_node * s_b;
	int total_nb;
	stack = build_stack("151 17 55 1 3 99", &total_nb);
	//to fix and and stack b
	t_sorting_toolbox the;
	init_struct_sorting_toolbox(&the, total_nb);
	the.smallest_nb_value = 1;
	the.biggest_nb_value = 5;

	push_nb_of_chunk_to_b(&stack, &s_b, &the);
	int expected_res = 3;
	if (s_b->data != expected_res)
	{
		printf("%d TRY AGAIN. It's %d and should be %d\n",
				__LINE__, stack->data, expected_res);
		display_stack(stack);
		exit(1);
	}

	stack = build_stack("151 17 1 2 3 777 888 88 99", &total_nb);
	// move_nb_of_chunk_to_top(&stack, 1, 5);
	expected_res = 1;
	if (stack->data != expected_res)
	{
		printf("%d TRY AGAIN. It's %d and should be %d\n", __LINE__, stack->data, expected_res);
		exit(1);
	}

	stack = build_stack("151 17 777 888 88 99", &total_nb);
	// move_nb_of_chunk_to_top(&stack, 1, 5);
	expected_res = 151;
	if (stack->data != expected_res)
	{
		printf("%d TRY AGAIN. It's %d and should be %d\n", __LINE__, stack->data, expected_res);
		exit(1);
	}
}


int		main()
{
	test_move_min_value_to_top();
	// test_insertion_sort();

	test_find_smallest_number_above();
	test_insert_nb_in_middles();

	test_rotate_number_to_top();

	test_compute_chunk_interval();
	test_move_nb_to_b_by_chunk();

	test_stack_len();

	test_pre_sorting_stack();

	test_move_nb_of_chunk_to_top();

	printf("all test ok\n");

}
