/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:39:45 by nachin            #+#    #+#             */
/*   Updated: 2019/11/15 19:02:51 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long nb_lenght)
{
	int lenght;

	lenght = 0;
	if (nb_lenght == 0)
		lenght = 1;
	if (nb_lenght < 0)
	{
		nb_lenght = nb_lenght * (-1);
		lenght = lenght + 1;
	}
	while (nb_lenght > 0)
	{
		nb_lenght = nb_lenght / 10;
		lenght++;
	}
	return (lenght);
}

char			*ft_itoa(int nb)
{
	char	*number;
	int		lenght;
	int		sign;
	long	nb_long;

	nb_long = nb;
	lenght = ft_len(nb_long);
	sign = 0;
	if ((number = malloc(sizeof(char) * (lenght + 1))) == NULL)
		return (NULL);
	number[lenght] = '\0';
	if (nb_long < 0)
	{
		nb_long = nb_long * (-1);
		sign = 1;
	}
	while (--lenght >= 0)
	{
		number[lenght] = ((nb_long % 10) + 48);
		nb_long = nb_long / 10;
	}
	if (sign == 1)
		number[0] = '-';
	return (number);
}
