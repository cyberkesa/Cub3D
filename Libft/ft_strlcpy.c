/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:18:47 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:18:49 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	if (!src)
		return (0);
	while (src[i] && i != (dstsize - 1))
	{
		ft_memcpy(&dst[i], &src[i], 1);
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
