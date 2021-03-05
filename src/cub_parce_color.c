/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:19:00 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:19:01 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					parce_ceiling_color(char *line, t_cub *cub)
{
	if (cub->flags.ceiling_color_ok == 0)
	{
		check_two_commas(line, cub);
		cub->ceiling_color = parse_color(ft_strtrim(line, "C "), cub);
		cub->flags.ceiling_color_ok = 1;
	}
	else
		error_map_tex_fd_color("Error! Color's doubles.\n", cub);
}

void					parce_floor_color(char *line, t_cub *cub)
{
	if (cub->flags.floor_color_ok == 0)
	{
		check_two_commas(line, cub);
		cub->floor_color = parse_color(ft_strtrim(line, "F "), cub);
		cub->flags.floor_color_ok = 1;
	}
	else
		error_map_tex_fd_color("Error! Color's doubles.\n", cub);
}

void					check_two_commas(char *line, t_cub *cub)
{
	int					i;
	int					a;

	i = 0;
	a = 0;
	while (line[i])
	{
		if (line[i] == ',')
			a++;
		i++;
	}
	if (a != 2)
		error_map_tex_fd_color("Error! Commas troubles.\n", cub);
	return ;
}
