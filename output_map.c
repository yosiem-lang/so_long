/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:31:33 by oshie             #+#    #+#             */
/*   Updated: 2025/10/01 15:56:23 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/empty.xpm", &w, &h);
	game->img_items = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &w, &h);
	if (!game->img_wall || !game->img_floor || !game->img_items
		|| !game->img_exit || !game->img_player)
		output_error_and_exit(ERROR_FILE_ACCESS, game);
}


void	put_tile_to_window(t_game *game, int x, int y, char tile_type)
{
	if (tile_type == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile_type == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile_type == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile_type == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_items, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile_type == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, x * TILE_SIZE, y * TILE_SIZE);

}

int	draw_map(t_game *game)
{
	int	y;
	int	x;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			put_tile_to_window(game, x, y, game->map.grid[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}
