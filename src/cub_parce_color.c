/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parce_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:04:44 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:04:45 by vwinfred         ###   ########.fr       */
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
		cub_error("Error! Color's doubles.\n", cub, FREE_MAP_TEX_COLOR_FD);
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
		cub_error("Error! Color's doubles.\n", cub, FREE_MAP_TEX_COLOR_FD);
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
		cub_error("Error! Commas troubles.\n", cub, FREE_MAP_TEX_COLOR_FD);
	return ;
}
