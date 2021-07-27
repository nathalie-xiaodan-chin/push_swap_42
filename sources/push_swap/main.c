#include "../../include/push_swap.h"

int 	is_stack_sorted(t_node *stack)
{
	t_node* tmp = (t_node*)malloc(sizeof(t_node));
	tmp = stack;

	t_node *next_node = NULL;
	next_node = stack->next;

	while (tmp != NULL && next_node != NULL)
	{
		if (stack->data <= next_node->data)
			tmp = tmp->next;
		else
		{
			return(0);
		}
	}
	return(1);
}


int		main(int argc, char **argv)
{
	char * list_nb = argv[1];
	// printf("%s\n", argv[1]);



	t_node *stack = NULL;
	init_linked_list(stack);

	int total_nb = 0;

	// stack = build_stack(list_nb, &total_nb);
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else if (argc == 2)
	{
		stack = build_stack(list_nb, &total_nb);
	}
	else if (argc > 2)
	{
		int i = 1;
		while (i != argc)
		{
			// printf("%s\n", argv[i]);
			list_nb = ft_strjoin(list_nb, " ");
			list_nb = ft_strjoin(list_nb, argv[i]);
			i++;
		}
		stack = build_stack(list_nb, &total_nb);
	}

	//if one or two ?
	if (total_nb <= 3)
	{
		three_nb_sort(&stack, total_nb);
	}
	else if (total_nb <= 5)
	{
		five_or_four_nb(&stack, total_nb);
	}
	else if (total_nb > 500)
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
