/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:13:21 by nachin            #+#    #+#             */
/*   Updated: 2021/08/08 00:25:21 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "struct.h"

void	checking_all_nodes(t_sorting_toolbox *a, t_node **s_a, t_node **s_b);
void	sorting_four(t_node **stack_a, t_node **stack_b);
int		is_stack_sorted(t_node *stack);
void	two_nb_sort(t_node **stack_a);
void	three_nb_sort(t_node **stack_a);
void	radix_sort(t_node **stack_a, int count);
int		find_pos(t_node *list, int value);
void	find_smallest_nb(t_node *list, int *s_value, int *s_pos);
void	find_biggest_nb(t_node *list, int *b_value, int *b_pos);
void	four_nb_sort(t_node **stack_a, t_node **stack_b, int i);
void	five_nb_sort(t_node **stack_a, t_node **stack_b, int i);
void	five_or_four_nb_sort(t_node **stack_a, int count);
void	sorting_five(t_node **stack_a, t_node **stack_b);
int		get_last_value(t_node *stack);
int		insertion_sort(t_node **stack_a, int total_nb);
int		find_smallest_nb_above_x(t_node *stack, int x, int *total_node);
void	rotate_number_to_top(t_node **stack_a, int pos, int total_node);
void	multiple_rotations_on_a(t_node **stack_a, char *action, int nb_of_time);
void	insert_nb_in_middles(t_node **stack_a, t_node **stack_b);
int		insert_nb_in_extremities(t_node **stck_a, t_node **stck_b, int tot_nb);
void	multiple_rotations_on_a(t_node **stack_a, char *action, int nb_of_time);
void	insert_nb_from_b_to_a(t_node **stack_a, t_node **stack_b, int *tot_nb);
void	move_min_value_to_top(t_node **stack, int total_node);
int		compute_chunk_interval(int smallest_nb, int biggest_nb);
void	move_nb_to_b_by_chunk(t_node **stack_a, t_node **stack_b, int interval);
void	push_chunk_nbs_to_b(t_node **sa, t_node **sb, t_sorting_toolbox *the);
void	pre_sorting_stack(t_node **stack_a, t_node **stack_b);
void	multiple_push_on_b(t_node **s_a, t_node **s_b, int number_of_time);
// void	push_nb_of_chunk_to_b(t_node** stack_a, t_node** stack_b, t_sorting_toolbox *the);

void	compute_number_closest_border(int i_pos, int stack_size, int* distance, int *refers_top);
void	init_struct_sorting_toolbox(t_sorting_toolbox *init, int total_node);
void	make_positive_number(t_node **stack_a, int smallest_nb_value);
// void	push_nb_of_chunk_to_b(t_node **stack_a, t_node **stack_b, \
// 		t_sorting_toolbox *the);
void	push_nb_of_chunk_to_b(t_node** stack_a, t_node** stack_b, int chunk_min, int chunk_max);


void	compute_distance_for_pushing_nb_of_chunk_to_b(t_node **stack_a, \
		t_sorting_toolbox *the);
#endif
