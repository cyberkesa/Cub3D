/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:35:48 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/04 16:35:49 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					make_map_array(t_cub *cub, char *line)
{
	static int			i = 0;

	cub->map[i] = line;
	i++;
}

void					parce_map(t_cub *cub, char *line)
{
	static int			number_line = 0;
	static int			doubles_nswe = 0;
	int					nswe;

	cub->flags.parce_map_start = 1;
	nswe = 0;
	if (number_line == 0)
		check_first_line(line, cub);
	nswe = check_nswe(cub, line);
	make_map_array(cub, line);
	if (nswe != -1)
	{
		if (doubles_nswe != 0)
			return_error("Error! N, S, W, E doubles.\n", cub);
		cub->plr.x = nswe;
		cub->plr.y = number_line;
		cub->plr.nswe = line[nswe];
		doubles_nswe++;
	}
	number_line++;
}

void					check_valid_line(char *line, t_cub *cub)
{
	if ((line[0] == 'N' && line[1] == 'O')
	|| (line[0] == 'S' && line[1] == 'O')
	|| (line[0] == 'W' && line[1] == 'E')
	|| (line[0] == 'E' && line[1] == 'A')
	|| (line[0] == 'S' && line[1] != 'O')
	|| (line[0] == 'R') || (line[0] == 'F') || (line[0] == 'C')
	|| (line[0] == '1' || line[0] == ' ') || (line[0] == 0))
		return ;
	else
		return_error("Error! Not valide symbol in map.cub.\n", cub);
}

void					check_line(char *line, t_cub *cub)
{
	if (line[0] == 'N' && line[1] == 'O')
		parce_no(line, cub);
	else if (line[0] == 'S' && line[1] == 'O')
		parce_so(line, cub);
	else if (line[0] == 'W' && line[1] == 'E')
		parce_we(line, cub);
	else if (line[0] == 'E' && line[1] == 'A')
		parce_ea(line, cub);
	else if (line[0] == 'S' && line[1] != 'O')
		parce_s(line, cub);
	else if (line[0] == 'R')
		parce_r(line, cub);
	else if (line[0] == 'F')
		parce_floor_color(line, cub);
	else if (line[0] == 'C')
		parce_ceiling_color(line, cub);
}

void					general_parce(t_cub *cub, int fd)
{
	char				*line;

	while (get_next_line(fd, &line) == 1)
	{
		check_valid_line(line, cub);
		if (line[0] == '0')
			return_error("Error! Not valide symbol in map.cub.\n", cub);
		check_line(line, cub);
		if (line[0] == '\0' && cub->flags.parce_map_start == 1)
			return_error("Error! Not valide symbol in map.cub.\n", cub);
		if ((line[0] == '1' && !(tex_keys(cub) == 1)))
			return_error("Error! Not valide symbol in map.cub.\n", cub);
		if ((line[0] == '1' || line[0] == ' ') && tex_keys(cub) == 1)
			parce_map(cub, line);
		else
			free(line);
	}
	free(line);
	if (cub->flags.parce_map_start == 0)
		return_error("Error! Where map?\n", cub);
}
