/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:13:30 by nachin            #+#    #+#             */
/*   Updated: 2021/08/11 16:23:40 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	if (src == NULL && dst == NULL)
		return (0);
	while ((src[i] != '\0') && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*str;
	char			*dest;

	i = 0;
	str = (char *)s1;
	dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		// if ((dst = malloc(sizeof(char) * (len + 1))) == NULL)
		(dst = malloc(sizeof(char) * (len + 1)));
		if (dst == NULL)
			return (NULL);
		ft_strlcpy(dst, s + start, len + 1);
		return (dst);
	}
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}
