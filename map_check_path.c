/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:40:12 by oshie             #+#    #+#             */
/*   Updated: 2025/10/05 13:40:02 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bfs	init_bfs(t_map *map, char **grid, int mode)
{
	t_bfs	bfs;

	bfs.queue = NULL;
	bfs.grid = grid;
	bfs.map = map;
	bfs.collected = 0;
	bfs.exit_found = 0;
	bfs.mode = mode;
	bfs.dx[0] = 0;
	bfs.dx[1] = 0;
	bfs.dx[2] = 1;
	bfs.dx[3] = -1;
	bfs.dy[0] = 1;
	bfs.dy[1] = -1;
	bfs.dy[2] = 0;
	bfs.dy[3] = 0;
	enqueue(&bfs.queue, map->player_x, map->player_y);
	bfs.grid[map->player_y][map->player_x] = 'V';
	return (bfs);
}

void	bfs_explore(t_map *map, char **grid, int mode)
{
	t_bfs	bfs;
	t_node	*cur;

	bfs = init_bfs(map, grid, mode);
	while (bfs.queue)
	{
		cur = dequeue(&bfs.queue);
		explore_node(&bfs, cur);
	}
	while (bfs.queue)
		free(dequeue(&bfs.queue));
	if ((mode == 1 && bfs.collected != map->collectible_count)
		|| (mode == 2 && !bfs.exit_found))
		output_error_and_exit(ERROR_NO_VALID_PATH, NULL, 1);
}

int	has_valid_path(t_map *map, t_game *game)
{
	char	**temp_grid;

	temp_grid = copy_grid(map->grid, map->height);
	if (!temp_grid)
		output_error_and_exit(ERROR_NO_VALID_PATH, game, 1);
	bfs_explore(map, temp_grid, 1);
	free_grid_copy(temp_grid, map->height);
	temp_grid = copy_grid(map->grid, map->height);
	if (!temp_grid)
		output_error_and_exit(ERROR_NO_VALID_PATH, game, 1);
	bfs_explore(map, temp_grid, 2);
	free_grid_copy(temp_grid, map->height);
	return (1);
}
