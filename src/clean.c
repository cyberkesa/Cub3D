/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:34:53 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/04 16:34:55 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					ft_free_more(t_cub *cub)
{
	if (cub->image_data)
		free(cub->image_data);
	if (cub->mlx)
		free(cub->mlx);
	if (cub->cub_win_ptr)
		free(cub->cub_win_ptr);
	if (cub->flags.parce_map_start == 1 && cub->plr.nswe == 1)
		free_array(cub->map);
}

void					ft_freeleak(t_cub *cub)
{
	int					i;

	i = 0;
	if (cub->flags.texture_okey == 1)
		while (i < 5)
		{
			free(cub->tex[i].path);
			free(cub->tex[i].image_data);
			free(cub->tex[i].image_ptr);
			i++;
		}
	if (cub->val_sprites > 0)
	{
		free(cub->sprites);
		free(cub->sp_dist);
		free(cub->perp_for_sprites);
		free(cub->sp_order);
	}
	ft_free_more(cub);
}

void					free_array(char **r)
{
	size_t				i;

	i = 0;
	while (r[i])
		free(r[i++]);
	free(r);
}

void					return_error(char *error, t_cub *cub)
{
	int					len;

	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}

int						ft_exit(t_cub *cub)
{
	ft_freeleak(cub);
	if (cub->flags.screen == 0 && cub->flags.texture_okey == 1)
		if (cub->image)
			mlx_destroy_image(cub->mlx, cub->image);
	if (cub->flags.screen == 0 && cub->flags.texture_okey == 1)
		if (cub->cub_win_ptr)
			mlx_destroy_window(cub->mlx, cub->cub_win_ptr);
	exit(0);
}
