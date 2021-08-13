/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:40:05 by nachin            #+#    #+#             */
/*   Updated: 2021/08/13 17:55:38 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_minus_one(int fd, char **line, char **str)
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

void	check_end_value(int end, char *str)
{
	if (end > 0)
		end = 1;
	else
		end = 0;
	if (end == 0 && str != NULL)
		free(str);
	if (end == 0 && str != NULL)
		str = NULL;
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*str = NULL;
	int			end;

	if (ft_minus_one(fd, line, &str) == -1)
		return (-1);
	end = 1;
	while (ft_strchr(str, '\n') == NULL)
	{
		end = read(fd, buf, BUFFER_SIZE);
		buf[end] = '\0';
		str = ft_strjoin_free(str, buf, 'L');
		if (end <= 0)
			break ;
	}
	if (end == -1)
	{
		free(str);
		str = NULL;
		return (-1);
	}
	ft_line_and_str(line, &str);
	check_end_value(end, str);
	return (end);
}
