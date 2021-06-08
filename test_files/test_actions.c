#include "../include/push_swap.h"

void	function_2(t_node **stack)
{
	stack = push(89, (*stack));
	display_stack(stack);

}

void	function_1(t_node **stack)
{	
	function_2(stack);

}

int		main(int argc, char **argv)
{
	printf(RED"I am the main of "PURPLE"test_actions\n"NO_COLOR);
	//to do : If no argument is given checker stops and displays nothing.

	t_node *stack_a = NULL;
	init_linked_list(stack_a);

	stack_a = build_stack_a("12 15 42",0);
	function_1(&stack_a);
	// display_stack(stack_a);
	return (0);


	// /**
	//  * test swap
	// */
	// pstr("testing sa...");
	// t_node *stack_a = NULL;
	// t_node *stack_b = NULL;
	// init_linked_list(stack_a);
	// init_linked_list(stack_b);
	
	// pstr("test sa 1...");
	// // stack_a = build_stack_a("", 0);
	// // get_swap("sa", stack_a, stack_b);
	// // display_stack(stack_a);

	// pstr("test sa 2...");
	// stack_a = build_stack_a("1 2",  0);
	// // swap_action(&stack_a);
	// pint(1);
	// get_swap("sa", &stack_a, &stack_b);
	// pint(2);
	
	// display_stack(stack_a);
	// pint(3);


	// // pstr("testing sb...");
	// // char *cmd = "sb";
	// // t_node *stack_b = NULL;
	// // stack_b = init_linked_list(stack_b);
	// // stack_b = build_stack_b("4 67 3 87 23", 0);
	// return (0);
}
