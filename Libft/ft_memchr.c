/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:12:50 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:12:51 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (arr[i] == (unsigned char)c)
			return (&arr[i]);
		i++;
	}
	return (NULL);
}
