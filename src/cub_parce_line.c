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
		if (line[2] != ' ')
			cub_error("Error! Where whitespace after 'NO'.\n", cub, FD_TEX);
	}
	else
		cub_error("Error! Doubles texture NO.\n", cub, FD_TEX);
}

void					parce_so(char *line, t_cub *cub)
{
	if (cub->flags.tex_so == 0)
	{
		cub->tex[0].path = ft_strtrim(line + 2, " ");
		cub->flags.tex_so = 1;
		if (line[2] != ' ')
			cub_error("Error! Where whitespace after 'SO'.\n", cub, FD_TEX);
	}
	else
		cub_error("Error! Doubles texture SO.\n", cub, FD_TEX);
}

void					parce_we(char *line, t_cub *cub)
{
	if (cub->flags.tex_we == 0)
	{
		cub->tex[3].path = ft_strtrim(line + 2, " ");
		cub->flags.tex_we = 1;
		if (line[2] != ' ')
			cub_error("Error! Where whitespace after 'WE'.\n", cub, FD_TEX);
	}
	else
		cub_error("Error! Doubles texture WE.\n", cub, FD_TEX);
}

void					parce_ea(char *line, t_cub *cub)
{
	if (cub->flags.tex_ea == 0)
	{
		cub->tex[2].path = ft_strtrim(line + 2, " ");
		cub->flags.tex_ea = 1;
		if (line[2] != ' ')
			cub_error("Error! Where whitespace after 'EA'.\n", cub, FD_TEX);
	}
	else
		cub_error("Error! Doubles texture EA.\n", cub, FD_TEX);
}

void					parce_s(char *line, t_cub *cub)
{
	if (cub->flags.tex_s == 0)
	{
		cub->tex[4].path = ft_strtrim(line + 1, " ");
		cub->flags.tex_s = 1;
		if (line[1] != ' ')
			cub_error("Error! Where whitespace after 'S'.\n", cub, FD_TEX);
	}
	else
		cub_error("Error! Doubles texture S.\n", cub, FD_TEX);
}
