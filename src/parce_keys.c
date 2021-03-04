/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:19:05 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:19:06 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					parce_r(char *line, t_cub *cub)
{
	static int			i = 0;
	char				**r;

	r = ft_split(ft_strchr(line, 'R') + 1, ' ');
	if ((r[2]) || !r[0] || !r[1])
		return_error("Error! Not valide 'R'\n", cub);
	cub->width = ft_atoi(r[0]);
	cub->height = ft_atoi(r[1]);
	free_array(r);
	if (cub->width <= 0 || cub->height <= 0)
		return_error("Error! Not valide 'R'\n", cub);
	if (cub->height <= 300)
		cub->height = 300;
	if (cub->width <= 300)
		cub->width = 300;
	if (cub->height >= 1440)
		cub->height = 1440;
	if (cub->width >= 2560)
		cub->width = 2560;
	i++;
	if (i > 1)
		return_error("Error! Doubles 'R'.\n", cub);
}

void					check_valid_color(char *rgb, t_cub *cub)
{
	int					i;

	i = 0;
	if (rgb[i] == '-')
		return_error("Error! Not valide color.\n", cub);
	while (rgb[i++])
		if (ft_isalpha(rgb[i]))
			return_error("Error! Not valide color.\n", cub);
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
		return_error("Error! Not valide color.\n", cub);
}

int						parse_color(char *line, t_cub *cub)
{
	char				**rgb;
	int					r;
	int					g;
	int					b;

	rgb = ft_split(line, ',');
	if (rgb[3] || !rgb[0] || !rgb[2] || !rgb[1])
		return_error("Error! RGB: XXX, XXX, XXX\n", cub);
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
		return_error("Error! RGB range: 0 - 255\n", cub);
	return (((r & 0x0ff) << 16) | ((g & 0x0ff) << 8) | (b & 0x0ff));
}
