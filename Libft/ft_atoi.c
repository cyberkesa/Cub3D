/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:11:32 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:11:34 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isspace(int c)
{
	if (c == 32)
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return ((int)(result * sign));
}
