/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:04:23 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:04:24 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					cub_free_map(t_cub *cub)
{
	if (cub->flags.parce_map_start == 1 && cub->plr.nswe == 1)
		free_array(cub->map);
}

void					cub_free_mlx(t_cub *cub)
{
	if (cub->image_data)
		free(cub->image_data);
	if (cub->mlx)
		free(cub->mlx);
	if (cub->cub_win_ptr)
		free(cub->cub_win_ptr);
	if (cub->flags.screen == 0 && cub->flags.texture_okey == 1)
		if (cub->image)
			mlx_destroy_image(cub->mlx, cub->image);
	if (cub->flags.screen == 0 && cub->flags.texture_okey == 1)
		if (cub->cub_win_ptr)
			mlx_destroy_window(cub->mlx, cub->cub_win_ptr);
}

void					cub_free_sprites(t_cub *cub)
{
	if (cub->val_sprites > 0)
	{
		free(cub->sprites);
		free(cub->sp_dist);
		free(cub->perp_for_sprites);
		free(cub->sp_order);
	}
}

void					cub_free_color(t_cub *cub)
{
	printf("%d\n", cub->flags.ceiling_color_ok);
	// if (cub->flags.ceiling_color_ok)
	// 	free(cub->ceiling_color);
	// if (cub->flags.floor_color_ok)
	// 	free(cub->floor_color);
	return ;
}

void					cub_free_textures(t_cub *cub)
{
	int					i;

	i = 0;
	if (cub->flags.texture_okey == 1)
		while (i < 5)
		{
			free(cub->tex[i].path);
			free(cub->tex[i].image_data);
			free(cub->tex[i].image_ptr);
			i++;
		}
}

void					free_array(char **r)
{
	size_t				i;

	i = 0;
	while (r[i])
		free(r[i++]);
	free(r);
}
