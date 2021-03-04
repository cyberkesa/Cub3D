# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:04:48 by vwinfred          #+#    #+#              #
#    Updated: 2020/11/23 12:04:49 by vwinfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a
CC =			gcc
FLAGS =			-Wall -Werror -Wextra
INCLUDES =		-I $(HEADERS_PATH)
HEADERS_LIST =	libft.h
HEADERS_PATH =	./
HEADERS =		$(addprefix $(HEADERS_PATH), $(HEADERS_LIST))
SOURCES_PATH =	./
SOURCES_LIST =	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_unsigned_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_calloc.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strstr.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				get_next_line.c \
				get_next_line_utils.c

SOURCES =		$(addprefix $(SOURCES_PATH), $(SOURCES_LIST))
OBJECTS_PATH =	objects/
OBJECTS_LIST =	$(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	=		$(addprefix $(OBJECTS_PATH), $(OBJECTS_LIST))

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJECTS_PATH) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "\x1b[7mCreate: "
	@printf $@
	@printf "\n\x1b[0m\n"

$(OBJECTS_PATH):
	@mkdir -p $(OBJECTS_PATH)

$(OBJECTS_PATH)%.o : $(SOURCES_PATH)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ -O2
	@printf "\x1b[2m\x1b[m Compile object: "
	@printf $(notdir $@)
	@printf "\x1b[0m\n"
	@printf "\n"

clean:
	@rm -rf $(OBJECTS_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
