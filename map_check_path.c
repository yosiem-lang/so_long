/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:40:12 by oshie             #+#    #+#             */
/*   Updated: 2025/09/29 13:14:43 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bfs	init_bfs(t_map *map, char **grid)
{
	t_bfs	bfs;

	bfs.queue = NULL;
	bfs.grid = grid;
	bfs.map = map;
	bfs.dx[0] = 0;
	bfs.dx[1] = 0;
	bfs.dx[2] = 1;
	bfs.dx[3] = -1;
	bfs.dy[0] = 1;
	bfs.dy[1] = -1;
	bfs.dy[2] = 0;
	bfs.dy[3] = 0;
	enqueue(&bfs.queue, map->player_x, map->player_y);
	grid[map->player_y][map->player_x] = 'V';
	return (bfs);
}

static void	explore_node(t_bfs *bfs, t_node *cur,
							int *collected, int *exit_found)
{
	int	i;
	int	nx;
	int	ny;

	i = 0;
	while (i < 4)
	{
		nx = cur->x + bfs->dx[i];
		ny = cur->y + bfs->dy[i];
		if (nx >= 0 && nx < bfs->map->width && ny >= 0 && ny < bfs->map->height)
		{
			if (bfs->grid[ny][nx] != '1' && bfs->grid[ny][nx] != 'V')
			{
				enqueue(&bfs->queue, nx, ny);
				bfs->grid[ny][nx] = 'V';
			}
		}
		i++;
	}
	if (bfs->map->grid[cur->y][cur->x] == 'C')
		(*collected)++;
	if (bfs->map->grid[cur->y][cur->x] == 'E')
		*exit_found = 1;
	free(cur);
}

static void	bfs_explore(t_map *map, char **grid,
						int *collected, int *exit_found)
{
	t_bfs	bfs;
	t_node	*cur;

	bfs = init_bfs(map, grid);
	while (bfs.queue)
	{
		cur = dequeue(&bfs.queue);
		explore_node(&bfs, cur, collected, exit_found);
	}
	while (bfs.queue)
		free(dequeue(&bfs.queue));
}

int	has_valid_path(t_map *map)
{
	char	**temp_grid;
	int		collected;
	int		exit_found;
	int		result;

	temp_grid = copy_grid(map->grid, map->height);
	if (!temp_grid)
		return (0);
	collected = 0;
	exit_found = 0;
	bfs_explore(map, temp_grid, &collected, &exit_found);
	result = (collected == map->collectible_count && exit_found);
	free_grid_copy(temp_grid, map->height);
	return (result);
}
