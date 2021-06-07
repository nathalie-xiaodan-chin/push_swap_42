/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:40:05 by nachin            #+#    #+#             */
/*   Updated: 2019/12/02 18:32:27 by nachin           ###   ########.fr       */
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

int		ft_minus_one(int fd, char **line, char **str)
{
	if (*str == NULL)
		*str = ft_strdup("");
	if (fd == -1)
	{
		*line = ft_strdup("");
		free(*str);
		*str = NULL;
		return (-1);
	}
	if (line == NULL || BUFFER_SIZE == 0)
	{
		free(*str);
		*str = NULL;
		return (-1);
	}
	return (0);
}

void	ft_line_and_str(char **line, char **str)
{
	if (ft_strlen(*str) > 0)
	{
		if (ft_strchr(*str, '\n') != NULL)
		{
			*line = ft_substr(*str, 0, ft_strchr(*str, '\n') - *str);
			*str = ft_add_str(*str);
		}
		else if (ft_strchr(*str, '\0') != NULL)
			*line = ft_strdup(*str);
	}
	else if (ft_strlen(*str) == 0)
		*line = ft_strdup("");
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*str = NULL;
	int			end;

	if (ft_minus_one(fd, line, &str) == -1)
		return (-1);
	end = 1;
	while (ft_strchr(str, '\n') == NULL &&
	(end = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[end] = '\0';
		str = ft_strjoin_free(str, buf, 'L');
	}
	if (end == -1)
	{
		free(str);
		str = NULL;
		return (-1);
	}
	ft_line_and_str(line, &str);
	end = end > 0 ? 1 : 0;
	end == 0 && str != NULL ? free(str) : 0;
	end == 0 && str != NULL ? str = NULL : 0;
	return (end);
}
