/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:05:11 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:05:12 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void						set_side_texture(t_cub *cub)
{
	if (cub->ray.side == 1)
	{
		if (cub->ray.step_y > 0)
			cub->t_id = 0;
		if (cub->ray.step_y < 0)
			cub->t_id = 1;
	}
	if (cub->ray.side == 0)
	{
		if (cub->ray.step_x > 0)
			cub->t_id = 2;
		if (cub->ray.step_x < 0)
			cub->t_id = 3;
	}
}

void						ray_step(t_cub *cub)
{
	if (cub->ray.ray_dir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.side_dist_x = (cub->plr.x - cub->ray.x_int)
		* cub->ray.delta_dist_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->ray.side_dist_x = (cub->ray.x_int + 1.0 - cub->plr.x)
		* cub->ray.delta_dist_x;
	}
	if (cub->ray.ray_dir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.side_dist_y = (cub->plr.y - cub->ray.y_int)
		* cub->ray.delta_dist_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->ray.side_dist_y = (cub->ray.y_int + 1.0 - cub->plr.y)
		* cub->ray.delta_dist_y;
	}
}

void						ray_math(t_cub *cub)
{
	cub->cam_x = 2 * (cub->width - cub->loop) / (double)cub->width - 1;
	cub->ray.ray_dir_x = cub->ray.dir_x + cub->ray.plane_x * cub->cam_x;
	cub->ray.ray_dir_y = cub->ray.dir_y + cub->ray.plane_y * cub->cam_x;
	cub->ray.x_int = (int)cub->plr.x;
	cub->ray.y_int = (int)cub->plr.y;
	cub->ray.delta_dist_x = fabs(1 / cub->ray.ray_dir_x);
	cub->ray.delta_dist_y = fabs(1 / cub->ray.ray_dir_y);
	ray_step(cub);
	ray_hit(cub);
	ray_perp(cub);
	ray_wall_x(cub);
	set_side_texture(cub);
	ray_start_end(cub);
}

void						ray_hit(t_cub *cub)
{
	cub->hit = 0;
	while (cub->hit == 0)
	{
		if (cub->ray.side_dist_x < cub->ray.side_dist_y)
		{
			cub->ray.side_dist_x += cub->ray.delta_dist_x;
			cub->ray.x_int += cub->ray.step_x;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.side_dist_y += cub->ray.delta_dist_y;
			cub->ray.y_int += cub->ray.step_y;
			cub->ray.side = 1;
		}
		if (cub->map[cub->ray.y_int][cub->ray.x_int] == '1')
			cub->hit = 1;
	}
}

void						ray_wall_x(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->wall_x = cub->plr.y + cub->ray.perp_wall * cub->ray.ray_dir_y;
	else
		cub->wall_x = cub->plr.x + cub->ray.perp_wall * cub->ray.ray_dir_x;
	cub->wall_x = 1 - (cub->wall_x - floor(cub->wall_x));
}
