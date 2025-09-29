/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:31:33 by oshie             #+#    #+#             */
/*   Updated: 2025/09/28 11:15:28 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void *load_texture(void *mlx, const char *rel_path, int *w, int *h)
{
    char full_path[PATH_MAX];
    snprintf(full_path, sizeof(full_path), "/home/oshie/42/so_long_2/%s", rel_path);
    printf("DEBUG: loading %s\n", full_path);   // ←追加
    void *img = mlx_xpm_file_to_image(mlx, full_path, w, h);
    if (!img)
        fprintf(stderr, "DEBUG: Failed to load %s\n", full_path);
    return img;
}

void    load_textures(t_game *game)
{
    int w, h;

    game->img_wall   = load_texture(game->mlx, "textures/wall.xpm", &w, &h);
    game->img_floor  = load_texture(game->mlx, "textures/empty.xpm", &w, &h);
    game->img_items  = load_texture(game->mlx, "textures/collectible.xpm", &w, &h);
    game->img_closed_exit = load_texture(game->mlx, "textures/exit.xpm", &w, &h);
    game->img_opened_exit = game->img_closed_exit; // exit は共用
    game->img_player_front = load_texture(game->mlx, "textures/player.xpm", &w, &h);
    game->img_player_left  = game->img_player_front;
    game->img_player_right = game->img_player_front;
    game->img_player_back  = game->img_player_front;

    if (!game->img_wall || !game->img_floor || !game->img_items
        || !game->img_closed_exit || !game->img_player_front)
    {
        output_error_and_exit(ERROR_FILE_ACCESS);
    }
}

void	put_tile_to_window(t_game *game, int x, int y, char tile_type)
{
	if (tile_type == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile_type == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile_type == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_front, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile_type == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_items, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile_type == 'E')
	{
		if (game->map.collectible_count == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img_opened_exit, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_closed_exit, x * TILE_SIZE, y * TILE_SIZE);
	}
}

int draw_map(t_game *game)
{
	int	y;
	int	x;

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


