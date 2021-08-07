/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:33:56 by nachin            #+#    #+#             */
/*   Updated: 2021/08/06 20:36:08 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_node
{
	int			data;
	int			total_node;
	struct s_node	*next;
}				t_node;

typedef struct s_sorting_toolbox
{
	int			smallest_nb_value;
	int			smallest_nb_pos;
	int			biggest_nb_value;
	int			biggest_nb_pos;
	int			ith_digit_value;
	int			ith_digit_pos;
	int			current_node_value;
	int			i_node;
	int			total_node;
	int			i_chunk;
	int			n_chunk;
	int			chunk_min;
	int			chunk_max;
	int			chunk_range;
	int i_pos;
	int does_distance_refer_top;
	int min_distance_to_border ;
	int tmp_distance;
	int tmp_does_distance_refer_top;
}				t_sorting_toolbox;

typedef struct s_stack_toolbox
{
	int			i;
	int			size;
	long long	nb;
}				t_stack_toolbox;

#endif
