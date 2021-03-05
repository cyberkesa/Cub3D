#include "cub.h"


void					return_error(char *error, t_cub *cub)
{
	int					len;

	// close(fd);
	// ft_freeleak(cub);
	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}

void					re_exit_mlx_clean_all(char *error, t_cub *cub)
{
	int					len;

	ft_freeleak(cub);
	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}

void					re_free_only_map(char *error, t_cub *cub)
{
	int					len;

	ft_freeleak(cub);
	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}

void					re_free_map_tex_and_sprites(char *error, t_cub *cub)
{
	int					len;

	ft_freeleak(cub);
	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}

void					error_map_tex_fd(char *error, t_cub *cub)
{
	int					len;

	// close(fd);
	ft_freeleak(cub);
	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}

void					re_free_map_and_tex(char *error, t_cub *cub)
{
	int					len;

	ft_freeleak(cub);
	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}

void					error_map_tex_fd_color(char *error, t_cub *cub)
{
	int					len;

	ft_freeleak(cub);
	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}

void					error_map_tex_color(char *error, t_cub *cub)
{
	int					len;

	ft_freeleak(cub);
	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}

void					re_no_free(char *error, t_cub *cub)
{
	int					len;

	len = (int)ft_strlen(error);
	write(2, error, len);
	ft_exit(cub);
}


int						ft_exit(t_cub *cub)
{
	if (cub->flags.screen == 0 && cub->flags.texture_okey == 1)
		if (cub->image)
			mlx_destroy_image(cub->mlx, cub->image);
	if (cub->flags.screen == 0 && cub->flags.texture_okey == 1)
		if (cub->cub_win_ptr)
			mlx_destroy_window(cub->mlx, cub->cub_win_ptr);
	exit(0);
}
