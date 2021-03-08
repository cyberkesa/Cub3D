/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:44:12 by vwinfred          #+#    #+#             */
/*   Updated: 2021/03/03 22:16:41 by bmicheal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "get_next_line.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>
# include <mlx.h>

# define NO_FREE 1
# define TEX 4
# define FD_TEX 4
# define FREE_ALL 8
# define ESC 53
# define MOVE_LEFT 0
# define MOVE_RIGHT 2
# define MOVE_FORTH 13
# define MOVE_BACK 1
# define MOVE_SPEED 257
# define TURN_LEFT 123
# define TURN_RIGHT 124
# define BMP_H_SIZE 14
# define BMP_I_SIZE 40
# define COLLISION 0.16
# define STEP 0.10
# define COS_ROT cos(0.05)
# define SIN_ROT sin(0.05)
# define NEG_COS_ROT cos(-0.05)
# define NEG_SIN_ROT sin(-0.05)
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

typedef struct				s_textures
{
	char					*path;
	void					*image_data;
	void					*image_ptr;
	int						size_line;
	int						endian;
	int						width;
	int						height;
	int						bpp;
}							t_textures;

typedef struct				s_flags
{
	bool					screen;
	bool					parce_map_start;
	bool					texture_okey;
	bool					ceiling_color_ok;
	bool					floor_color_ok;
	bool					tex_no;
	bool					tex_so;
	bool					tex_ea;
	bool					tex_we;
	bool					tex_s;
	bool					resolution;
	bool					perp_allocate;
	bool					sprite_allocate;
	bool					map_allocate;
}							t_flags;

typedef struct				s_plr
{
	char					nswe;
	double					x;
	double					y;
}							t_plr;

typedef	struct				s_sprites
{
	size_t					sprite_id;
	double					x;
	double					y;
	int						pos_in_map_x;
	int						pos_in_map_y;
}							t_sprites;

typedef	struct				s_spr
{
	size_t					loop_sprites;
	double					sprite_x;
	double					sprite_y;
	double					invdet;
	double					tr_x;
	double					tr_y;
	int						s_screen_x;
	int						sp_height;
	int						sp_width;
	int						start_x;
	int						end_x;
	int						start_y;
	int						end_y;
	int						tex_x;
	int						tex_y;
	int						v_move;
	int						color;
	int						d;
	int						y;
	int						stripe;
}							t_spr;

typedef	struct				s_ray
{
	double					dir_x;
	double					dir_y;
	double					plane_x;
	double					plane_y;
	double					perp_wall;
	double					side_dist_x;
	double					side_dist_y;
	double					delta_dist_x;
	double					delta_dist_y;
	double					ray_dir_x;
	double					ray_dir_y;
	int						side;
	int						step_x;
	int						step_y;
	int						x_int;
	int						y_int;
	int						color;
}							t_ray;

typedef	struct				s_cub
{
	t_textures				tex[5];
	t_plr					plr;
	t_ray					ray;
	t_spr					spr;
	t_flags					flags;
	size_t					val_sprites;
	t_sprites				*sprites;
	char					**map;
	double					*sp_dist;
	double					*perp_for_sprites;
	int						*sp_order;
	int						*image_data;
	void					*mlx;
	void					*cub_win_ptr;
	void					*image;
	double					fov;
	double					cam_x;
	double					wall_x;
	double					tex_pos;
	double					step;
	int						fd;
	int						fd_for_number_line;
	int						image_line;
	int						image_size;
	int						size_line;
	int						bpp;
	int						endian;
	int						width;
	int						height;
	int						floor_color;
	int						ceiling_color;
	int						t_id;
	int						pressed_key;
	int						move_forth;
	int						move_back;
	int						move_left;
	int						move_right;
	int						move_speed;
	int						turn_left;
	int						turn_right;
	int						map_number_line;
	int						fd_number_line;
	int						loop;
	int						hit;
	int						line_height;
	int						draw_start;
	int						draw_end;
	int						tex_x;
	int						tex_y;
	int						r;
	int						g;
	int						b;
}							t_cub;

int							main(int argc, char **argv);
void						check_valid_argc(int argc, char **argv, t_cub *cub);
int							ft_exit(t_cub *cub);
int							tex_keys(t_cub *cub);
int							draw(t_cub *cub);
int							turn_on(int key, void *arg);
int							turn_off(int key, void *arg);
int							check_nswe(t_cub *cub, char *line);
int							parse_color(char *line, t_cub *cub);
void						parce_number_line(t_cub *cub);
void						parce_ceiling_color(char *line, t_cub *cub);
void						parce_floor_color(char *line, t_cub *cub);
void						general_parce(t_cub *cub);
void						parce_r(char *line, t_cub *cub);
void						parce_map(t_cub *cub, char *line);
void						parce_no(char *line, t_cub *cub);
void						parce_so(char *line, t_cub *cub);
void						parce_we(char *line, t_cub *cub);
void						parce_ea(char *line, t_cub *cub);
void						parce_s(char *line, t_cub *cub);
void						nswe(t_cub *cub);
void						ft_freeleak(t_cub *win);
void						free_array(char **r);
void						mlx_start(t_cub *cub);
void						draw_background(t_cub *cub);
void						draw_sprites(t_cub *cub);
void						set_pixel(t_cub *cub, int x, int y, int color);
void						get_sprite_val(t_cub *cub);
void						parce_struct_sprites(t_cub *cub);
void						ray_cast(t_cub *cub);
void						return_error(char *error, t_cub *cub);
void						press(t_cub *cub);
void						check_wall(t_cub *cub, int x, int y);
void						check_map_validate(t_cub *cub);
void						check_map_closed(t_cub *cub);
void						check_two_commas(char *line, t_cub *cub);
void						check_player_pos(t_cub *cub);
void						check_valid_line(char *line, t_cub *cub);
void						check_first_line(char *line, t_cub *cub);
void						check_last_line(t_cub *cub);
void						check_maybe_not_valid_line(char *line, t_cub *cub);
void						check_keys_true(t_cub *cub);
void						mlx_texture(t_cub *cub);
void						make_texture_pixel_array(t_cub *cub, int num);
void						set_side_texture(t_cub *cub);
void						ray_step(t_cub *cub);
void						ray_math(t_cub *cub, int loop);
void						ray_hit(t_cub *cub);
void						ray_wall_x(t_cub *cub);
void						ray_perp(t_cub *cub);
void						ray_start_end(t_cub *cub);
void						bmp_info(t_cub *cub, int fd);
void						get_pixel(t_cub *cub, int fd);
void						bmp_header(t_cub *cub);
int							turn_off(int key, void *arg);
void						mlx_hl(t_cub *cub);
void						parce_and_check(t_cub *cub);
void						move_turn(t_cub *cub, double cos, double sin);
void						move_right_and_left(t_cub *cub, int init);
void						move_forth_and_back(t_cub *cub, int init);
void						move_speed(t_cub *cub);
void						sort_sprite(t_cub *s);
void						get_sprites_pos(t_cub *cub);
void						sprites_draw_start_end(t_cub *cub);
void						sprite_math(t_cub *cub);
int							draw_init(t_cub *cub);
void						color_sprite(t_cub *cub);
void						draw_sprites(t_cub *cub);
void						ray_sprites(t_cub *cub);
void						check_valide_pos_sprite(t_cub *cub, int x, int y);
void						ft_free_more(t_cub *cub);
void						check_one_more_null(int color,
							char *rgb, t_cub *cub);
void						null_all_pointer(t_cub *cub);
void						cub_allocate_perp_sprites(t_cub *cub);
void						cub_allocate_sprites(t_cub *cub);
void						cub_allocate_map(t_cub *cub);
int							cub_args_and_fd(t_cub *cub, int argc, char **argv);
void						cub_error(char *error, t_cub *cub, int code);
void						re_map_tex_fd_color(t_cub *cub);
int							free_all_and_exit(t_cub *cub);
void						cub_free_textures(t_cub *cub);
void						cub_free_sprites(t_cub *cub);
void						cub_free_mlx(t_cub *cub);
void						cub_free_map(t_cub *cub);
void						cub_free_perp(t_cub *cub);
void						colors_check(t_cub *cub, char *red,
							char *green, char *blue);
void						check_line_resolution(char *line, t_cub *cub);
void						check_line_color(t_cub *cub, char *color);
void						super_check_number_element_colors(t_cub *cub,
							char *color);

#endif
