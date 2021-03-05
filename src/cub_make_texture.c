/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_make_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:04:38 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:04:39 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

void					make_texture_pixel_array(t_cub *cub, int num)
{
	int					fd;

	fd = open(cub->tex[num].path, 1);
	if (fd == -1)
	{
		close(fd);
		cub_error("Error open file texture.\n", cub, FREE_MAP_TEX_COLOR_SPRITES);
	}
	if (cub->tex[num].path != NULL)
	{
		if (num == 4)
			cub->flags.texture_okey = 1;
		cub->tex[num].image_ptr = mlx_xpm_file_to_image(cub->mlx,
		cub->tex[num].path, &cub->tex[num].width, &cub->tex[num].height);
		if (cub->tex[num].image_ptr == NULL)
			cub_error("Global error with make texture.\n", cub, FREE_MAP_TEX_COLOR_SPRITES);
		cub->tex[num].image_data = mlx_get_data_addr(cub->tex[num].image_ptr,
		&cub->tex[num].bpp, &cub->tex[num].size_line, &cub->tex[num].endian);
	}
	else
		cub_error("Error with make texture.\n", cub, FREE_MAP_TEX_COLOR_SPRITES);
	close(fd);
}

void					mlx_texture(t_cub *cub)
{
	int					num;

	num = -1;
	while (num++ != 4)
		make_texture_pixel_array(cub, num);
}
