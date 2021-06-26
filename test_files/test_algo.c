// #include "../include/push_swap.h"


// // void test_algo(t_node **a, t_node **b)
// // {
// // 	// test with radix
// // 	int nb;

// // 	while((*a) != NULL)
// // 	{
// // 		nb = (*a)->data;
// // 		if (nb % 2 == 0)
// // 		{
// // 			printf("modulo 0\n");
// // 			// get_push("pb", a, b);
// // 		}
// // 		else if (nb % 2 == 1)
// // 		{
// // 			printf("modulo 1\n");
// // 			// get_rotate("ra", a, b);
// // 		}

// // 		(*a) = (*a)->next;
// // 	}
// // 	pstr("stack_a after test_algo");display_stack(*a);
// // 	pstr("stack_b after test_algo");display_stack(*b);
// // 	// while (stack_b != NULL)
// // 	// {
// // 	// 	get_push("pb", &stack_a, & stack_b);
// // 	// 	stack_b = stack_b->next;
// // 	// }
// // }

// void test_algo(t_node **a, t_node **b)
// {

// 	get_push("pb", a, b);
// 	get_push("pb", a, b);
// 	get_push("pb", a, b);
// 	get_rotate("ra", a, b);

// }



// int		main(int argc, char **argv)
// {
// 	printf(RED"I am the main of "PURPLE"test_algo\n"NO_COLOR);

// 	t_node *stack_a = NULL;
// 	init_linked_list(stack_a);
// 	t_node *stack_b = NULL;
// 	init_linked_list(stack_b);
// 	stack_a = build_stack("101 100 110 111", 0);
// 	test_algo(&stack_a, &stack_b);
// 	pstr("stack_a");display_stack(stack_a);
// 	pstr("stack_b");display_stack(stack_b);

// 	return (0);
// }




// /**
//  * DRAFT
// */


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
