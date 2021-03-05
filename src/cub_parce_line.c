/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parce_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:04:55 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/05 17:04:55 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					parce_no(char *line, t_cub *cub)
{
	if (cub->flags.tex_no == 0)
	{
		cub->tex[1].path = ft_strtrim(line + 2, " ");
		cub->flags.tex_no = 1;
	}
	else
		cub_error("Error! Doubles texture NO.\n", cub, FREE_MAP_TEX_COLOR_FD);
}

void					parce_so(char *line, t_cub *cub)
{
	if (cub->flags.tex_so == 0)
	{
		cub->tex[0].path = ft_strtrim(line + 2, " ");
		cub->flags.tex_so = 1;
	}
	else
		cub_error("Error! Doubles texture SO.\n", cub, FREE_MAP_TEX_COLOR_FD);
}

void					parce_we(char *line, t_cub *cub)
{
	if (cub->flags.tex_we == 0)
	{
		cub->tex[3].path = ft_strtrim(line + 2, " ");
		cub->flags.tex_we = 1;
	}
	else
		cub_error("Error! Doubles texture WE.\n", cub, FREE_MAP_TEX_COLOR_FD);
}

void					parce_ea(char *line, t_cub *cub)
{
	if (cub->flags.tex_ea == 0)
	{
		cub->tex[2].path = ft_strtrim(line + 2, " ");
		cub->flags.tex_ea = 1;
	}
	else
		cub_error("Error! Doubles texture EA.\n", cub, FREE_MAP_TEX_COLOR_FD);
}

void					parce_s(char *line, t_cub *cub)
{
	if (cub->flags.tex_s == 0)
	{
		cub->tex[4].path = ft_strtrim(line + 1, " ");
		cub->flags.tex_s = 1;
	}
	else
		cub_error("Error! Doubles texture S.\n", cub, FREE_MAP_TEX_COLOR_FD);
}
