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

SRS =	parce.c \
		mlx_init.c \
		mlx_make_texture.c \
		clean.c \
		raycast.c \
		raycast_1.c \
		main.c \
		render.c \
		periphery.c \
		raysprites.c \
		sprites.c \
		parce_check_sprites.c \
		player_move.c \
		check_error.c \
		check_map.c \
		check_map_1.c \
		parce_line.c \
		parce_color.c \
		parce_number_line.c \
		parce_keys.c \
		screen.c

SRCD = src/

OBJECTS =	$(addprefix $(OBJD), $(patsubst %.c, %.o, $(SRS)))

INCLUDES = -I inc/ -I Libft/


CFLAGS = -O2 -Wall -Werror -Wextra
SEGFLAG = -fsanitize=address

MINILIBFLAGS = -framework OpenGL -framework AppKit -lmlx

CC = gcc

all: $(NAME)

$(NAME):: $(LIBFT) $(OBJD)
$(NAME):: $(OBJECTS)
	@$(CC) $(CFLAGS) $(SEGFLAG) -o $@ $(INCLUDES) $^ $(MINILIBFLAGS) $(LIBFT)
	@printf "\x1b[7m Create: "
	@printf $@
	@printf "\x1b[7m\n"

$(LIBFT):
	@make -C ./Libft

$(OBJD)%.o: $(SRCD)%.c
	@$(CC) $(CFLAGS) $(SEGFLAG) $(INCLUDES) -c $< -o $@ -g
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
