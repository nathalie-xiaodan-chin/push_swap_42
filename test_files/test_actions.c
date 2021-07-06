// #include "../include/push_swap.h"
// /**
//  * test function
// */

// void	test_1()
// {
// 	t_node *stack_a = NULL;
// 	t_node *stack_b = NULL;
// 	init_linked_list(stack_a);
// 	init_linked_list(stack_b);

// 	stack_a = build_stack("101 100 110 111",  0);

// 	get_push("pb", &stack_a, &stack_b);
// 	get_push("pb", &stack_a, &stack_b);
// 	get_push("pb", &stack_a, &stack_b);
// 	get_rotate("ra", &stack_a, &stack_b);

// 	t_node *correct_a;
// 	t_node *correct_b;
// 	init_linked_list(correct_a);
// 	init_linked_list(correct_b);
// 	correct_a = build_stack("111", 0);
// 	correct_b = build_stack("110 100 101", 0);

// 	while (correct_a != NULL)
// 	{
// 		if (correct_a->data == stack_a->data)
// 		{
// 			printf(GREEN"stack_a %d | correct_a %d\n"NO_COLOR, stack_a->data, correct_a->data);
// 			stack_a = stack_a->next;
// 			correct_a = correct_a->next;
// 		}
// 		else
// 		{
// 			printf(RED"stack_a->data is %d and should be %d\n"NO_COLOR, stack_a->data, correct_a->data);
// 			exit(0);
// 		}
// 	}
// 	printf("\n");
// 	while (correct_b != NULL)
// 	{
// 		if (correct_b->data == stack_b->data)
// 		{
// 			printf(GREEN"stack_b %d | correct_b %d\n"NO_COLOR, stack_b->data, correct_b->data);
// 			stack_b = stack_b->next;
// 			correct_b = correct_b->next;
// 		}
// 		else
// 		{
// 			printf(RED"stack_b->data is %d and should be %d\n"NO_COLOR, stack_b->data, correct_b->data);
// 			exit(0);
// 		}
// 	}
// 	printf("\n");

// }

// void	test_2()
// {
// 	t_node *stack_a = NULL;
// 	t_node *stack_b = NULL;
// 	init_linked_list(stack_a);
// 	init_linked_list(stack_b);

// 	stack_a = build_stack("101 100 110 111",  0);

// 	pstr("stack_a before test");display_stack(stack_a);
// 	pstr("stack_b before test");display_stack(stack_b);

// 	get_reverse("rra", &stack_a, &stack_b);
// 	get_push("pb", &stack_a, &stack_b);
// 	get_reverse("rrb", &stack_a, &stack_b);
// 	get_push("pa", &stack_a, &stack_b);
// 	get_rotate("ra", &stack_a, &stack_b);

// 	pstr("stack_a after test");display_stack(stack_a);
// 	pstr("stack_b after test");display_stack(stack_b);

// 	// t_node *correct_a;
// 	// t_node *correct_b;
// 	// init_linked_list(correct_a);
// 	// init_linked_list(correct_b);
// 	// correct_a = build_stack("111", 0);
// 	// correct_b = build_stack("110 100 101", 0);

// 	// while (correct_a != NULL)
// 	// {
// 	// 	if (correct_a->data == stack_a->data)
// 	// 	{
// 	// 		printf(GREEN"stack_a %d | correct_a %d\n"NO_COLOR, stack_a->data, correct_a->data);
// 	// 		stack_a = stack_a->next;
// 	// 		correct_a = correct_a->next;
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		printf(RED"stack_a->data is %d and should be %d\n"NO_COLOR, stack_a->data, correct_a->data);
// 	// 		exit(0);
// 	// 	}
// 	// }
// 	// printf("\n");
// 	// while (correct_b != NULL)
// 	// {
// 	// 	if (correct_b->data == stack_b->data)
// 	// 	{
// 	// 		printf(GREEN"stack_b %d | correct_b %d\n"NO_COLOR, stack_b->data, correct_b->data);
// 	// 		stack_b = stack_b->next;
// 	// 		correct_b = correct_b->next;
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		printf(RED"stack_b->data is %d and should be %d\n"NO_COLOR, stack_b->data, correct_b->data);
// 	// 		exit(0);
// 	// 	}
// 	// }
// }

// /**
//  * test main
// */

// int		main(int argc, char **argv)
// {
// 	printf(PURPLE"unit testing vroum...\n\n"NO_COLOR);
// 	test_1();
// 	// test_2();
// 	printf("\n");printf(PURPLE"end of unit testing..."NO_COLOR);
// 	return (0);
// }



// /**
//  * DRAFT
// */


// // /**
// //  * simple test swap
// // */

// // int		main(int argc, char **argv)
// // {
// // 	printf(RED"I am the main of "PURPLE"test_actions\n"NO_COLOR);

// // 	pstr("testing sa...");
// // 	t_node *stack_a = NULL;
// // 	t_node *stack_b = NULL;
// // 	init_linked_list(stack_a);
// // 	init_linked_list(stack_b);

// // 	// pstr("test sa 1...");
// // 	// stack_a = build_stack("", 0);
// // 	// get_swap("sa", &stack_a, &stack_b);
// // 	// display_stack(stack_a);

// // 	// pstr("test sa 2...");
// // 	// stack_a = build_stack("1 2",  0);
// // 	// get_swap("sa", &stack_a, &stack_b);
// // 	// display_stack(stack_a);

// // 	// pstr("testing sb...");
// // 	// stack_b = build_stack("4 67 3 87 23", 0);
// // 	// get_swap("sb", &stack_a, &stack_b);
// // 	// display_stack(stack_b);

// // 	// pstr("testing ss...");
// // 	// stack_a = build_stack("1 2",  0);
// // 	// stack_b = build_stack("4 67 3 87 23", 0);
// // 	// get_swap("ss", &stack_a, &stack_b);
// // 	// pstr("stack_a");
// // 	// display_stack(stack_a);
// // 	// pstr("stack_b");
// // 	// display_stack(stack_b);

// // 	// pstr("test sa 2...");
// // 	// stack_a = build_stack("0       ",  0);
// // 	// get_swap("sa", &stack_a, &stack_b);
// // 	// display_stack(stack_a);

// // 	pstr("test build_stack...");
// // 	// // stack_a = build_stack("      00000   ",0);
// // 	// // display_stack(stack_a);
// // 	// // "0  12 1000000"
// // 	// // stack_a = build_stack("000000000   0 2 1000000",0);
// // 	// // display_stack(stack_a);
// // 	// stack_a = build_stack("-1 0 -9 100 -10000",0);
// // 	// display_stack(stack_a);

// // 	// pstr("test push a");
// // 	// stack_a = build_stack("     1 ",  0);
// // 	// stack_b = build_stack("   999",  0);

// // 	// get_push("pa", &stack_a, &stack_b);
// // 	// pstr("stack a");
// // 	// display_stack(stack_a);
// // 	// pstr("stack b");
// // 	// display_stack(stack_b);

// // 	// pstr("test push b");
// // 	// stack_a = build_stack("     1 ",  0);
// // 	// stack_b = build_stack("   999",  0);
// // 	// get_push("pb", &stack_a, &stack_b);
// // 	// pstr("stack a");
// // 	// display_stack(stack_a);
// // 	// pstr("stack b");
// // 	// display_stack(stack_b);

// // 	pstr("test rotate a");
// // 	stack_a = build_stack("     1 100    2000",  0);
// // 	get_rotate("ra", &stack_a, &stack_b);
// // 	pstr("stack a");
// // 	display_stack(stack_a);

// // 	// pstr("test rotate b");
// // 	// stack_b = build_stack("   3  1 100    2000 88",  0);
// // 	// get_rotate("rb", &stack_a, &stack_b);
// // 	// pstr("stack b");
// // 	// display_stack(stack_b);

// // 	// pstr("test rotate rr");
// // 	// stack_a = build_stack("1 2 3",  0);
// // 	// stack_b = build_stack("4 5 6",  0);
// // 	// get_rotate("rr", &stack_a, &stack_b);
// // 	// pstr("stack a");
// // 	// display_stack(stack_a);
// // 	// pstr("stack b");
// // 	// display_stack(stack_b);


// // 	// pstr("test rra");
// // 	// stack_a = build_stack("1 2 3",  0);
// // 	// get_reverse("rra", &stack_a, &stack_b);
// // 	// pstr("stack a");
// // 	// display_stack(stack_a);

// // 	//to be done again
// // 	// pstr("test rrb");
// // 	// stack_b = build_stack(" 0  12 1000000",  0);
// // 	// get_reverse("rrb", &stack_a, &stack_b);
// // 	// pstr("stack b");
// // 	// display_stack(stack_b);

// // 	// pstr("test rrr");
// // 	// stack_a = build_stack(" 90  7 ",  0);
// // 	// stack_b = build_stack(" 0  12 1000000",  0);
// // 	// get_reverse("rrr", &stack_a, &stack_b);
// // 	// // pstr("stack a");
// // 	// // display_stack(stack_a);
// // 	// pstr("stack b");
// // 	// display_stack(stack_b);
// // 	return (0);
// // }
