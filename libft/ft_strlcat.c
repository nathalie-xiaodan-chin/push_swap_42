/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:40:55 by nachin            #+#    #+#             */
/*   Updated: 2019/11/15 18:43:26 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (dstsize < ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[i])
		i++;
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	k = i;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k + ft_strlen(src));
}
