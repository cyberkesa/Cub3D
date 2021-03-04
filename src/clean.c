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

void					ft_freeleak(t_cub *cub)
{
	int					i;

	i = 0;
	while (i < 5)
	{
		free(cub->tex[i].path);
		free(cub->tex[i].image_data);
		free(cub->tex[i].image_ptr);
		i++;
	}
	free(cub->sprites);
	free(cub->sp_dist);
	free(cub->perp_for_sprites);
	free(cub->sp_order);
	free(cub->image_data);
	free(cub->mlx);
	free(cub->cub_win_ptr);
	i = 0;
	if (cub->map == NULL)
		return ;
	free(cub->map);
}

void					free_array(char **r)
{
	int					i;

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
	if (cub->flags.screen == 0)
		if (cub->image)
			mlx_destroy_image(cub->mlx, cub->image);
	if (cub->flags.screen == 0)
		if (cub->cub_win_ptr)
			mlx_destroy_window(cub->mlx, cub->cub_win_ptr);
	exit(0);
}
