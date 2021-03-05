/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:04:32 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:04:33 by vwinfred         ###   ########.fr       */
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
	(cub->move_forth) ? move_forth_and_back(cub, 1) : 0;
	(cub->move_back) ? move_forth_and_back(cub, 2) : 0;
	(cub->turn_left) ? move_turn(cub, NEG_COS_ROT, NEG_SIN_ROT) : 0;
	(cub->turn_right) ? move_turn(cub, COS_ROT, SIN_ROT) : 0;
	(cub->move_right) ? move_right_and_left(cub, 1) : 0;
	(cub->move_left) ? move_right_and_left(cub, 2) : 0;
	(cub->move_speed) ? move_speed(cub) : 0;
}

int						turn_off(int key, void *arg)
{
	t_cub				*cub;

	cub = arg;
	if (key == ESC)
		free_all_and_exit(cub);
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
