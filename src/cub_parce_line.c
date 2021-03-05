/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:19:12 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:19:13 by vwinfred         ###   ########.fr       */
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
		re_free_map_and_tex("Error! Doubles texture NO.\n", cub);
}

void					parce_so(char *line, t_cub *cub)
{
	if (cub->flags.tex_so == 0)
	{
		cub->tex[0].path = ft_strtrim(line + 2, " ");
		cub->flags.tex_so = 1;
	}
	else
		re_free_map_and_tex("Error! Doubles texture SO.\n", cub);
}

void					parce_we(char *line, t_cub *cub)
{
	if (cub->flags.tex_we == 0)
	{
		cub->tex[3].path = ft_strtrim(line + 2, " ");
		cub->flags.tex_we = 1;
	}
	else
		re_free_map_and_tex("Error! Doubles texture WE.\n", cub);
}

void					parce_ea(char *line, t_cub *cub)
{
	if (cub->flags.tex_ea == 0)
	{
		cub->tex[2].path = ft_strtrim(line + 2, " ");
		cub->flags.tex_ea = 1;
	}
	else
		re_free_map_and_tex("Error! Doubles texture EA.\n", cub);
}

void					parce_s(char *line, t_cub *cub)
{
	if (cub->flags.tex_s == 0)
	{
		cub->tex[4].path = ft_strtrim(line + 1, " ");
		cub->flags.tex_s = 1;
	}
	else
		re_free_map_and_tex("Error! Doubles texture S.\n", cub);
}
