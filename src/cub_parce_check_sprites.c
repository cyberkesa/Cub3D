/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_check_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:35:19 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/04 16:35:20 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					parce_struct_sprites(t_cub *cub)
{
	int					val;
	int					x;
	int					y;

	val = 0;
	x = 0;
	while (x < cub->map_number_line && cub->map[x])
	{
		y = 0;
		while (x < cub->map_number_line && cub->map[x][y])
		{
			if (cub->map[x][y] == '2')
			{
				check_valide_pos_sprite(cub, x, y);
				cub->sprites[val].sprite_id = val;
				cub->sprites[val].pos_in_map_x = y;
				cub->sprites[val].pos_in_map_y = x;
				val++;
			}
			y++;
		}
		x++;
	}
}

void					allocate_sprites(t_cub *cub)
{
	cub->sp_order = NULL;
	cub->sp_dist = NULL;
	cub->flags.sprites_in_map = 1;
	cub->sprites = (t_sprites *)malloc(sizeof(t_sprites)
	* (cub->val_sprites + 1));
	cub->sp_order = malloc(sizeof(int) * cub->val_sprites);
	cub->sp_dist = malloc(sizeof(double) * cub->val_sprites);
	cub->perp_for_sprites = malloc(sizeof(double) * cub->width + 1);
	if (!cub->sprites)
		exit(-1);
}

void					get_sprite_val(t_cub *cub)
{
	int					x;
	int					y;

	x = 0;
	y = 0;
	while (x < cub->map_number_line && cub->map[x])
	{
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == '2')
				cub->val_sprites++;
			y++;
		}
		y = 0;
		x++;
	}
	allocate_sprites(cub);
}
