/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:34:02 by nachin            #+#    #+#             */
/*   Updated: 2021/08/13 18:04:59 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLBOX_H
# define TOOLBOX_H
# include "struct.h"

int			is_invisible_char(char c);
long long	long_long_atoi(const char *str);
int			ft_check_sep(char c, char *sep);
void		ff(void);
void		pint(int integer);
void		pstr(char *str);
void		pchar(char c);
void		pfloat(float c);

#endif
