/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:14:23 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:14:24 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		**free_leak(char **arr)
{
	unsigned int	l;

	l = 0;
	while (arr[l])
	{
		free(arr[l]);
		l++;
	}
	free(arr);
	return (NULL);
}

static	size_t		words_x(char const *s, char c)
{
	size_t			words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static	void		next(char **line, unsigned int *len,
					char c)
{
	unsigned int	i;

	*line = *line + *len;
	*len = 0;
	i = 0;
	while (**line && **line == c)
		(*line)++;
	while ((*line)[i])
	{
		if ((*line)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char				**ft_split(char const *s, char c)
{
	char			**arr;
	char			*line;
	unsigned int	len;
	unsigned int	words;
	unsigned int	i;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	words = words_x(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!(arr))
		return (NULL);
	line = (char *)s;
	while (i < words)
	{
		next(&line, &len, c);
		if (!(arr[i] = malloc(sizeof(char) * (len + 1))))
			return (free_leak(arr));
		ft_strlcpy(arr[i], line, len + 1);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
