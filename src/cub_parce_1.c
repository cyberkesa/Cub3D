/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parce_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:44:18 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/08 21:44:22 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					check_number_nswe(t_cub *cub)
{
	int					x;
	int					y;

	x = 0;
	y = 0;
	while (x < cub->map_number_line && cub->map[x])
	{
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == 'N' || cub->map[x][y] == 'S'
			|| cub->map[x][y] == 'W' || cub->map[x][y] == 'E')
				cub->nswe_count++;
			y++;
		}
		y = 0;
		x++;
	}
	if (cub->nswe_count > 1 || cub->nswe_count == 0)
		cub_error("Error! Not valide number of player.\n", cub, FD_TEX);
}

void					set_pos_nswe(t_cub *cub, int x, int y, char c)
{
	cub->plr.y = x;
	cub->plr.x = y;
	cub->plr.nswe = c;
}

void					find_player_in_map(t_cub *cub)
{
	int					x;
	int					y;

	x = 0;
	y = 0;
	while (x < cub->map_number_line && cub->map[x] && cub->plr.nswe == 0)
	{
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == 'N')
				set_pos_nswe(cub, x, y, 'N');
			if (cub->map[x][y] == 'S')
				set_pos_nswe(cub, x, y, 'S');
			if (cub->map[x][y] == 'W')
				set_pos_nswe(cub, x, y, 'W');
			if (cub->map[x][y] == 'E')
				set_pos_nswe(cub, x, y, 'E');
			y++;
		}
		y = 0;
		x++;
	}
}

void					parce_map(t_cub *cub, char *line)
{
	static int			number_line = 0;

	cub->flags.parce_map_start = 1;
	if (number_line == 0)
		check_first_line(line, cub);
	make_map_array(cub, line);
	number_line++;
}
