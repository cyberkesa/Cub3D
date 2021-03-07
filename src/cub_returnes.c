/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_returnes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:07:24 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:07:25 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					cub_error(char *error, t_cub *cub, int code)
{
	int					len;

	len = (int)ft_strlen(error);
	write(2, error, len);
	if (code == NO_FREE)
		exit(0);
	if (cub->flags.map_allocate)
		cub_free_map(cub);
	if (cub->flags.perp_allocate)
		cub_free_perp(cub);
	if (cub->flags.sprite_allocate)
		cub_free_sprites(cub);
	if (code == FREE_ALL)
		free_all_and_exit(cub);
	if (code == TEX)
		cub_free_textures(cub);
	if (code == FD_TEX)
	{
		close(cub->fd);
		cub_free_textures(cub);
	}
	exit (0);
}

int					free_all_and_exit(t_cub *cub)
{
	cub_free_mlx(cub);
	cub_free_textures(cub);
	cub->fd = 0;
	exit (0);
	return (0);
}
