/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_allocate_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:03:37 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:03:38 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					cub_allocate_map(t_cub *cub)
{
	cub->map = (char **)malloc(sizeof(char *) * (cub->map_number_line + 1));
}

void					cub_allocate_sprites(t_cub *cub)
{
	cub->sp_order = NULL;
	cub->sp_dist = NULL;
	cub->sprites = (t_sprites *)malloc(sizeof(t_sprites)
	* (cub->val_sprites + 1));
	cub->sp_order = malloc(sizeof(int) * cub->val_sprites);
	cub->sp_dist = malloc(sizeof(double) * cub->val_sprites);
	cub->perp_for_sprites = malloc(sizeof(double) * cub->width + 1);
}
