// #include "../include/push_swap.h"

// void test_is_duplicate_in_stack(){

// 	pstr("test is_duplicate_in_stack");
// 	t_node *stack = NULL;
// 	init_linked_list(stack);

// 	push(2, &stack);
// 	push(1, &stack);

// 	if (is_duplicate_in_stack(stack))
// 	{
// 		printf(
// 			"\n %d is_duplicate_in_stack should return 0 and now it return %d \n",
// 			__LINE__,
// 			is_duplicate_in_stack(stack)
// 		);
// 		exit(1);
// 	}

// 	push(2, &stack);
// 	if (! is_duplicate_in_stack(stack))
// 	{
// 		printf(
// 			"\n %d is_duplicate_in_stack should return 1 and now it return %d \n",
// 			__LINE__,
// 			is_duplicate_in_stack(stack)
// 		);
// 		exit(1);
// 	}

// 	stack = NULL;
// 	init_linked_list(stack);
// 	push(1, &stack);
// 	push(0, &stack);

// 	if (is_duplicate_in_stack(stack))
// 	{
// 		printf(
// 			"\n %d is_duplicate_in_stack should return 0 and now it return %d \n",
// 			__LINE__,
// 			is_duplicate_in_stack(stack)
// 		);
// 		exit(1);
// 	}

// }


// void test_build_stack(){
// 	char* str_values = "0 1";
// 	int size;
// 	t_node* stack = build_stack(str_values, &size);

// 	if (stack->data != 0)
// 	{
// 		printf(
// 			"\n %d build_stack issue : 1st node should be 0 and now is %d \n",
// 			__LINE__,
// 			stack->data);
// 		exit(1);
// 	}

// 	char* str_values2 = "3 -2 -9 13 6 5";
// 	stack = build_stack(str_values2, &size);

// 	if (stack->next->data != -2 || stack->next->next->data != -9)
// 	{
// 		printf(
// 			"build_stack issue : 2nd node should be -2 and is %i\n 3rd should be -9 and is %i",
// 			  stack->next->data,
// 			  stack->next->next->data
// 			);
// 		exit(1);
// 	}

// }

// int		main(int argc, char **argv)
// {

// 	pstr("Tests...");
// 	test_is_duplicate_in_stack();
// 	test_build_stack();
// 	// int i = 0;
// 	// int j = 0;
// 	// while (i < argc)
// 	// {
// 	// 	j = 0;
// 	// 	while (argv[i][j] != '\0')
// 	// 	{
// 	// 		printf("%c\n", argv[i]);
// 	// 		j++;
// 	// 	}

// 	// 	i++;
// 	// }

// 	// pstr(argv[0]); //1
// 	// pstr(argv[1]); //2
// 	// pstr(argv[2]); //3





// 	// pint(argc);


// 	// t_node *stack = NULL;
// 	// init_linked_list(stack);
// 	// char *str = "";
// 	// int * size = 0;
// 	// if (argc == 1)
// 	// {
// 	//  	pstr("no stack \n");
// 	// 	exit(1);
// 	// }
// 	// else if (argc == 2)
// 	// {
// 	//  	pstr("argc 2");
// 	// 	stack = build_stack(argv[1], &size);
// 	// }
// 	// else if (argc > 2)
// 	// {
// 	// 	int i = 1;
// 	// 	while (i != argc)
// 	// 	{
// 	// 		// printf("%s\n", argv[i]);
// 	// 		str = ft_strjoin(str, " ");
// 	// 		str = ft_strjoin(str, argv[i]);
// 	// 		i++;
// 	// 	}
// 	// 	stack = build_stack(str, &size);
// 	// }
// 	// char *str1 = "hello";
// 	// char *str2 = "fuck";
// 	// char *res = NULL;
// 	// str1 = ft_strjoin(str1, " ");
// 	// res = ft_strjoin(str1, str2);
// 	// printf("%s\n", str);

// 	// display_stack(stack);


// 	//decomment below

// 	char* str;

// 	// str = "";
// 	// if (is_error(str) != 1)
// 	// {
// 	// 	printf("\n %d is_error should return 0 and now it return 1\n", __LINE__);
// 	// }

// 	// str = NULL;
// 	// if (is_error(str) != 1)
// 	// {
// 	// 	printf("\n %d is_error should return 0 and now it return 1\n", __LINE__);
// 	// }



// 	// stack = build_stack("1  0 2      ", &size);
// 	// if (is_duplicate_in_stack(stack) != 0)
// 	// {
// 	// 	printf("\n %d is_duplicate_in_stack should return 0 and now it return %d \n", __LINE__, is_duplicate_in_stack(stack));
// 	// }

// 	// stack = build_stack("1  0 2 3 4 10 11 12 111 1111111 111111 22222", &size);
// 	// if (is_duplicate_in_stack(stack) != 0)
// 	// {
// 	// 	printf("\n %d is_duplicate_in_stack should return 0 and now it return %d \n", __LINE__, is_duplicate_in_stack(stack));
// 	// }

// 	// stack = build_stack("11", &size);
// 	// if (is_duplicate_in_stack(stack) != 0)
// 	// {
// 	// 	printf("\n %d is_duplicate_in_stack should return 0 and now it return %d \n", __LINE__, is_duplicate_in_stack(stack));
// 	// }

// 	// stack = build_stack("11 1", &size);
// 	// if (is_duplicate_in_stack(stack) != 0)
// 	// {
// 	// 	printf("\n %d is_duplicate_in_stack should return 0 and now it return %d \n", __LINE__, is_duplicate_in_stack(stack));
// 	// }

// 	// stack = build_stack("11 1 1", &size);
// 	// if (is_duplicate_in_stack(stack) != 1)
// 	// {
// 	// 	printf("\n %d is_duplicate_in_stack should return 1 and now it return %d \n", __LINE__, is_duplicate_in_stack(stack));
// 	// }

// 	// stack = build_stack("1 1", &size);
// 	// if (is_duplicate_in_stack(stack) != 1)
// 	// {
// 	// 	printf("\n %d is_duplicate_in_stack should return 1 and now it return %d \n", __LINE__, is_duplicate_in_stack(stack));
// 	// }


// 	// size = 0;
// 	// stack = build_stack("1 2147483647 0", &size);
// 	// if (is_max_int_in_stack(stack) != 1)
// 	// {
// 	// 	printf("\n %d is_max_int_in_stack should return 0 and now it return 1\n", __LINE__);
// 	// }


// 	// size = 0;
// 	// stack = build_stack("1 2147483648 0", &size);
// 	// if (is_max_int_in_stack(stack) != 1)
// 	// {
// 	// 	printf("\n %d is_max_int_in_stack should return 1 and now it return 0\n", __LINE__);
// 	// }


// 	// size = 0;
// 	// stack = build_stack("1 4000000000 0", &size);
// 	// if (is_max_int_in_stack(stack) != 1)
// 	// {
// 	// 	printf("\n %d is_max_int_in_stack should return 1 and now it return 0\n", __LINE__);
// 	// }


// 	// size = 0;
// 	// // stack = build_stack("1 4000000000 0", &size);
// 	// // stack = build_stack("1 2147483648 0", &size);
// 	// stack = build_stack("19223372036854775806 0", &size);

// 	// long int nb;
// 	// nb = 4000000000;
// 	// nb = 2147483648;

// 	// printf("test lu %ld \n", nb);
// 	// if (nb > 2147483647 || nb < -2147483648)
// 	// 	pstr("stop");





// 	// str = """ 2";
// 	// if (is_error(str) != 1)
// 	// {
// 	// 	printf("\n %d is_error should return 0 and now it return 1\n", __LINE__);
// 	// }



// 	return (0);
// }


// /**
//  * DRAFT
// */

// 	// str = "123";
// 	// if (is_duplicate(str) != 0)
// 	// {
// 	// 	printf("\n %d duplicate should return 0 and now it return 1\n", __LINE__);
// 	// }

// 	// str = "1231";
// 	// if (is_duplicate(str) != 1)
// 	// {
// 	// 	printf("\n %d duplicate should return 0 and now it return 1\n", __LINE__);
// 	// }

// 	// str = "12222231";
// 	// if (is_duplicate(str) != 1)
// 	// {
// 	// 	printf("\n %d duplicate should return 0 and now it return 1\n", __LINE__);
// 	// }

// 	// str = "1 1";
// 	// if (is_duplicate(str) != 1)
// 	// {
// 	// 	printf("\n %d duplicate should return 0 and now it return 1\n", __LINE__);
// 	// }

// 	// str = "5 1 3 4 2 0 0";
// 	// if (is_duplicate(str) != 1)
// 	// {
// 	// 	printf("\n %d duplicate should return 0 and now it return 1\n", __LINE__);
// 	// }

// 	// str = "5 0 0";
// 	// if (is_duplicate(str) != 1)
// 	// {
// 	// 	printf("\n %d duplicate should return 0 and now it return 1\n", __LINE__);
// 	// }

// 	// str = "5 1 3 4 2 0";
// 	// if (is_duplicate(str) != 0)
// 	// {
// 	// 	printf("\n %d duplicate should return 0 and now it return 1\n", __LINE__);
// 	// }


















// // // //find the smallest nb
// // // //find the biggest nb

// // // int		find_pos(t_node * list, int value)
// // // {
// // // 	t_node *tmp = NULL;
// // // 	tmp = list;
// // // 	int i = 0;
// // // 	while(tmp != NULL)
// // // 	{
// // // 		if (tmp->data != value)
// // // 		{
// // // 			tmp = tmp->next;
// // // 			i++;
// // // 		}
// // // 		else
// // // 			break;
// // // 	}
// // // 	return(i);
// // // }
// // // void		find_smallest_nb(t_node *list, int *s_value, int *s_pos, int biggest_nb)
// // // {
// // // 	t_node *tmp = NULL;
// // // 	tmp = list;
// // // 	int smallest_value =  biggest_nb;
// // // 	int smallest_pos = 0;
// // // 	// pint(smallest_value);

// // // 	while(tmp != NULL)
// // // 	{
// // // 		// pint(tmp->data);
// // // 		if (tmp->data < smallest_value)
// // // 		{
// // // 			smallest_value = tmp->data;
// // // 			smallest_pos++;
// // // 		}
// // // 		tmp = tmp->next;
// // // 	}
// // // 	*s_value = smallest_value;
// // // 	*s_pos = find_pos(list, smallest_value);
// // // }

// // // void		find_biggest_nb(t_node *list, int *b_value, int *b_pos)
// // // {
// // // 	int biggest_nb_value = 0;
// // // 	int biggest_nb_pos = 0;

// // // 	t_node *tmp = NULL;
// // // 	tmp = list;
// // // 	while(tmp != NULL)
// // // 	{
// // // 		if (tmp->data > biggest_nb_value)
// // // 		{
// // // 			biggest_nb_value = tmp->data;
// // // 			biggest_nb_pos++;
// // // 		}
// // // 		tmp = tmp->next;
// // // 	}
// // // 	// *b_pos = biggest_nb_pos;
// // // 	*b_value = biggest_nb_value;
// // // 	*b_pos = find_pos(list, biggest_nb_value);

// // // }


// // // void	four_nb_sort(t_node **stack_a, t_node**stack_b, int i)
// // // {
// // // 	if (i == 0)
// // // 	{
// // // 		get_push("pb", stack_a, stack_b);
// // // 	}
// // // 	else if (i == 1)
// // // 	{
// // // 		get_rotate("ra",stack_a, stack_b);
// // // 		get_push("pb", stack_a, stack_b);
// // // 	}
// // // 	else if (i == 2)
// // // 	{
// // // 		get_rotate("ra",stack_a, stack_b);
// // // 		get_rotate("ra",stack_a, stack_b);
// // // 		get_push("pb", stack_a, stack_b);
// // // 	}
// // // 	else if (i == 3)
// // // 	{
// // // 		get_reverse("rra",stack_a, stack_b);
// // // 		get_push("pb", stack_a, stack_b);
// // // 	}
// // // }

// // // void	five_nb_sort(t_node **stack_a, t_node**stack_b, int i)
// // // {
// // // 	if (i == 0)
// // // 	{
// // // 		get_push("pb", stack_a, stack_b);
// // // 	}
// // // 	else if (i == 1)
// // // 	{
// // // 		get_rotate("ra",stack_a, stack_b);
// // // 		get_push("pb", stack_a, stack_b);
// // // 	}
// // // 	else if (i == 2)
// // // 	{
// // // 		get_rotate("ra",stack_a, stack_b);
// // // 		get_rotate("ra",stack_a, stack_b);
// // // 		get_push("pb", stack_a, stack_b);
// // // 	}
// // // 	else if (i == 3)
// // // 	{
// // // 		get_rotate("rra",stack_a, stack_b);
// // // 		get_rotate("rra",stack_a, stack_b);
// // // 		get_push("pb", stack_a, stack_b);
// // // 	}
// // // 	else if (i == 4)
// // // 	{
// // // 		get_reverse("rra",stack_a, stack_b);
// // // 		get_push("pb", stack_a, stack_b);
// // // 	}
// // // }



// // int		main()
// // {
// // 	t_node* stack_a = NULL;
// // 	init_linked_list(stack_a);

// // 	t_node *stack_b = NULL;
// // 	init_linked_list(stack_b);

// // 	int count = 0; //starting from 1
// // 	// stack_a = build_stack("10 12 42  15 10000", &count);
// // 	// stack_a = build_stack("11 12 14 10 13", &count);
// // 	// stack_a = build_stack("10 12 14 13 11", &count);
// // 	// stack_a = build_stack("10 11 14 13 12", &count); //hardest for 5
// // 	stack_a = build_stack("2 1 3 5 ", &count);

// // 	int smallest_nb_value = 0;
// // 	int smallest_nb_pos = 0; //starting from 0

// // 	int biggest_nb_value = 0;
// // 	int biggest_nb_pos = 0; //starting from 0

// // 	if (count <= 3)
// // 	{
// // 		three_nb_sort(&stack_a, count);
// // 	}
// // 	else if (count == 4)
// // 	{
// // 		find_biggest_nb(stack_a, &biggest_nb_value, &biggest_nb_pos);
// // 		find_smallest_nb(stack_a, &smallest_nb_value, &smallest_nb_pos, biggest_nb_value);
// // 		four_nb_sort(&stack_a, &stack_b, smallest_nb_pos);
// // 		three_nb_sort(&stack_a, count);
// // 		get_push("pa", &stack_a, &stack_b);
// // 	}
// // 	else if (count == 5)
// // 	{
// // 		find_biggest_nb(stack_a, &biggest_nb_value, &biggest_nb_pos);
// // 		// pint(biggest_nb_pos);
// // 		five_nb_sort(&stack_a, &stack_b, biggest_nb_pos);
// // 		find_smallest_nb(stack_a, &smallest_nb_value, &smallest_nb_pos, biggest_nb_value);
// // 		four_nb_sort(&stack_a, &stack_b, smallest_nb_pos);
// // 		// printf("stack_a :\n");display_stack(stack_a);
// // 		three_nb_sort(&stack_a, count);
// // 		//push biggest nb and smallest nb
// // 		get_push("pa", &stack_a, &stack_b);
// // 		get_push("pa", &stack_a, &stack_b);
// // 		get_rotate("ra", &stack_a, &stack_b);
// // 	}
// // 	else if (count > 5)
// // 	{
// // 		radix_sort(&stack_a, count);
// // 	}

// // 	// "12 15 42 10 10000"

// // 	// printf("smallest nb value: %d\n", smallest_nb_value);
// // 	// printf("smallest nb pos: %d\n", smallest_nb_pos);
// // 	// printf("biggest nb value: %d\n", biggest_nb_value);
// // 	// printf("biggest nb pos: %d\n", biggest_nb_pos);


// // 	// push(biggest_nb_value, &stack_b);
// // 	// push(smallest_nb_value, &stack_b);

// // 	// printf("stack_a :\n");display_stack(stack_a);
// // 	// printf("stack_b :\n");display_stack(stack_b);

// // 	// three_nb_sort(&stack_a, count);
// // 	// push(stack_b->data, &stack_a);
// // 	// pop(&stack_b);

// // 	printf("stack_a :\n");display_stack(stack_a);
// // 	printf("stack_b :\n");display_stack(stack_b);


// // 	return(0);
// // }


