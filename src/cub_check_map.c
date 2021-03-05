/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:18:04 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:18:05 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					check_first_line(char *line, t_cub *cub)
{
	int					i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'W' || line[i] == 'E' || line[i] == '2')
			error_map_tex_fd("Error first line!\n", cub);
		i++;
	}
}

void					check_last_line(t_cub *cub)
{
	int					x;
	int					i;

	x = cub->map_number_line - 1;
	i = 0;
	while (cub->map[x][i])
	{
		if (cub->map[x][i] == '0'
		|| cub->map[x][i] == 'N'
		|| cub->map[x][i] == 'S'
		|| cub->map[x][i] == 'W'
		|| cub->map[x][i] == 'E')
			error_map_tex_fd("Error last line!\n", cub);
		i++;
	}
}

int						check_nswe(t_cub *cub, char *line)
{
	int					i;
	int					a;

	i = 0;
	a = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'W' || line[i] == 'E')
			a++;
		i++;
	}
	if (a > 1)
		error_map_tex_fd("Error! Not valide number of player.\n", cub);
	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'W' || line[i] == 'E')
			return (i);
		i++;
	}
	return (-1);
}

void					check_wall(t_cub *cub, int x, int y)
{
	if ((cub->map[x][y + 1] == ' ' || cub->map[x][y + 1] == '\0')
	|| (cub->map[x][y - 1] == ' ' || cub->map[x][y - 1] == '\0')
	|| (cub->map[x - 1][y] == ' ' || cub->map[x - 1][y] == '\0')
	|| (cub->map[x + 1][y] == ' ' || cub->map[x + 1][y] == '\0')
	|| (cub->map[x + 1][y + 1] == ' ' || cub->map[x + 1][y + 1] == '\0')
	|| (cub->map[x - 1][y - 1] == ' ' || cub->map[x - 1][y - 1] == '\0')
	|| (cub->map[x - 1][y + 1] == ' ' || cub->map[x - 1][y + 1] == '\0')
	|| (cub->map[x + 1][y - 1] == ' ' || cub->map[x + 1][y - 1] == '\0'))
		error_map_tex_color("Error! Map bad closed.\n", cub);
	return ;
}

void					check_map_closed(t_cub *cub)
{
	int					x;
	int					y;

	x = 0;
	y = 0;
	while (cub->map[x] && x < cub->map_number_line)
	{
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == '0')
				check_wall(cub, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}
