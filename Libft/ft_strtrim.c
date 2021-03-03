/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:20:01 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:20:02 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_set(char s, char const *set, size_t lenset)
{
	size_t	i;

	i = 0;
	while (i < lenset)
	{
		if (s == set[i])
			return (1);
		if (s != set[i])
			i++;
	}
	return (0);
}

static	int	end_pos(char const *s1, char const *set)
{
	size_t	lenset;
	size_t	i;
	size_t	a;

	a = 0;
	lenset = ft_strlen(set);
	i = ft_strlen(s1);
	while (i-- && is_set(s1[i], set, lenset) != 0)
		a++;
	return (ft_strlen(s1) - a);
}

static	int	s_pos(char const *s1, char const *set)
{
	size_t	lenset;
	size_t	i;

	i = 0;
	lenset = ft_strlen(set);
	while (is_set(s1[i], set, lenset) != 0)
		i++;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;

	if (!s1)
		return (NULL);
	res = ft_substr(s1, s_pos(s1, set), end_pos(s1, set) - s_pos(s1, set));
	return (res);
}
