/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:18:18 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/03 23:14:59 by bmicheal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				ft_freeleak(t_cub *cub)
{
	int i = 0;
	while (i < 5)
	{
		free(cub->tex[i].path);
		free(cub->tex[i].image_data);
		free(cub->tex[i].image_ptr);
		i++;
	}
	free(cub->sprites);
	free(cub->sp_dist);
	free(cub->perp_for_sprites);
	free(cub->sp_order);
	free(cub->image_data);
	free(cub->mlx);
	free(cub->cub_win_ptr);
	i = 0;
	if (cub->map == NULL)
		return ;
//	while (cub->map[i])
//		free(cub->map[i++]);
	free(cub->map);
}

void				free_array(char **r)
{
	int				i;

	i = 0;
	while (r[i])
		free(r[i++]);
	free(r);
}
