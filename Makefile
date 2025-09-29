# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshie <oshie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 12:01:04 by oshie             #+#    #+#              #
#    Updated: 2025/09/06 12:01:09 by oshie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX_FLAGS = -L./mlx -lmlx_Linux -lXext -lX11 -lm
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf
INCLUDES = -I. -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I./get_next_line

SRCS = so_long.c \
       read_map.c \
       map_check.c \
       output_error.c \
       output_map.c \
       game_logic.c

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(MLX_FLAGS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_DIR)/libftprintf.a:
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus