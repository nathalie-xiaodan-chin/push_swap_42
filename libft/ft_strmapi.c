/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:58:18 by nachin            #+#    #+#             */
/*   Updated: 2019/11/15 19:08:28 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*dest;
	unsigned int	index;

	str = (char *)s;
	index = 0;
	if (str == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == NULL)
		return (NULL);
	while (str[index] != '\0')
	{
		dest[index] = f(index, str[index]);
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
