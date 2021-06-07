/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:32:57 by nachin            #+#    #+#             */
/*   Updated: 2019/11/19 13:17:52 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenght(char const *str, char const *sep)
{
	int		i;
	int		len;

	i = 0;
	while (str[i] && ft_strchr(sep, str[i]) != NULL)
		i++;
	if (str[i] == '\0')
		return (-1);
	len = 0;
	while (str[i] != '\0')
	{
		i++;
		len++;
	}
	i--;
	while (ft_strchr(sep, str[i]) != NULL)
	{
		i--;
		len--;
	}
	return (len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;
	char	*s2;
	char	*sep;
	int		len;

	str = (char *)s1;
	sep = (char *)set;
	if (!s1 || !set)
		return (NULL);
	if (ft_lenght(str, sep) == -1)
		return (ft_strdup(""));
	len = ft_lenght(str, sep);
	if (!(s2 = malloc(sizeof(*s2) * (len + 1))))
		return (NULL);
	while (*str && ft_strchr(sep, *str) != NULL)
		str++;
	i = 0;
	while (i < len)
	{
		s2[i++] = *str;
		str++;
	}
	s2[i] = '\0';
	return (s2);
}
