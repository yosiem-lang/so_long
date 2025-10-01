/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:15:04 by oshie             #+#    #+#             */
/*   Updated: 2025/10/01 16:07:21 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map_structure(t_map *map, t_game *game)
{
	int	i;
	int	j;
	int	exit_count;

	i = 0;
	j = 0;
	exit_count = 0;
	while (i < map->width)
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i++] != '1')
			output_error_and_exit(ERROR_NOT_ENCLOSED, game);
	while (j < map->height)
	{
		if (map->grid[j][0] != '1' || map->grid[j][map->width - 1] != '1')
			output_error_and_exit(ERROR_NOT_ENCLOSED, game);
		if (ft_strchr(map->grid[j], 'E'))
			exit_count++;
		j++;
	}
	if (map->player_x == -1)
		output_error_and_exit(ERROR_MISSING_PLAYER, game);
	if (exit_count != 1)
		output_error_and_exit(ERROR_MISSING_EXIT, game);
	if (map->collectible_count < 1)
		output_error_and_exit(ERROR_MISSING_COLLECTIBLE, game);
}

void	validate_map_path(t_map *map, t_game *game)
{
	if (!has_valid_path(map))
		output_error_and_exit(ERROR_NO_VALID_PATH, game);
}

char	**read_and_validate_map(const char *path, t_map *map, t_game *game)
{
	char	**grid;

	count_map_dimensions(path, map, game);
	grid = read_map_to_grid(path, map, game);
	validate_map_structure(map, game);
	validate_map_path(map, game);
	return (grid);
}
