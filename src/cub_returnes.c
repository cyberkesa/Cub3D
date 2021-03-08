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
	else if (code == FD_TEX)
		close(cub->fd);
	free_all_and_exit(cub);
}

int						free_all_and_exit(t_cub *cub)
{
	if (cub->flags.map_allocate)
		cub_free_map(cub);
	if (cub->flags.perp_allocate)
		cub_free_perp(cub);
	if (cub->flags.sprite_allocate)
		cub_free_sprites(cub);
	if (cub->flags.textures_allocate)
		cub_free_textures(cub);
	exit(0);
	return (0);
}
