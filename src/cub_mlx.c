/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:05:21 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:05:22 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					mlx_start(t_cub *cub)
{
	cub->image = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->image_data = (int *)mlx_get_data_addr(cub->image, &cub->bpp,
	&cub->size_line, &cub->endian);
	cub->image_line = cub->size_line / (cub->bpp / 8);
	cub->image_size = cub->image_line * cub->height;
	mlx_texture(cub);
}

void					mlx_hl(t_cub *cub)
{
	mlx_do_key_autorepeatoff(cub->mlx);
	mlx_hook(cub->cub_win_ptr, 3, 0, turn_off, cub);
	mlx_hook(cub->cub_win_ptr, 2, 0, turn_on, cub);
	mlx_hook(cub->cub_win_ptr, 17, 0, free_all_and_exit, cub);
	mlx_loop_hook(cub->mlx, draw, cub);
	mlx_loop(cub->mlx);
}
