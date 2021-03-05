/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:22:59 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:23:00 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void					sort_sprite(t_cub *s)
{
	size_t				i;
	size_t				j;
	int					tmp;

	i = 0;
	while (i < s->val_sprites)
	{
		j = i + 1;
		while (j < s->val_sprites)
		{
			if (s->sp_dist[s->sp_order[i]] < s->sp_dist[s->sp_order[j]])
			{
				tmp = s->sp_order[j];
				s->sp_order[j] = s->sp_order[i];
				s->sp_order[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

void					get_sprites_pos(t_cub *cub)
{
	size_t				i;

	i = 0;
	while (i < cub->val_sprites)
	{
		cub->sprites[i].x = (double)cub->sprites[i].pos_in_map_x + 0.5;
		cub->sprites[i].y = (double)cub->sprites[i].pos_in_map_y + 0.5;
		cub->sp_order[i] = i;
		cub->sp_dist[i] = fabs((cub->plr.x - cub->sprites[i].x)
		* (cub->plr.x - cub->sprites[i].x)
		+ (cub->plr.y - cub->sprites[i].y)
		* (cub->plr.y - cub->sprites[i].y));
		i++;
	}
}

void					sprites_draw_start_end(t_cub *cub)
{
	cub->spr.sp_height = abs((int)(cub->height / cub->spr.tr_y) / VDIV);
	cub->spr.start_y = -cub->spr.sp_height /
	2 + cub->height / 2 + cub->spr.v_move;
	cub->spr.start_y = (cub->spr.start_y < 0) ? 0 : cub->spr.start_y;
	cub->spr.end_y = cub->spr.sp_height / 2 + cub->height / 2 + cub->spr.v_move;
	cub->spr.end_y = (cub->spr.end_y >= cub->height)
	? cub->height - 1 : cub->spr.end_y;
	cub->spr.sp_width = abs((int)(cub->height / cub->spr.tr_y) / UDIV);
	cub->spr.start_x = -cub->spr.sp_width / 2 + cub->spr.s_screen_x;
	cub->spr.start_x = (cub->spr.start_x < 0) ? 0 : cub->spr.start_x;
	cub->spr.end_x = cub->spr.sp_width / 2 + cub->spr.s_screen_x;
	cub->spr.end_x = (cub->spr.end_x >= cub->width)
	? cub->width - 1 : cub->spr.end_x;
}
