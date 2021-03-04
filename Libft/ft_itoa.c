/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:12:33 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:12:34 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len(long l)
{
	int		len;

	len = 0;
	if (l < 0)
	{
		l *= -1;
		len++;
	}
	if (l == 0)
	{
		return (1);
	}
	while (l > 0)
	{
		l /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*array;
	long	l;
	int		i;

	l = n;
	i = len(l);
	if (!(array = (char*)malloc(sizeof(char) * (i + 1) + (l <= 0 ? 0 : 1))))
		return (NULL);
	array[i--] = '\0';
	if (l == 0)
		array[0] = 48;
	if (l < 0)
	{
		array[0] = '-';
		l = l * -1;
	}
	while (l > 0)
	{
		array[i] = 48 + (l % 10);
		l = l / 10;
		i--;
	}
	return (array);
}
