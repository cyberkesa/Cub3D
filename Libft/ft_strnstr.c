/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:17:32 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:17:33 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	size_t	nl;

	if (!(*needle) || needle == haystack)
		return ((char*)haystack);
	i = 0;
	nl = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		a = 0;
		while (haystack[i + a] == needle[a])
		{
			if (i + a > (len - 1))
				return (0);
			if (a == nl - 1)
				return (char*)(haystack + i);
			a++;
		}
		i++;
	}
	return (NULL);
}
