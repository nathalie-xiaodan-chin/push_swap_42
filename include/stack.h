#ifndef STACK_H
# define STACK_H
# include "struct.h"

int is_invisible_str(char *str);

t_node*		init_linked_list(t_node* head);
void		push(int data, t_node** stack);
void		pop(t_node **stack);
void		display_stack(t_node* head);
void		display_head(t_node* stack);
void 		printReverse(t_node* head);
int			is_stack_empty(t_node *stack);
t_node *	build_stack(char *str, int *stack_size);
void 		delete_node(t_node **head_ref, int position); //TO BE CHANGED

int 	is_stack_sorted(t_node *stack);

#endif
