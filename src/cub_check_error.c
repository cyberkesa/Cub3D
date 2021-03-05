/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:17:53 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:17:55 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int						tex_keys(t_cub *cub)
{
	if (cub->tex[0].path != NULL)
		if (cub->tex[1].path != NULL)
			if (cub->tex[2].path != NULL)
				if (cub->tex[3].path != NULL)
					if (cub->tex[4].path != NULL)
						if (cub->flags.ceiling_color_ok)
							if (cub->flags.floor_color_ok)
								return (1);
	return (0);
}

void					check_keys_true(t_cub *cub)
{
	if (cub->tex[0].path == NULL
	|| cub->tex[1].path == NULL
	|| cub->tex[2].path == NULL
	|| cub->tex[3].path == NULL
	|| cub->tex[4].path == NULL
	|| (cub->flags.ceiling_color_ok == 0)
	|| (cub->flags.floor_color_ok == 0)
	|| (!cub->width || !cub->height))
		error_map_tex_color("Error! Keys in map.cub.\n", cub);
}

void					nswe(t_cub *cub)
{
	cub->fov = ((double)cub->width / (double)cub->height) / 2.4;
	if (cub->plr.nswe == 0)
		error_map_tex_color("Error! Where player?\n", cub);
	if (cub->plr.nswe == 'N')
	{
		cub->ray.dir_y = -1;
		cub->ray.plane_x = -cub->fov;
	}
	else if (cub->plr.nswe == 'S')
	{
		cub->ray.dir_y = 1;
		cub->ray.plane_x = cub->fov;
	}
	else if (cub->plr.nswe == 'W')
	{
		cub->ray.dir_x = -1;
		cub->ray.plane_y = cub->fov;
	}
	else if (cub->plr.nswe == 'E')
	{
		cub->ray.dir_x = 1;
		cub->ray.plane_y = -cub->fov;
	}
}
