/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:36:02 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/04 16:36:03 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			ray_perp(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->ray.perp_wall = (cub->ray.x_int - cub->plr.x +
		(1 - cub->ray.step_x) / 2) / cub->ray.ray_dir_x;
	else
		cub->ray.perp_wall = (cub->ray.y_int - cub->plr.y +
		(1 - cub->ray.step_y) / 2) / cub->ray.ray_dir_y;
}

void			ray_start_end(t_cub *cub)
{
	cub->line_height = (int)(cub->height / cub->ray.perp_wall - 2);
	cub->draw_start = -cub->line_height / 2 + cub->height / 2;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = cub->line_height / 2 + cub->height / 2;
	if (cub->draw_end >= cub->height)
		cub->draw_end = cub->height - 1;
	cub->tex_x = (int)(cub->wall_x * (double)cub->tex[cub->texture_id].width);
	if (cub->ray.side == 0 && cub->ray.ray_dir_x > 0)
		cub->tex_x = cub->tex[cub->texture_id].width - cub->tex_x - 1;
	if (cub->ray.side == 1 && cub->ray.ray_dir_y < 0)
		cub->tex_x = cub->tex[cub->texture_id].width - cub->tex_x - 1;
	cub->step = 1.0 * cub->tex[cub->texture_id].height / cub->line_height;
	cub->tex_pos = (cub->draw_start - cub->height /
	2 + cub->line_height / 2) * cub->step;
}

void			ray_cast(t_cub *cub)
{
	press(cub);
	cub->loop = 0;
	while (cub->loop <= cub->width)
	{
		ray_math(cub);
		ray_step(cub);
		ray_hit(cub);
		ray_perp(cub);
		ray_wall_x(cub);
		set_side_texture(cub);
		ray_start_end(cub);
		while (cub->draw_start < cub->draw_end)
		{
			cub->ray.color = ((int *)cub->tex[cub->texture_id].image_data)
			[cub->tex[cub->texture_id].height * cub->tex_y + cub->tex_x];
			cub->tex_y = (int)cub->tex_pos &
			(cub->tex[cub->texture_id].height - 1);
			cub->tex_pos += cub->step;
			set_pixel(cub, cub->loop, cub->draw_start++, cub->ray.color);
		}
		cub->perp_for_sprites[cub->loop] = cub->ray.perp_wall;
		cub->loop++;
	}
}
