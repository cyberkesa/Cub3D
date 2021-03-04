/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:12:07 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:12:08 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

static	int		ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

int				ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
