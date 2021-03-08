# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:04:48 by vwinfred          #+#    #+#              #
#    Updated: 2021/02/16 16:55:00 by vwinfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = Libft/libft.a

OBJD = objects/

SRS =	main.c \
		cub_parce.c \
		cub_parce_line.c \
		cub_parce_keys.c \
		cub_parce_color.c \
		cub_check_error.c \
		cub_check_map.c \
		cub_check_map_1.c \
		cub_parce_check_sprites.c \
		cub_parce_resolution.c \
		cub_args_number_line.c \
		cub_make_texture.c \
		cub_mlx.c \
		cub_allocate_memory.c \
		cub_drawing.c \
		cub_sprites.c \
		cub_raycast.c \
		cub_raycast_1.c \
		cub_raysprites.c \
		cub_player_move.c \
		cub_keyboard.c \
		cub_clean.c \
		cub_returnes.c \
		cub_utils.c \
		cub_screen.c

SRCD = src/

OBJECTS =	$(addprefix $(OBJD), $(patsubst %.c, %.o, $(SRS)))

INCLUDES = -I inc/ -I Libft/

CFLAGS  = -O2 -g -Wall -Werror -Wextra -pipe -msse -msse2 -msse3 -mmmx -m3dnow

MINILIBFLAGS = -framework OpenGL -framework AppKit -lmlx

CC = gcc

all: $(NAME)

$(NAME):: $(LIBFT) $(OBJD)
$(NAME):: $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(INCLUDES) $^ $(MINILIBFLAGS) $(LIBFT)
	@printf "\x1b[7m Create: "
	@printf $@
	@printf "\x1b[7m\n"

$(LIBFT):
	@make -C ./Libft

$(OBJD)%.o: $(SRCD)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "\x1b[2m\x1b[m Compile object: "
	@printf $(notdir $@)
	@printf "\x0b\n"

$(OBJD):
	@mkdir -p $@

clean:
	@make clean -C ./Libft
	@rm -rf $(OBJD)

fclean: clean
	@make fclean -C ./Libft
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
