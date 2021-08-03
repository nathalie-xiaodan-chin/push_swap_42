#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	char * list_nb;
	t_node *stack = NULL;
	init_linked_list(stack);

	int total_nb = 0;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else if (argc == 2)
	{
		list_nb = argv[1];
		stack = build_stack(list_nb, &total_nb);
		if (stack->next == NULL) //if its only one nb
			exit(1);
		// display_stack(stack);
	}
	else if (argc > 2)
	{
		int i = 1;
		list_nb = "";
		while (i != argc -1)
		{
			// printf("%s\n", argv[i]);

			list_nb = ft_strjoin(list_nb, argv[i]);
			list_nb = ft_strjoin(list_nb, " ");
			i++;
		}
		list_nb = ft_strjoin(list_nb, argv[i]);

		stack = build_stack(list_nb, &total_nb);
	}
		// pint(total_nb);

	//if one or two ?
	if (total_nb == 1){
		return(0);
	}
	else if(total_nb == 2){
		two_value_sort(&stack, total_nb);
	}
	else if (total_nb == 3)
	{
		three_nb_sort(&stack);

	}
	else if (total_nb <= 5)
	{
		five_or_four_nb(&stack, total_nb);
	}
	else if (total_nb <= 100)
	{
		insertion_sort(&stack, total_nb);
		// radix_sort(&stack, total_nb);
	}
	else if (total_nb > 100)
	{
		radix_sort(&stack, total_nb);
	}
	else
	{
		return (0);
	}
	// display_stack(stack);
	return (0);
}




/**
 * DRAFT
*/



// 	// int i = 0;
// 	// while (i < 10001)
// 	// {
// 	// 	printf("sa\n");
// 	// 	i++;
// 	// }
