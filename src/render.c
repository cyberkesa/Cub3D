/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:19:54 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:19:55 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void						set_pixel(t_cub *cub, int x, int y, int color)
{
	int						pixel_position;

	pixel_position = y * cub->image_line + x;
	if (pixel_position >= cub->image_size || pixel_position < 0)
		return ;
	cub->image_data[pixel_position] = color;
}

void						draw_background(t_cub *cub)
{
	int						image_line;
	int						image_size;
	int						half_image_size;
	int						ceiling_pixel;
	int						i;

	image_line = cub->size_line / (cub->bpp / 8);
	image_size = cub->height * image_line;
	half_image_size = image_size / 2;
	ceiling_pixel = half_image_size - half_image_size % image_line;
	i = -1;
	while (++i < image_size)
		cub->image_data[i] = (i < ceiling_pixel) ? cub->ceiling_color
		: cub->floor_color;
}

int							draw(t_cub *cub)
{
	draw_background(cub);
	ray_cast(cub);
	ray_sprites(cub);
	mlx_put_image_to_window(cub->mlx, cub->cub_win_ptr, cub->image, 0, 0);
	return (0);
}
