/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check_map_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:04:17 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:04:18 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					check_player_pos(t_cub *cub)
{
	int					y;
	int					x;

	y = cub->plr.x;
	x = cub->plr.y;
	if (cub->plr.nswe > 0)
	{
		if ((cub->map[x][y + 1] == ' ' || cub->map[x][y + 1] == '\0'
	|| (cub->map[x][y - 1] == ' ' || cub->map[x][y - 1] == '\0')
	|| (cub->map[x - 1][y] == ' ' || cub->map[x - 1][y] == '\0')
	|| (cub->map[x + 1][y] == ' ' || cub->map[x + 1][y] == '\0')
	|| (cub->map[x + 1][y + 1] == ' ' || cub->map[x + 1][y + 1] == '\0')
	|| (cub->map[x - 1][y - 1] == ' ' || cub->map[x - 1][y - 1] == '\0')
	|| (cub->map[x - 1][y + 1] == ' ' || cub->map[x - 1][y + 1] == '\0')
	|| cub->map[x + 1][y - 1] == ' ' || cub->map[x + 1][y - 1] == '\0'))
			cub_error("Erro! Player's error!\n", cub, TEX);
	}
	return ;
}

void					check_map_validate(t_cub *cub)
{
	int					x;
	int					i;

	x = 0;
	while (x < cub->map_number_line && cub->map[x])
	{
		i = 0;
		while (x < cub->map_number_line && cub->map[x][i])
		{
			if (!(cub->map[x][i] == '0'
			|| cub->map[x][i] == '1'
			|| cub->map[x][i] == '2'
			|| cub->map[x][i] == 'N'
			|| cub->map[x][i] == 'S'
			|| cub->map[x][i] == 'W'
			|| cub->map[x][i] == 'E'
			|| cub->map[x][i] == ' '))
				cub_error("Error! Not valide symbol in map.\n", cub, TEX);
			i++;
		}
		x++;
	}
}
