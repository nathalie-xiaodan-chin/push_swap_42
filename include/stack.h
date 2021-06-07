#ifndef STACK_H
# define STACK_H
# include "struct.h"


t_node*		init_linked_list(t_node* head);
t_node*		push(int data, t_node* stack);
void		pop(t_node **stack);
void	display_stack(t_node* head);
void	display_head(t_node* stack);
void printReverse(t_node* head);



#endif
