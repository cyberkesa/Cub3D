/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_number_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:19:19 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:19:20 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					parce_number_line(t_cub *cub, int fd_for_number_line)
{
	char				*line;

	while (get_next_line(fd_for_number_line, &line) == 1)
	{
		if (line[0] == ' ')
			check_maybe_not_valid_line(line, cub);
		if (line[0] == ' ' || line[0] == '1' || line[0] == ' ')
			cub->map_number_line++;
		else
			free(line);
		cub->fd_number_line++;
	}
	free(line);
	cub->map = (char **)malloc(sizeof(char *) * (cub->map_number_line + 1));
	close(fd_for_number_line);
}
