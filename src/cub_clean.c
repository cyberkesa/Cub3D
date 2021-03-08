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
	free_array(cub->map);
}

void					cub_free_mlx(t_cub *cub)
{
	if (cub->flags.screen == 0 && cub->flags.texture_okey == 1)
		if (cub->image)
			mlx_destroy_image(cub->mlx, cub->image);
	if (cub->flags.screen == 0 && cub->flags.texture_okey == 1)
		if (cub->cub_win_ptr)
			mlx_destroy_window(cub->mlx, cub->cub_win_ptr);
	if (cub->mlx)
		free(cub->mlx);
}

void					cub_free_sprites(t_cub *cub)
{
	if (cub->val_sprites > 0)
	{
		free(cub->sprites);
		free(cub->sp_dist);
		free(cub->sp_order);
	}
}

void					cub_free_perp(t_cub *cub)
{
	free(cub->perp_for_sprites);
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
