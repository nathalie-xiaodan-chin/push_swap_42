/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:05:37 by nachin            #+#    #+#             */
/*   Updated: 2021/08/08 12:44:17 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

int	is_swap(char *cmd);
int	is_push(char *cmd);
int	is_rotate(char *cmd);
int	is_reverse(char *cmd);
void	swap_for_checker(char *cmd, t_node **stack_a, t_node **stack_b);
void	push_for_checker(char *cmd, t_node **stack_a, t_node **stack_b);
void	rotate_for_checker(char *cmd, t_node **stack_a, t_node **stack_b);
void	reverse_for_checker(char *cmd, t_node **stack_a, t_node **stack_b);
void	processing_checker_args(int argc, char **argv, t_node **stack_a, \
		int total_nb);
#endif
