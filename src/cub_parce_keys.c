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
			cub_error("Error! Where whitespace after 'R'?\n", cub, FD_TEX);
		r = ft_split(ft_strchr(line, 'R') + 1, ' ');
		if ((r[2]) || !r[0] || !r[1])
			cub_error("Error! Not valide 'R'\n", cub, FD_TEX);
		cub->width = ft_atoi(r[0]);
		cub->height = ft_atoi(r[1]);
		cub->width = (ft_strlen(r[0]) > 4) ? 1440 : cub->width;
		cub->height = (ft_strlen(r[1]) > 4) ? 2560 : cub->height;
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

void					check_valid_color(char *rgb, t_cub *cub)
{
	int					i;

	i = 0;
	if (rgb[i] == '-')
		cub_error("Error! Not valide color.\n", cub, FD_TEX);
	while (rgb[i])
	{
		if (rgb[i] != ' ' && rgb[i] != '0' && rgb[i] != '1'
		&& rgb[i] != '2' && rgb[i] != '3' && rgb[i] != '4'
		&& rgb[i] != '5' && rgb[i] != '6' && rgb[i] != '7'
		&& rgb[i] != '8' && rgb[i] != '9')
			cub_error("Error! Not valide color.\n", cub, FD_TEX);
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
		cub_error("Error! Not valide color.\n", cub, FD_TEX);
}

void					colors_check(t_cub *cub, char *red,
									char *green, char *blue)
{
	check_valid_color(red, cub);
	check_valid_color(green, cub);
	check_valid_color(blue, cub);
	cub->r = ft_atoi(red);
	cub->g = ft_atoi(green);
	cub->b = ft_atoi(blue);
	check_one_more_null(cub->r, red, cub);
	check_one_more_null(cub->g, green, cub);
	check_one_more_null(cub->b, blue, cub);
	free(red);
	free(green);
	free(blue);
}

int						parse_color(char *color, t_cub *cub)
{
	char				**rgb;
	char				*red;
	char				*green;
	char				*blue;

	rgb = NULL;
	rgb = ft_split(color, ',');
	if (rgb[3] || !rgb[0] || !rgb[2] || !rgb[1])
	{
		free_array(rgb);
		free(color);
		cub_error("Error! RGB: XXX, XXX, XXX\n", cub, FD_TEX);
	}
	red = ft_strtrim(rgb[0], " ");
	green = ft_strtrim(rgb[1], " ");
	blue = ft_strtrim(rgb[2], " ");
	colors_check(cub, red, green, blue);
	free_array(rgb);
	free(color);
	if ((cub->r < 0 || cub->r > 255) || (cub->g < 0 || cub->g > 255)
	|| (cub->b < 0 || cub->b > 255))
		cub_error("Error! RGB range: 0 - 255\n", cub, FD_TEX);
	return (((cub->r & 0x0ff) << 16)
	| ((cub->g & 0x0ff) << 8) | (cub->b & 0x0ff));
}
