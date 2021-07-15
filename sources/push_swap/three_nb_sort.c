#include "../../include/push_swap.h"


void	three_nb_sort(t_node **stack_a, int n_elem)
{
	int a;
	int b;
	int c;
	t_node * tmp = (*stack_a);

	t_node *stack_b = NULL;
	init_linked_list(stack_b);

	a = tmp->data;
	tmp = tmp->next;
	b = tmp->data;
	tmp = tmp->next;
	c = tmp->data;

	if (a > b && b < c && c > a)
	{
		get_swap("sa", stack_a, &stack_b);
	}
	else if (a > b && b > c && c < a)
	{
		get_swap("sa", stack_a, &stack_b);
		get_reverse("rra", stack_a, &stack_b);
	}
	else if (a > b && b < c && c < a)
	{
		get_rotate("ra", stack_a, &stack_b);
	}
	else if (a < b && b > c && c > a)
	{
		get_swap("sa", stack_a, &stack_b);
		get_rotate("ra", stack_a, &stack_b);
	}
	else if (a < b && b > c && c < a)
	{
		get_reverse("rra", stack_a, &stack_b);
	}

	display_stack((*stack_a));

}
