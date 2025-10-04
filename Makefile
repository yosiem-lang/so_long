# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshie <oshie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 12:01:04 by oshie             #+#    #+#              #
#    Updated: 2025/10/04 20:00:57 by oshie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
LIBFT_DIR = ./libft
INCLUDES = -I. -I$(MLX_DIR) -I$(LIBFT_DIR)

SRCS = so_long.c \
       read_map.c \
	   read_map_grid.c \
	   validate_map.c \
       map_check.c \
	   map_check_path.c \
	   map_check_path_utils.c \
       output_error.c \
       output_map.c \
       game_logic.c \
	   read_next_line.c \
	   read_next_line_utils.c

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIBFT_DIR)/libft.a $(MLX_FLAGS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re