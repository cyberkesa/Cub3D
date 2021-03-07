/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:35:04 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/04 16:35:05 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void					parce_and_check(t_cub *cub)
{
	general_parce(cub);
	check_keys_true(cub);
	check_player_pos(cub);
	check_last_line(cub);
	check_map_validate(cub);
	check_map_closed(cub);
	cub->pressed_key = -1;
	cub->plr.x += 0.5;
	cub->plr.y += 0.5;
	nswe(cub);
	cub_allocate_perp_sprites(cub);
	get_sprite_val(cub);
	if (cub->val_sprites > 0)
	{
		cub_allocate_sprites(cub);
		parce_struct_sprites(cub);
	}
}

int						main(int argc, char **argv)
{
	t_cub				cub;

	null_all_pointer(&cub);
	ft_bzero(&cub, sizeof(t_cub));
	cub.fd = cub_args_and_fd(&cub, argc, argv);
	parce_and_check(&cub);
	cub.mlx = mlx_init();
	cub.cub_win_ptr = mlx_new_window(cub.mlx, cub.width, cub.height, "Cub3D");
	mlx_start(&cub);
	draw(&cub);
	if (cub.flags.screen == 1)
		bmp_header(&cub);
	mlx_hl(&cub);
	return (0);
}
