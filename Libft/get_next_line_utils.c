/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:10:29 by vwinfred          #+#    #+#             */
/*   Updated: 2020/12/18 18:10:31 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					find_endl(char const *s)
{
	int				i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (i);
}

char				*joinrealloc(char *s1, char *s2)
{
	char			*new;
	int				i;

	new = malloc(find_endl(s1) + find_endl(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && *s2 && *s2 != '\n')
		new[i++] = *s2++;
	new[i] = 0;
	free(s1);
	return (new);
}
