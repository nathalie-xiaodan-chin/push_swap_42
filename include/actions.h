/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:04:37 by nachin            #+#    #+#             */
/*   Updated: 2021/08/06 15:33:28 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H
# include "struct.h"

void	reverse_action(t_node **stack_reversed);
void	get_reverse(char *cmd, t_node **stack_a, t_node **stack_b);
void	rotate_action(t_node **stack_rotated);
void	get_rotate(char *cmd, t_node **stack_a, t_node **stack_b);
void	push_action(t_node **stack_pushed, t_node **stack_received);
void	get_push(char *cmd, t_node **stack_a, t_node **stack_b);
void	swap_action(t_node **stack);
void	get_swap(char *cmd, t_node **stack_a, t_node **stack_b);
void	get_sa_and_rra(t_node **stack_a, t_node **stack_b);
void	get_sa_and_ra(t_node **stack_a, t_node **stack_b);

#endif
