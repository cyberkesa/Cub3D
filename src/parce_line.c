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
	static int			no = 0;

	cub->tex[1].path = ft_strtrim(line + 2, " ");
	no++;
	if (no > 1)
		return_error("Error texture NO.\n", cub);
}

void					parce_so(char *line, t_cub *cub)
{
	static int			so = 0;

	cub->tex[0].path = ft_strtrim(line + 2, " ");
	so++;
	if (so > 1)
		return_error("Error texture SO.\n", cub);
}

void					parce_we(char *line, t_cub *cub)
{
	static int			we = 0;

	cub->tex[3].path = ft_strtrim(line + 2, " ");
	we++;
	if (we > 1)
		return_error("Error texture WE.\n", cub);
}

void					parce_ea(char *line, t_cub *cub)
{
	static int			ea = 0;

	cub->tex[2].path = ft_strtrim(line + 2, " ");
	ea++;
	if (ea > 1)
		return_error("Error texture EA.\n", cub);
}

void					parce_s(char *line, t_cub *cub)
{
	static int			s = 0;

	cub->tex[4].path = ft_strtrim(line + 1, " ");
	s++;
	if (s > 1)
		return_error("Error texture S.\n", cub);
}
