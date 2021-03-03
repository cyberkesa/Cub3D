/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:12:41 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:12:43 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*src1;
	unsigned char	*dst1;

	c1 = (unsigned char)c;
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		ft_memcpy(&dst1[i], &src1[i], 1);
		if (src1[i] == c1)
			return (&dst1[i + 1]);
		i++;
	}
	return (NULL);
}
