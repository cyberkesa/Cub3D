/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:20:00 by vwinfred          #+#    #+#             */
/*   Updated: 2021/02/26 20:20:00 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					get_pixel(t_cub *cub, int fd)
{
	unsigned char		buf[4];
	int					i;
	int					a;

	i = cub->width * (cub->height - 1);
	while (i >= 0)
	{
		a = 0;
		while (a < cub->width)
		{
			buf[0] = (unsigned char)(cub->image_data[i] % 256);
			buf[1] = (unsigned char)(cub->image_data[i] / 256 % 256);
			buf[2] = (unsigned char)(cub->image_data[i] / 256 / 256 % 256);
			buf[3] = (unsigned char)(0);
			write(fd, buf, 4);
			i++;
			a++;
		}
		i -= 2 * cub->width;
	}
	close(fd);
	// free_all(cub);
	exit(0);
}

void					bmp_info(t_cub *cub, int fd)
{
	char				*info;

	if (!(info = ft_calloc(BMP_I_SIZE, 1)))
		return_error("Error! With screen.\n", cub);
	info[0] = BMP_I_SIZE;
	info[4] = cub->width;
	info[5] = cub->width >> 8;
	info[6] = cub->width >> 16;
	info[7] = cub->width >> 24;
	info[8] = cub->height;
	info[9] = cub->height >> 8;
	info[10] = cub->height >> 16;
	info[11] = cub->height >> 24;
	info[12] = 1;
	info[14] = cub->bpp;
	write(fd, info, BMP_I_SIZE);
	free(info);
	get_pixel(cub, fd);
}

void					bmp_header(t_cub *cub)
{
	int					fd;
	int					size;
	char				*header;

	if ((fd = open("img.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0777)) < 0)
		return_error("Error! With screen.\n", cub);
	if (!(header = ft_calloc(BMP_H_SIZE, 1)))
		return_error("Error! With screen.\n", cub);
	size = cub->height * (cub->width * cub->bpp / 8) + BMP_H_SIZE + BMP_I_SIZE;
	header[0] = 'B';
	header[1] = 'M';
	header[2] = size;
	header[3] = size >> 8;
	header[4] = size >> 16;
	header[5] = size >> 24;
	header[10] = BMP_H_SIZE + BMP_I_SIZE;
	write(fd, header, BMP_H_SIZE);
	free(header);
	bmp_info(cub, fd);
}
