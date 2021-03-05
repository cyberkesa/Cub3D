#include "cub.h"

void					null_all_pointer(t_cub *cub)
{
	int					i;

	i = 0;
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
