/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:14:51 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:14:52 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	max;
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = lendst;
	max = dstsize - ft_strlen(dst);
	if (dstsize != 0 && lendst < dstsize)
	{
		while (--max && lensrc != 0 && *src && dst != '\0')
		{
			dst[i] = *src++;
			i++;
		}
		dst[i] = '\0';
	}
	if (dstsize < lendst)
		return (lensrc + dstsize);
	return (lensrc + lendst);
}
