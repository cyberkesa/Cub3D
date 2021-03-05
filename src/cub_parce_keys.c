/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parce_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:04:50 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:04:51 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					parce_r(char *line, t_cub *cub)
{
	char				**r;

	if (cub->flags.resolution == 0)
	{
		if (line[1] != ' ')
			cub_error("Error! Where whitespace after 'R'?\n", cub, FREE_MAP_TEX_COLOR_FD);
		r = ft_split(ft_strchr(line, 'R') + 1, ' ');
		if ((r[2]) || !r[0] || !r[1])
			cub_error("Error! Not valide 'R'\n", cub, FREE_MAP_TEX_COLOR_FD);
		if (ft_strlen(r[0]) > 10 || ft_strlen(r[1]) > 10)
			cub_error("Error! Very big 'R'\n", cub, FREE_MAP_TEX_COLOR_FD);
		cub->width = ft_atoi(r[0]);
		cub->height = ft_atoi(r[1]);
		free_array(r);
		if (cub->width <= 0 || cub->height <= 0)
			cub_error("Error! Not valide 'R'\n", cub, FREE_MAP_TEX_COLOR_FD);
		if (cub->height <= 300)
			cub->height = 300;
		if (cub->width <= 300)
			cub->width = 300;
		if (cub->height >= 1440)
			cub->height = 1440;
		if (cub->width >= 2560)
			cub->width = 2560;
		cub->flags.resolution = 1;
	}
	else
		cub_error("Error! Doubles 'R'.\n", cub, FREE_MAP_TEX_COLOR_FD);
}

void					check_valid_color(char *rgb, t_cub *cub)
{
	int					i;

	i = 0;
	if (rgb[i] == '-')
		cub_error("Error! Not valide color.\n", cub, FREE_MAP_TEX_COLOR_FD);
	while (rgb[i])
	{
		if (rgb[i] != ' ' && rgb[i] != '0' && rgb[i] != '1'
		&& rgb[i] != '2' && rgb[i] != '3' && rgb[i] != '4'
		&& rgb[i] != '5' && rgb[i] != '6' && rgb[i] != '7'
		&& rgb[i] != '8' && rgb[i] != '9')
			cub_error("Error! Not valide color.\n", cub, FREE_MAP_TEX_COLOR_FD);
		i++;
	}
}

void					check_one_more_null(int color, char *rgb, t_cub *cub)
{
	int					nbr_null;
	int					i;

	i = 0;
	nbr_null = 0;
	while (rgb[i++])
		if (rgb[i] == '0')
			nbr_null++;
	if (nbr_null == 2 && color == 100)
		return ;
	if (nbr_null == 2 && color == 200)
		return ;
	if (nbr_null >= 2)
		cub_error("Error! Not valide color.\n", cub, FREE_MAP_TEX_COLOR_FD);
}

int						parse_color(char *line, t_cub *cub)
{
	char				**rgb;
	int					r;
	int					g;
	int					b;

	rgb = ft_split(line, ',');
	rgb[0] = ft_strtrim(rgb[0], " ");
	rgb[1] = ft_strtrim(rgb[1], " ");
	rgb[2] = ft_strtrim(rgb[2], " ");
	if (rgb[3] || !rgb[0] || !rgb[2] || !rgb[1])
		cub_error("Error! RGB: XXX, XXX, XXX\n", cub, FREE_MAP_TEX_COLOR_FD);
	check_valid_color(rgb[0], cub);
	check_valid_color(rgb[1], cub);
	check_valid_color(rgb[2], cub);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	check_one_more_null(r, rgb[0], cub);
	check_one_more_null(g, rgb[1], cub);
	check_one_more_null(b, rgb[2], cub);
	free_array(rgb);
	free(line);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		cub_error("Error! RGB range: 0 - 255\n", cub, FREE_MAP_TEX_COLOR_FD);
	return (((r & 0x0ff) << 16) | ((g & 0x0ff) << 8) | (b & 0x0ff));
}
