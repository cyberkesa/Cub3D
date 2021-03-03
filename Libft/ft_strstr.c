/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:02:19 by vwinfred          #+#    #+#             */
/*   Updated: 2021/01/23 19:02:20 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	a;
	size_t	nl;
	size_t	len;

	if (!(*needle) || needle == haystack)
		return ((char*)haystack);
	len = ft_strlen(haystack);
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
