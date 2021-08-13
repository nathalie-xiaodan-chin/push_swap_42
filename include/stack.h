/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:33:47 by nachin            #+#    #+#             */
/*   Updated: 2021/08/13 18:11:48 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "struct.h"

int			is_invisible_str(char *str);
void		create_and_push_value(int data, t_node **stack);
void		push_from_stack_to_stack(t_node **stack_pushed, \
			t_node **stack_received);
void		pop(t_node **stack);
void		display_stack(t_node *head);
void		display_head(t_node *stack);
void		printReverse(t_node *head);
int			is_stack_empty(t_node *stack);
t_node		*build_stack(char *str, int *stack_size);
void		delete_node(t_node **head_ref, int position);
void		find_biggest_and_smallest(t_node *list, int *min, int *max);
int			is_stack_sorted(t_node *stack);
int			stack_len(t_node *stack);
void		init_struct_stack_toolbox(t_stack_toolbox *init);

#endif
