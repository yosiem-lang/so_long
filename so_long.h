/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:32:51 by oshie             #+#    #+#             */
/*   Updated: 2025/10/04 19:58:08 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdint.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"

# define TILE_SIZE 64

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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
	void	*img_exit;
	void	*img_player;
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
	int		mode;
}			t_bfs;

void	output_error_and_exit(int sign, t_game *game, int check);
void	cleanup_resources(t_game *game, int check);
void	validate_map_file_extension(const char *path);
char	**read_and_validate_map(const char *path, t_map *map, t_game *game);
void	count_map_dimensions(const char *path, t_map *map, t_game *game);
void	init_map_info(t_map *map);
char	*read_next_line(int fd);
char	get_char(int fd);
char	*put_char(char *str, size_t *i, char c);
char	*re_malloc(char *str, size_t i, char c);
void	validate_line_chars(t_map *map, char *line, int len, t_game *game);
char	**read_map_to_grid(const char *path, t_map *map, t_game *game);
void	validate_map_structure(t_map *map, t_game *game);
int		has_valid_path(t_map *map, t_game *game);
char	**copy_grid(char **grid, int height);
void	bfs_explore(t_map *map, char **grid, int mode);
t_bfs	init_bfs(t_map *map, char **grid, int mode);
void	enqueue(t_node **queue, int x, int y);
t_node	*dequeue(t_node **queue);
void	explore_node(t_bfs *bfs, t_node *cur);
int		should_skip(t_bfs *bfs, int nx, int ny);
void	visit_node(t_bfs *bfs, int nx, int ny);
void	free_grid_copy(char **grid, int height);
void	free_map(char **map);
void	load_textures(t_game *game);
int		draw_map(t_game *game);
void	put_tile_to_window(t_game *game, int x, int y, char tile_type);
int		key_hook(int keycode, t_game *game);
int		close_window(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);

#endif