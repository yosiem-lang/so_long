/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:07:30 by oshie             #+#    #+#             */
/*   Updated: 2025/10/02 15:38:57 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map_file_extension(const char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".ber", 4) != 0)
		output_error_and_exit(ERROR_INVALID_EXTENSION, NULL, 1);
}

static t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		output_error_and_exit(ERROR_MALLOC_FAIL, game, 1);
	return (game);
}

static void	init_mlx_window(t_game *game)
{
	int	win_width;
	int	win_height;

	win_width = game->map.width * TILE_SIZE;
	win_height = game->map.height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game->map.grid);
		output_error_and_exit(ERROR_MALLOC_FAIL, game, 1);
	}
	game->win = mlx_new_window(game->mlx, win_width, win_height, "So Long");
	if (!game->win)
	{
		free_map(game->map.grid);
		output_error_and_exit(ERROR_MALLOC_FAIL, game, 1);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		output_error_and_exit(ERROR_INVALID_EXTENSION, NULL, 1);
	validate_map_file_extension(argv[1]);
	game = init_game();
	ft_memset(game, 0, sizeof(t_game));
	game->map.grid = read_and_validate_map(argv[1], &game->map, game);
	if (!game->map.grid)
		output_error_and_exit(ERROR_FILE_ACCESS, game, 1);
	init_mlx_window(game);
	game->moves = 0;
	load_textures(game);
	draw_map(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_hook, game);
	mlx_hook(game->win, DestroyNotify, 0, close_window, game);
	mlx_hook(game->win, Expose, ExposureMask, draw_map, game);
	mlx_loop(game->mlx);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
