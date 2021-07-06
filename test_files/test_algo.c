// #include "../include/push_swap.h"

// void	radix_sort(t_node **stack_a, int n_elem)
// {
// 	// test with radix => "101 100 110 111"
// 	t_node *stack_b = NULL; //create stack b
// 	init_linked_list(stack_b);

// 	int ith_digit = 0; //index for ith-digit
// 	int ith_digit_value = 0; // value of ith-digit
// 	int max_nb = (*stack_a)->data; //find the largest number
// 	int node_value; //current node value

// 	while (1) //infinite loop. Break when the ith-digit of the largest number is 0 when >>
// 	{

// 		int i_node = 0;
// 		while (i_node < n_elem ) //second loop : check all the node of the linked list
// 		{
// 			node_value = (*stack_a)->data;

// 			if (node_value > max_nb)
// 				max_nb = node_value;

// 			ith_digit_value = (node_value >> ith_digit) % 2;
// 			if (ith_digit_value == 0) //sort even ith-digit
// 			{
// 				get_push("pb", stack_a, &stack_b);
// 			}
// 			else //sort off ith-digit
// 			{
// 				get_rotate("ra", stack_a, &stack_b);
// 			}

// 			i_node++;
// 		}

// 		while (stack_b != NULL) //put everything back from stack b to stack a
// 		{
// 			get_push("pa", stack_a, & stack_b);
// 		}

// 		ith_digit++;

// 		if (max_nb >> ith_digit == 0)
// 			break;
// 	}
// }

// int 	is_stack_sorted(t_node *stack)
// {
// 	t_node* tmp = (t_node*)malloc(sizeof(t_node));
// 	tmp = stack;

// 	t_node *next_node = NULL;
// 	next_node = stack->next;

// 	while (tmp != NULL && next_node != NULL)
// 	{
// 		if (stack->data <= next_node->data)
// 			tmp = tmp->next;
// 		else
// 		{
// 			return(0);
// 		}
// 	}
// 	return(1);
// }

// void	test_radix_sort()
// {
// 	t_node *stack = NULL;
// 	init_linked_list(stack);
// 	int n_elem = 0;
// 	stack = build_stack("3 2 4 1", &n_elem);

// 	radix_sort(&stack, n_elem);
// 	if (is_stack_sorted(stack) == 0)
// 	{
// 		display_stack(stack);
// 		pstr("stack is not sorted");
// 		exit(1);
// 	}


// }



// // char* mystrcat( char* dest, char* src )
// // {
// //      while (*dest) dest++;
// //      while (*dest++ = *src++);
// //      return --dest;
// // }





// int		main(int argc, char **argv)
// {
// 	printf(RED"I am the main of "PURPLE"test_algo\n"NO_COLOR);

// 	// t_node *stack_a = NULL;
// 	// init_linked_list(stack_a);

// 	// stack_a = build_stack("101 100 110 111", 0);

// 	// pstr("stack_a before");display_stack(stack_a);
// 	// pstr("stack_b before");display_stack(stack_b);
// 	// test_algo(&stack_a, &stack_b);
// 	// test_algo(&stack_a);
// 	// pstr("stack_a after");display_stack(stack_a);

// 	test_radix_sort();

// 	return (0);
// }




// /**
//  * DRAFT
// */

// // void test_algo(t_node **a)
// // {
// // 	// test with radix => "101 100 110 111"

// // 	t_node *stack_b = NULL;
// // 	init_linked_list(stack_b);

// // 	int nb;
// // 	t_node* new_a = (t_node*)malloc(sizeof(t_node));
// // 	new_a = (*a);

// // 	t_node* tmp = (t_node*)malloc(sizeof(t_node));
// // 	tmp = (*a);

// // 	// while (tmp != NULL)
// // 	// {
// // 	// 	tmp = tmp->next;
// // 	// }
// // 	while(tmp != NULL)
// // 	{
// // 		if (tmp->data % 2 == 0)
// // 		{
// // 			printf("modulo 0 because %d\n", tmp->data);
// // 			get_push("pb", &new_a, &stack_b);
// // 			// temp_a = temp_a->next;
// // 			// (*a) = (*a)->next;
// // 		}
// // 		// else if (tmp->data % 2 == 1)
// // 		// {
// // 		// 	printf("modulo 1 because nb = %d\n\n", tmp->data % 2);
// // 		// 	get_rotate("ra", &new_a, &new_b);
// // 		// 	// temp_a = temp_a->next;
// // 		// 	// (*a) = (*a)->next;
// // 		// }

// // 		tmp = tmp->next;

// // 	}

// // 	// while (stack_b != NULL)
// // 	// {
// // 	// 	get_push("pb", &stack_a, & stack_b);
// // 	// 	stack_b = stack_b->next;
// // 	// }

// // 	// get_rotate("ra", &temp_a, &temp_b);
// // 	// get_push("pb", &temp_a, &temp_b);

// // 	(*a) = new_a;

// // }
















// // void test_algo(t_node **a, t_node **b)
// // {

// // 	get_push("pb", a, b);
// // 	get_push("pb", a, b);
// // 	get_push("pb", a, b);
// // 	get_rotate("ra", a, b);

// // }

// // void test_algo(t_node **stack)
// // {
// // 	//Play with << and %2
// // 	// int nb = 100<<1; //100 = 1100100
// // 	// pint(nb);
// // 	// nb = 100>>1;
// // 	// pint(nb);
// // 	// nb = (100>>1)%2;
// // 	// pint(nb);
// // 	// nb = (1001%2); //1001 = 1111101001
// // 	// pint(nb);

// // 	//Play with %2
// // 	// t_node *test = (*stack);
// // 	// while (test != NULL)
// // 	// {
// // 	// 	nb = test->data;
// // 	// 	printf("dernier chiffre en binaire %d\n", nb%2);
// // 	// 	test = test->next;
// // 	// }

// // 	//test with >> and %2
// // 	// t_node *test = (*stack);
// // 	// int i = 0;
// // 	// int nb;
// // 	// while (i < 3)
// // 	// {
// // 	// 	test = (*stack);
// // 	// 	printf("i = %d\n", i);
// // 	// 	while(test != NULL)
// // 	// 	{
// // 	// 		nb = test->data>>i;
// // 	// 		pint(nb);
// // 	// 		if (nb % 2 == 0)
// // 	// 			get_rotate("ra", );
// // 	// 		else if (nb % 2 == 1)
// // 	// 			pb();
// // 	// 		// printf("dernier chiffre %d\n", nb%2);
// // 	// 		test = test->next;
// // 	// 	}
// // 	// 	i++;
// // 	// }






// // 	//test with radix
// // 	t_node *stack_a = (*stack);
// // 	t_node *stack_b = NULL;
// // 	init_linked_list(stack_b);

// // 	int i = 0;
// // 	int nb;
// // 	while (i < 1)
// // 	{
// // 		stack_a = (*stack);
// // 		printf("i = %d\n", i);
// // 		while(stack_a != NULL)
// // 		{
// // 			// nb = stack_a->data>>i;
// // 			nb = stack_a->data;
// // 			if (nb % 2 == 0)
// // 			{
// // 				printf("modulo 0\n");
// // 				get_rotate("pb", &stack_a, &stack_b);
// // 			}
// // 			else if (nb % 2 == 1)
// // 			{
// // 				printf("modulo 1\n");
// // 				get_push("ra", &stack_a, &stack_b);
// // 			}
// // 			// printf("dernier chiffre %d\n", nb%2);
// // 			while (stack_b != NULL)
// // 			{
// // 				get_push("pb", &stack_a, & stack_b);
// // 				stack_b = stack_b->next;
// // 			}
// // 			stack_a = stack_a->next;
// // 		}
// // 		i++;
// // 		display_stack(stack_a);
// // 		display_stack(stack_b);
// // 	}

// // }









// // void test_algo(t_node **stack)
// // {
// // 	//Play with << and %2
// // 	int nb = 100<<1; //100 = 1100100
// // 	pint(nb);
// // 	nb = 100>>1;
// // 	pint(nb);
// // 	nb = (100>>1)%2;
// // 	pint(nb);
// // 	nb = (1001%2); //1001 = 1111101001
// // 	pint(nb);

// // 	//Play with %2
// // 	// t_node *test = (*stack);
// // 	// while (test != NULL)
// // 	// {
// // 	// 	nb = test->data;
// // 	// 	printf("dernier chiffre en binaire %d\n", nb%2);
// // 	// 	test = test->next;
// // 	// }

// // 	//test with >> and %2
// // 	// t_node *test = (*stack);
// // 	// int i = 0;
// // 	// int nb;
// // 	// while (i < 3)
// // 	// {
// // 	// 	test = (*stack);
// // 	// 	printf("i = %d\n", i);
// // 	// 	while(test != NULL)
// // 	// 	{
// // 	// 		nb = test->data>>i;
// // 	// 		pint(nb);
// // 	// 		if (nb % 2 == 0)
// // 	// 			get_rotate("ra", );
// // 	// 		else if (nb % 2 == 1)
// // 	// 			pb();
// // 	// 		// printf("dernier chiffre %d\n", nb%2);
// // 	// 		test = test->next;
// // 	// 	}
// // 	// 	i++;
// // 	// }
// // }
