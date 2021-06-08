#ifndef ACTIONS_H
# define ACTIONS_H
# include "struct.h"


void	reverse_action(t_node **stack_reversed);
void	get_reverse(char *cmd, t_node *stack_a, t_node *stack_b);
void	rotate_action(t_node **stack_rotated);
void	get_rotate(char *cmd, t_node *stack_a, t_node *stack_b);
void    push_action(t_node **stack_pushed, t_node **stack_received);
void	get_push(char *cmd, t_node *stack_a, t_node *stack_b);


void    swap_action(t_node **stack);
void	get_swap(char *cmd, t_node **stack_a, t_node **stack_b);



#endif
