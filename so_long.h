/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:32:51 by oshie             #+#    #+#             */
/*   Updated: 2025/09/29 13:49:34 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "ft_printf/ft_printf.h"
# include <limits.h>    // PATH_MAX
# include <stdio.h>     // snprintf

# define TILE_SIZE 64

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define ERROR_FILE_ACCESS 1
# define ERROR_INVALID_EXTENSION 2
# define ERROR_NOT_RECTANGULAR 11
# define ERROR_NOT_ENCLOSED 12
# define ERROR_INVALID_CHAR 13
# define ERROR_MISSING_PLAYER 21
# define ERROR_MISSING_EXIT 22
# define ERROR_MISSING_COLLECTIBLE 23
# define ERROR_NO_VALID_PATH 31
# define ERROR_MALLOC_FAIL 99

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectible_count;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_items;
	void	*img_opened_exit;
	void	*img_closed_exit;
	void	*img_player_front;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_player_back;
	t_map	map;
	int		moves;
}			t_game;

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}					t_node;

typedef struct s_bfs
{
	t_map	*map;
	char	**grid;
	int		width;
	int		height;
	int		collected;
	int		exit_found;
	t_node	*queue;
	int		dx[4];
	int		dy[4];
}			t_bfs;


/* error */
void	output_error_and_exit(int sign);

/* map read & validation */
void	init_map_info(t_map *map);
void	validate_line_chars(t_map *map, char *line, int len);
//void	process_line_dimensions(t_map *map, char *line, int len);
void	count_map_dimensions(const char *path, t_map *map);
char	**read_map_to_grid(const char *path, t_map *map);
void	validate_map_structure(t_map *map);
void	validate_map_path(t_map *map);
char	**read_and_validate_map(const char *map_path, t_map *map_info);

/* memory */
void	free_map(char **map);
char	**copy_grid(char **grid, int height);
void	free_grid_copy(char **grid, int height);

/* rendering */
int		draw_map(t_game *game);
void	put_tile_to_window(t_game *game, int x, int y, char tile_type);
void	render_tile(t_game *game, int x, int y, char tile_type);

/* input */
int		key_hook(int keycode, t_game *game);
int		close_window(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);

/* pathfinding */
int		has_valid_path(t_map *map);

/* textures */
void	load_textures(t_game *game);

void	enqueue(t_node **queue, int x, int y);
t_node	*dequeue(t_node **queue);

#endif