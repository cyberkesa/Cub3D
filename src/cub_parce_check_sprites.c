/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parce_check_sprites.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:05:47 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:05:48 by vwinfred         ###   ########.fr       */
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
}

void					check_valide_pos_sprite(t_cub *cub, int x, int y)
{
	if ((cub->map[x][y + 1] == ' ' || cub->map[x][y + 1] == '\0')
	|| (cub->map[x][y - 1] == ' ' || cub->map[x][y - 1] == '\0')
	|| (cub->map[x - 1][y] == ' ' || cub->map[x - 1][y] == '\0')
	|| (cub->map[x + 1][y] == ' ' || cub->map[x + 1][y] == '\0')
	|| (cub->map[x + 1][y + 1] == ' ' || cub->map[x + 1][y + 1] == '\0')
	|| (cub->map[x - 1][y - 1] == ' ' || cub->map[x - 1][y - 1] == '\0')
	|| (cub->map[x - 1][y + 1] == ' ' || cub->map[x - 1][y + 1] == '\0')
	|| (cub->map[x + 1][y - 1] == ' ' || cub->map[x + 1][y - 1] == '\0'))
		cub_error("Error! Sprite not in map.\n", cub, TEX);
	return ;
}
