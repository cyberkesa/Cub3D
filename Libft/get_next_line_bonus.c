/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:10:12 by vwinfred          #+#    #+#             */
/*   Updated: 2020/12/18 18:10:14 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		buf[1024][BUFFER_SIZE + 1];
	int				reader;
	int				i;

	if (BUFFER_SIZE < 1 || fd < 0 || !line
		|| !(*line = joinrealloc(0, buf[fd])))
		return (-1);
	reader = 1;
	while (ft_strchr(buf[fd], '\n') == NULL && reader)
	{
		reader = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][reader] = 0;
		if (reader == -1 || !(*line = joinrealloc(*line, buf[fd])))
			return (-1);
	}
	if (buf[fd][0] == 0)
		return (0);
	reader = find_endl(buf[fd]) + 1;
	i = 0;
	while (buf[fd][reader])
		buf[fd][i++] = buf[fd][reader++];
	buf[fd][i] = 0;
	return (1);
}
