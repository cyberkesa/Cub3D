/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:13:08 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:13:09 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	const char	*lasts;
	char		*d;
	char		*lastd;

	d = dst;
	s = src;
	lasts = s + (len - 1);
	lastd = d + (len - 1);
	while (len-- && (dst != 0 || src != 0))
	{
		if (d < s)
			*d++ = *s++;
		else
			*lastd-- = *lasts--;
	}
	return (dst);
}
