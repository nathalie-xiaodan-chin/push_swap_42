#include "../include/push_swap.h"

void test_is_sorted(){

	printf("test_is_sorted...\n");
	int result;
	int expected_result;
	int size;
	t_node *stack;

	stack = build_stack("1 2 3 4", &size);
	result = is_stack_sorted(stack);
	expected_result = 1;

	if (result != expected_result){
		pstr("1 2 3 4 should be sorted");
		exit(1);
	}

	stack = build_stack("2 3 4 1", &size);
	result = is_stack_sorted(stack);
	expected_result = 0;

	if (result != expected_result){
		pstr("2 3 4 1 should not be sorted");
		exit(1);
	}

	stack = build_stack("10 2 3 4", &size);
	result = is_stack_sorted(stack);
	expected_result = 0;

	if (result != expected_result){
		pstr("10 2 3 4 should not be sorted");
		exit(1);
	}

	stack = build_stack("10 -3 4 8", &size);
	result = is_stack_sorted(stack);
	expected_result = 0;

	if (result != expected_result){
		pstr("10 -3 4 8 should not be sorted");
		exit(1);
	}

	printf("done.\n");
}

// void	function_push_2(t_node **stack)
// {
// 	// push(1, *stack);
// 	push(1, stack);

// }

// void	function_push_1(t_node **stack)
// {

// 	function_push_2(stack);

// }


// void	function_pop_2(t_node **stack)
// {
// 	// push(1, *stack);
// 	pop(stack);

// }

// void	function_pop_1(t_node **stack)
// {

// 	function_pop_2(stack);

// }

// int		main(int argc, char **argv)
// {
// 	printf(RED"I am the main of "PURPLE"test_stack\n"NO_COLOR);

// 	// //test push stack a
// 	// t_node *stack_a = NULL;
// 	// init_linked_list(stack_a);
// 	// stack_a = build_stack("12 15 42",0);
// 	// push(89, &stack_a);
// 	// function_push_1(&stack_a);
// 	// display_stack(stack_a);

// 	// //test push stack b
// 	// t_node *stack_b = NULL;
// 	// init_linked_list(stack_b);
// 	// stack_b = build_stack("99",0);
// 	// push(89, &stack_b);
// 	// function_push_1(&stack_b);
// 	// display_stack(stack_b);

// 	// //test pop stack a
// 	// t_node *stack_a = NULL;
// 	// init_linked_list(stack_a);
// 	// stack_a = build_stack("12 15 42",0);
// 	// pop(&stack_a);
// 	// function_pop_1(&stack_a);
// 	// display_stack(stack_a);

// 	// //test push stack b
// 	// t_node *stack_b = NULL;
// 	// init_linked_list(stack_b);
// 	// stack_b = build_stack("99 100",0);
// 	// pop(&stack_b);
// 	// function_pop_1(&stack_b);
// 	// display_stack(stack_b);

// 	return (0);
// }
