/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:19:33 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:19:33 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void						move_forth(t_cub *cub)
{
	if (cub->map[(int)cub->plr.y][(int)(cub->plr.x
	+ cub->ray.dir_x * COLLISION)] != '1'
	&& cub->map[(int)(cub->plr.y + cub->ray.dir_y
	* COLLISION)][(int)(cub->plr.x)] != '1'
	&& cub->map[(int)cub->plr.y][(int)(cub->plr.x
	+ cub->ray.dir_x * COLLISION)] != '2'
	&& cub->map[(int)(cub->plr.y + cub->ray.dir_y
	* COLLISION)][(int)(cub->plr.x)] != '2')
	{
		cub->plr.x += cub->ray.dir_x * STEP;
		cub->plr.y += cub->ray.dir_y * STEP;
	}
}

void						move_back(t_cub *cub)
{
	if (cub->map[(int)cub->plr.y][(int)(cub->plr.x
	+ cub->ray.dir_x * -COLLISION)] != '1'
	&& cub->map[(int)(cub->plr.y + cub->ray.dir_y
	* -COLLISION)][(int)(cub->plr.x)] != '1'
	&& cub->map[(int)cub->plr.y][(int)(cub->plr.x
	+ cub->ray.dir_x * -COLLISION)] != '2'
	&& cub->map[(int)(cub->plr.y + cub->ray.dir_y
	* -COLLISION)][(int)(cub->plr.x)] != '2')
	{
		cub->plr.x -= cub->ray.dir_x * STEP;
		cub->plr.y -= cub->ray.dir_y * STEP;
	}
}

void						move_right(t_cub *cub)
{
	if (cub->map[(int)cub->plr.y][(int)(cub->plr.x
	+ cub->ray.plane_x * -COLLISION)] != '1'
	&& cub->map[(int)(cub->plr.y + cub->ray.plane_y
	* -COLLISION)][(int)(cub->plr.x)] != '1'
	&& cub->map[(int)cub->plr.y][(int)(cub->plr.x
	+ cub->ray.plane_x * -COLLISION)] != '2'
	&& cub->map[(int)(cub->plr.y + cub->ray.plane_y
	* -COLLISION)][(int)(cub->plr.x)] != '2')
	{
		cub->plr.x -= cub->ray.plane_x * STEP;
		cub->plr.y -= cub->ray.plane_y * STEP;
	}
}

void						move_left(t_cub *cub)
{
	if (cub->map[(int)cub->plr.y][(int)(cub->plr.x +
	cub->ray.plane_x * COLLISION)] != '1'
	&& cub->map[(int)(cub->plr.y + cub->ray.plane_y *
	COLLISION)][(int)(cub->plr.x)] != '1'
	&& cub->map[(int)cub->plr.y][(int)(cub->plr.x +
	cub->ray.plane_x * COLLISION)] != '2'
	&& cub->map[(int)(cub->plr.y + cub->ray.plane_y *
	COLLISION)][(int)(cub->plr.x)] != '2')
	{
		cub->plr.x += cub->ray.plane_x * STEP;
		cub->plr.y += cub->ray.plane_y * STEP;
	}
}

void						move_speed(t_cub *cub)
{
	if (cub->map[(int)(cub->plr.y + cub->ray.dir_y
	* COLLISION)][(int)(cub->plr.x)] != '1'
	&& cub->map[(int)cub->plr.y][(int)(cub->plr.x
	+ cub->ray.dir_x * COLLISION)] != '1'
	&& cub->map[(int)(cub->plr.y + cub->ray.dir_y
	* COLLISION)][(int)(cub->plr.x)] != '2'
	&& cub->map[(int)cub->plr.y][(int)(cub->plr.x
	+ cub->ray.dir_x * COLLISION)] != '2')
	{
		cub->plr.x += cub->ray.dir_x * STEP;
		cub->plr.y += cub->ray.dir_y * STEP;
	}
}
