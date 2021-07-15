#include "../../include/push_swap.h"



void	radix_sort(t_node **stack_a, int n_elem)
{
	// test with radix => "101 100 110 111"
	t_node *stack_b = NULL; //create stack b
	init_linked_list(stack_b);

	int ith_digit = 0; //index for ith-digit
	int ith_digit_value = 0; // value of ith-digit
	int max_nb = (*stack_a)->data; //find the largest number
	int node_value; //current node value

	while (1) //infinite loop. Break when the ith-digit of the largest number is 0 when >>
	{

		int i_node = 0;
		while (i_node < n_elem ) //second loop : check all the node of the linked list
		{
			node_value = (*stack_a)->data;

			if (node_value > max_nb)
				max_nb = node_value;

			ith_digit_value = (node_value >> ith_digit) % 2;
			if (ith_digit_value == 0) //sort even ith-digit
			{
				get_push("pb", stack_a, &stack_b);
			}
			else //sort off ith-digit
			{
				get_rotate("ra", stack_a, &stack_b);
			}

			i_node++;
		}

		while (stack_b != NULL) //put everything back from stack b to stack a
		{
			get_push("pa", stack_a, & stack_b);
		}

		ith_digit++;

		if (max_nb >> ith_digit == 0)
			break;
	}
}


void	test_radix_sort(char *list_nb)
{
	t_node *stack = NULL;
	init_linked_list(stack);
	int n_elem = 0;
	stack = build_stack(list_nb, &n_elem);
	// display_stack(stack);
	radix_sort(&stack, n_elem);
	if (is_stack_sorted(stack) == 0)
	{
		display_stack(stack);
		pstr("stack is not sorted");
		exit(1);
	}
	// printf("\nsorted stack\n");display_stack(stack);


}
