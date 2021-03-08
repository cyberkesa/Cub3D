/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:03:56 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:04:00 by vwinfred         ###   ########.fr       */
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
		cub_error("Error! Keys in map.cub.\n", cub, TEX);
}

void					nswe(t_cub *cub)
{
	cub->fov = 0.66;
	if (cub->plr.nswe == 0)
		cub_error("Error! Where player?\n", cub, TEX);
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
