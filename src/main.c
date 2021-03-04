/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:47:14 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/03 23:33:05 by bmicheal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					valid_argc(int argc, char **argv, t_cub *cub)
{
	int					argv_len;

	argv_len = (int)ft_strlen(argv[1]) - 1;
	if (argv[1][argv_len - 3] != '.'
	&& argv[1][argv_len - 2] != 'c'
	&& argv[1][argv_len - 1] != 'u'
	&& argv[1][argv_len] != 'b')
		return_error("Error! Need .cub.\n", cub);
	if (argc == 3 && argv[2][0] == '-'
	&& argv[2][1] == '-' && argv[2][2] == 's'
	&& argv[2][3] == 'a' && argv[2][4] == 'v'
	&& argv[2][5] == 'e' && argv[2][6] == '\0')
		cub->flags.screen = 1;
	else if (argc == 3)
		return_error("Error! Not valide number of arguments.\n", cub);
}

void					parce_and_check(t_cub *cub,
						int fd_for_number_line, int fd)
{
	parce_number_line(cub, fd_for_number_line);
	general_parce(cub, fd);
	check_keys_true(cub);
	check_player_pos(cub);
	check_last_line(cub);
	check_map_validate(cub);
	check_map_closed(cub);
	cub->pressed_key = -1;
	cub->plr.x += 0.5;
	cub->plr.y += 0.5;
	nswe(cub);
	get_sprite_val(cub);
	parce_struct_sprites(cub);
}

void					return_error(char *error, t_cub *cub)
{
	int					len;

	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}

int						ft_exit(t_cub *cub)
{
	ft_freeleak(cub);
	if (cub->image)
		mlx_destroy_image(cub->mlx, cub->image);
	if (cub->cub_win_ptr)
		mlx_destroy_window(cub->mlx, cub->cub_win_ptr);
	exit(0);
}

void					init_bm(t_cub *cub)
{
	int i = 0;
	while (i < 5)
	{
		cub->tex[i].image_data = NULL;
		cub->tex[i].image_ptr = NULL;
		cub->tex[i].path = NULL;
		i++;
	}
	cub->sprites = NULL;
	cub->map = NULL;
	cub->sp_dist = NULL;
	cub->perp_for_sprites = NULL;
	cub->sp_order = NULL;
	cub->image_data = NULL;
	cub->mlx = NULL;
	cub->cub_win_ptr = NULL;
	cub->image = NULL;
}

int						main(int argc, char **argv)
{
	t_cub				cub;
	int					fd_for_number_line;
	int					fd;

	if (!argv[1])
		return_error("Error argv.\n", &cub);
	ft_bzero(&cub, sizeof(t_cub));
	valid_argc(argc, argv, &cub);
	fd = open(argv[1], O_RDONLY);
	fd_for_number_line = open(argv[1], O_RDONLY);
	if (fd_for_number_line < 0 || fd < 0)
		return_error("Error argv.\n", &cub);
//	close(fd);
//	close(fd_for_number_line);
	init_bm(&cub);
	parce_and_check(&cub, fd_for_number_line, fd);
	cub.mlx = mlx_init();
	cub.cub_win_ptr = mlx_new_window(cub.mlx, cub.width, cub.height, "Cub3D");
	mlx_start(&cub);
	draw(&cub);
	if (cub.flags.screen == 1)
		bmp_header(&cub);
	mlx_hl(&cub);
	return (0);
}
