/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:18:18 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:18:19 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				ft_freeleak(t_cub *cub)
{
	free(cub->tex[0].path);
	free(cub->tex[1].path);
	free(cub->tex[2].path);
	free(cub->tex[3].path);
	free(cub->tex[4].path);
}

void				free_array(char **r)
{
	int				i;

	i = 0;
	while (r[i])
		free(r[i++]);
	free(r);
}
