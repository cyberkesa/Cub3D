/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   periphery.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:19:26 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:20:13 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int						turn_on(int key, void *arg)
{
	t_cub				*cub;

	cub = arg;
	cub->move_left = (key == MOVE_LEFT) ? 1 : cub->move_left;
	cub->move_right = (key == MOVE_RIGHT) ? 1 : cub->move_right;
	cub->move_forth = (key == MOVE_FORTH) ? 1 : cub->move_forth;
	cub->move_back = (key == MOVE_BACK) ? 1 : cub->move_back;
	cub->move_speed = (key == MOVE_SPEED) ? 1 : cub->move_speed;
	cub->turn_left = (key == TURN_LEFT) ? 1 : cub->turn_left;
	cub->turn_right = (key == TURN_RIGHT) ? 1 : cub->turn_right;
	return (0);
}

void					press(t_cub *cub)
{
	(cub->move_forth) ? move_forth(cub) : 0;
	(cub->move_back) ? move_back(cub) : 0;
	(cub->turn_left) ? turn(cub, NEG_COS_ROT, NEG_SIN_ROT) : 0;
	(cub->turn_right) ? turn(cub, COS_ROT, SIN_ROT) : 0;
	(cub->move_right) ? move_right(cub) : 0;
	(cub->move_left) ? move_left(cub) : 0;
	(cub->move_speed) ? move_speed(cub) : 0;
}

int						turn_off(int key, void *arg)
{
	t_cub				*cub;

	cub = arg;
	if (key == ESC)
	{
		ft_freeleak(cub);
		exit(0);
	}
	else
	{
		cub->pressed_key = key;
		press(cub);
	}
	key = cub->pressed_key;
	cub->move_left = (key == MOVE_LEFT) ? 0 : cub->move_left;
	cub->move_right = (key == MOVE_RIGHT) ? 0 : cub->move_right;
	cub->move_forth = (key == MOVE_FORTH) ? 0 : cub->move_forth;
	cub->move_back = (key == MOVE_BACK) ? 0 : cub->move_back;
	cub->move_speed = (key == MOVE_SPEED) ? 0 : cub->move_speed;
	cub->turn_left = (key == TURN_LEFT) ? 0 : cub->turn_left;
	cub->turn_right = (key == TURN_RIGHT) ? 0 : cub->turn_right;
	return (0);
}

void					turn(t_cub *cub, double cos, double sin)
{
	double				dir_x;
	double				plane_x;

	dir_x = cub->ray.dir_x;
	plane_x = cub->ray.plane_x;
	cub->ray.dir_x = cub->ray.dir_x * cos - cub->ray.dir_y * sin;
	cub->ray.dir_y = dir_x * sin + cub->ray.dir_y * cos;
	cub->ray.plane_x = cub->ray.plane_x * cos - cub->ray.plane_y * sin;
	cub->ray.plane_y = plane_x * sin + cub->ray.plane_y * cos;
}
