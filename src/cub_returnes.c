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
	if (code == FREE_MAP)
		cub_free_map(cub);
	if (code == FREE_MAP_TEX)
		re_map_tex(cub);
	if (code == FREE_MAP_TEX_COLOR)
		re_map_tex_color(cub);
	if (code == FREE_MAP_TEX_COLOR_FD)
		re_map_tex_fd_color(cub);
	if (code == FREE_MAP_TEX_COLOR_SPRITES)
		re_map_tex_sprites_color(cub);
	if (code == FREE_ALL)
		free_all_and_exit(cub);
	exit (0);
}

int					free_all_and_exit(t_cub *cub)
{
	cub_free_mlx(cub);
	cub_free_map(cub);
	cub_free_sprites(cub);
	cub_free_textures(cub);
	exit (0);
	return (0);
}

void					re_map_tex_sprites_color(t_cub *cub)
{
	cub_free_map(cub);
	cub_free_textures(cub);
	cub_free_sprites(cub);
}

void					re_map_tex(t_cub *cub)
{
	cub_free_map(cub);
	cub_free_textures(cub);
}

void					re_map_tex_fd_color(t_cub *cub)
{
	close(cub->fd);
	cub_free_map(cub);
	cub_free_textures(cub);
}

void					re_map_tex_color(t_cub *cub)
{
	cub_free_map(cub);
	cub_free_textures(cub);
}

