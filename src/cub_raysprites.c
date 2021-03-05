/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raysprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:07:18 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:07:19 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					sprite_math(t_cub *cub)
{
	cub->spr.sprite_x = cub->sprites
	[cub->sp_order[cub->spr.loop_sprites]].x - cub->plr.x;
	cub->spr.sprite_y = cub->sprites
	[cub->sp_order[cub->spr.loop_sprites]].y - cub->plr.y;
	cub->spr.invdet = 1.0 /
	(cub->ray.plane_x * cub->ray.dir_y - cub->ray.dir_x
	* cub->ray.plane_y);
	cub->spr.tr_x = -cub->spr.invdet
	* (cub->ray.dir_y * cub->spr.sprite_x - cub->ray.dir_x
	* cub->spr.sprite_y);
	cub->spr.tr_y = cub->spr.invdet
	* (-cub->ray.plane_y * cub->spr.sprite_x + cub->ray.plane_x
	* cub->spr.sprite_y);
	cub->spr.s_screen_x = (int)((cub->width / 2)
	* (1 + cub->spr.tr_x / cub->spr.tr_y));
	cub->spr.v_move = (int)(VMOVE / cub->spr.tr_y);
}

int						draw_init(t_cub *cub)
{
	return (cub->spr.tr_y > 0 && cub->spr.stripe > 0
	&& cub->spr.stripe < cub->width
	&& cub->spr.tr_y < cub->perp_for_sprites[cub->spr.stripe]);
}

void					color_sprite(t_cub *cub)
{
	cub->spr.d = (cub->spr.y - cub->spr.v_move) * 256
	- cub->height * 128 + cub->spr.sp_height * 128;
	cub->spr.tex_y = ((cub->spr.d * cub->tex[4].height) /
	cub->spr.sp_height) / 256;
	cub->spr.color = ((int *)cub->tex[4].image_data)[cub->tex[4].width
	* cub->spr.tex_y + cub->spr.tex_x];
}

void					draw_sprites(t_cub *cub)
{
	sprite_math(cub);
	sprites_draw_start_end(cub);
	cub->spr.stripe = cub->spr.start_x;
	while (cub->spr.stripe < cub->spr.end_x)
	{
		cub->spr.tex_x = (int)((256 * (cub->spr.stripe
		- (-cub->spr.sp_width / 2 + cub->spr.s_screen_x))
		* cub->tex[4].width / cub->spr.sp_width) / 256);
		cub->spr.y = cub->spr.start_y;
		if (draw_init(cub))
			while (cub->spr.y < cub->spr.end_y)
			{
				color_sprite(cub);
				if ((cub->spr.color & 0x00FFFFFF) != 0)
					set_pixel(cub, cub->spr.stripe,
					cub->spr.y, cub->spr.color);
				cub->spr.y++;
			}
		cub->spr.stripe++;
	}
}

void					ray_sprites(t_cub *cub)
{
	get_sprites_pos(cub);
	sort_sprite(cub);
	cub->spr.loop_sprites = 0;
	while (cub->spr.loop_sprites < cub->val_sprites)
	{
		draw_sprites(cub);
		cub->spr.loop_sprites++;
	}
}
