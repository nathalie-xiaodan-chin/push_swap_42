/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:54:40 by nachin            #+#    #+#             */
/*   Updated: 2021/09/10 22:57:33 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*ft_strjoin_free(char *s1, char *s2, char ctrl)
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
	if (ctrl == 'L' || ctrl == 'B')
		free(s1);
	if (ctrl == 'R' || ctrl == 'B')
		free(s2);
	return (result);
}

char	*ft_add_str(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strchr(str, '\n') != NULL)
	{
		while (str[i] != '\n')
			i++;
		i = i + 1;
		tmp = ft_substr(str, i, ft_strchr(str, '\0') - str);
	}
	else
	{
		tmp = malloc(1);
		tmp[0] = '\0';
	}
	free(str);
	return (tmp);
}
