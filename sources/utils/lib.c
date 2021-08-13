/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:08:05 by nachin            #+#    #+#             */
/*   Updated: 2021/08/09 09:30:40 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int result;

	i = 0;
	neg = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
	|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	if (neg == 1)
		return (result * (-1));
	else
		return (result);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2)) + 1));
	if (result == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
		result[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		result[j++] = s2[i++];
	result[j] = '\0';
	return (result);
}

// size_t	ft_strlen(const char *s)
// {
// 	unsigned int	i;
// 	char			*str;

// 	i = 0;
// 	str = (char *)s;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

