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


// int		main(int argc, char **argv)
// {
// 	char * list_nb = argv[1];
// 	printf("%s\n", argv[1]);


// 	// test_radix_sort(list_nb);

// 	t_node *stack = NULL;
// 	init_linked_list(stack);

// 	int total_nb = 0;
// 	stack = build_stack(list_nb, &total_nb);

// 	pint(total_nb);


// 	if (total_nb <= 3)
// 	{
// 		three_nb_sort(&stack, total_nb);
// 	}
// 	else if (total_nb > 500)
// 	{
// 		radix_sort(&stack, total_nb);
// 	}
// 	else
// 	{
// 		return (0);
// 	}

// 	return (0);
// }




/**
 * DRAFT
*/



	// int i = 0;
	// while (i < 10001)
	// {
	// 	printf("sa\n");
	// 	i++;
	// }
