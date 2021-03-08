/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parce_resolution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:49:28 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/08 16:49:32 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					check_line_resolution(char *line, t_cub *cub)
{
	int					i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' '
		&& line[i] != '0' && line[i] != '2'
		&& line[i] != '3' && line[i] != '4'
		&& line[i] != '5' && line[i] != '6'
		&& line[i] != '7' && line[i] != '8'
		&& line[i] != '9' && line[i] != 'R')
			cub_error("Error! Not valide 'R' - resolution.\n", cub, FD_TEX);
		i++;
	}
}

void					parce_r(char *line, t_cub *cub)
{
	char				**r;

	if (cub->flags.resolution == 0)
	{
		check_line_resolution(line, cub);
		if (line[1] != ' ')
			cub_error("Error! Where whitespace after 'R'?\n", cub, FD_TEX);
		r = ft_split(ft_strchr(line, 'R') + 1, ' ');
		if ((r[2]) || !r[0] || !r[1])
			cub_error("Error! Not valide 'R'\n", cub, FD_TEX);
		cub->width = ft_atoi(r[0]);
		cub->height = ft_atoi(r[1]);
		cub->width = (ft_strlen(r[0]) > 4) ? 2560 : cub->width;
		cub->height = (ft_strlen(r[1]) > 4) ? 1440 : cub->height;
		free_array(r);
		if (cub->width <= 0 || cub->height <= 0)
			cub_error("Error! Not valide 'R'\n", cub, FD_TEX);
		cub->height = (cub->height < 300) ? 300 : cub->height;
		cub->width = (cub->width < 300) ? 300 : cub->width;
		cub->height = (cub->height > 1440) ? 1440 : cub->height;
		cub->width = (cub->width > 2560) ? 2560 : cub->width;
		cub->flags.resolution = 1;
	}
	else
		cub_error("Error! Doubles 'R'.\n", cub, FD_TEX);
}
