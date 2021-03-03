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
	static	int			i = 0;

	check_two_commas(line, cub);
	cub->ceiling_color = parse_color(ft_strtrim(line, "C "), cub);
	i++;
	if (i > 1)
		return_error("Error! Color's doubles.\n", cub);
}

void					parce_floor_color(char *line, t_cub *cub)
{
	static	int			i = 0;

	check_two_commas(line, cub);
	cub->floor_color = parse_color(ft_strtrim(line, "F "), cub);
	i++;
	if (i > 1)
		return_error("Error! Color's doubles.\n", cub);
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
		return_error("Error! Commas troubles.\n", cub);
	return ;
}
