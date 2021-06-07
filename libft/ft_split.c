/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachin <nachin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:43:36 by nachin            #+#    #+#             */
/*   Updated: 2019/11/18 16:44:01 by nachin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char *str, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	//parcourir la string pour compter le nb de mots (sans separateur)
	while (str[i])
	{
		if (str[i] != c && i == 0)//pour compter le 1er mot
		{
			word++;
			i++;
		}
		if (str[i] != c && str[i - 1] == c)//pour compter les autres mots
			word++;
		i++;
	}
	return (word);
}

static int		ft_len_word(char *str, char c)
{
	int		len;

	len = 0;
	while (str[len])
	{
		if (str[len] != c)
			len++; //calculate the lenght of 1 line of the array
		else
			break ;
	}
	return (len);
}

static char		**ft_free(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static	char	*ft_dup(char *src, char c)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = ft_len_word(src, c);
	if ((dst = malloc(sizeof(*src) * (len + 1))) == NULL)
		return (NULL);
	while (src[i] && i < len) //copy each word into 1 line
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char	*str;
	char	**tab;
	int		words;
	int		i;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	words = ft_count_word(str, c); 	//compter le nb total de mots dans la string (sans separateur)
	if ((tab = ft_calloc(words + 1, sizeof(*tab))) == NULL)
		return (NULL);
	tab[words] = NULL;
	i = 0;
	while (*str)
		if (*str != c) 
		{
			if ((tab[i] = ft_dup(str, c)) == NULL) //malloc each line + protect your malloc 
				return (ft_free(tab));
			i++;
			str += ft_len_word(str, c); //str = ft_len_word(str, c) + str; // str avance 
		}
		else
			str++;
	return (tab);
}
