/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:05:22 by nachin            #+#    #+#             */
/*   Updated: 2021/08/13 18:05:25 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "struct.h"

int		is_empty(char *str);
int		is_duplicate_in_stack(t_node *stack);
void	error_and_exit(void);

#endif
