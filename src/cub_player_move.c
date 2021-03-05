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

void						move_forth_and_back(t_cub *cub, int init)
{
	if (init == 1)
		if (cub->map[(int)cub->plr.y][(int)(cub->plr.x
		+ cub->ray.dir_x * COLLISION)] != '1'
		&& cub->map[(int)(cub->plr.y + cub->ray.dir_y
		* COLLISION)][(int)(cub->plr.x)] != '1')
		{
			cub->plr.x += cub->ray.dir_x * STEP;
			cub->plr.y += cub->ray.dir_y * STEP;
		}
	if (init == 2)
		if (cub->map[(int)cub->plr.y][(int)(cub->plr.x
		+ cub->ray.dir_x * -COLLISION)] != '1'
		&& cub->map[(int)(cub->plr.y + cub->ray.dir_y
		* -COLLISION)][(int)(cub->plr.x)] != '1')
		{
			cub->plr.x -= cub->ray.dir_x * STEP;
			cub->plr.y -= cub->ray.dir_y * STEP;
		}
}

void						move_right_and_left(t_cub *cub, int init)
{
	if (init == 1)
		if (cub->map[(int)cub->plr.y][(int)(cub->plr.x
		+ cub->ray.plane_x * -COLLISION)] != '1'
		&& cub->map[(int)(cub->plr.y + cub->ray.plane_y
		* -COLLISION)][(int)(cub->plr.x)] != '1')
		{
			cub->plr.x -= cub->ray.plane_x * STEP;
			cub->plr.y -= cub->ray.plane_y * STEP;
		}
	if (init == 2)
		if (cub->map[(int)cub->plr.y][(int)(cub->plr.x +
		cub->ray.plane_x * COLLISION)] != '1'
		&& cub->map[(int)(cub->plr.y + cub->ray.plane_y *
		COLLISION)][(int)(cub->plr.x)] != '1')
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

void						move_turn(t_cub *cub, double cos, double sin)
{
	double					dir_x;
	double					plane_x;

	dir_x = cub->ray.dir_x;
	plane_x = cub->ray.plane_x;
	cub->ray.dir_x = cub->ray.dir_x * cos - cub->ray.dir_y * sin;
	cub->ray.dir_y = dir_x * sin + cub->ray.dir_y * cos;
	cub->ray.plane_x = cub->ray.plane_x * cos - cub->ray.plane_y * sin;
	cub->ray.plane_y = plane_x * sin + cub->ray.plane_y * cos;
}
