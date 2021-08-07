#include "../../include/push_swap.h"

void	free_stack(t_node *stack)
{
	t_node * tmp;

   while (stack != NULL)
    {
       tmp = stack;
       stack = stack->next;
       free(tmp);
    }

}
