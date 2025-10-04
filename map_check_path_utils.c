/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:27:40 by oshie             #+#    #+#             */
/*   Updated: 2025/10/04 12:28:06 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	should_skip(t_bfs *bfs, int nx, int ny)
{
	if (nx < 0 || nx >= bfs->map->width || ny < 0 || ny >= bfs->map->height)
		return (1);
	if (bfs->grid[ny][nx] == '1' || bfs->grid[ny][nx] == 'V')
		return (1);
	if (bfs->mode == 1 && bfs->map->grid[ny][nx] == 'E')
		return (1);
	return (0);
}

void	visit_node(t_bfs *bfs, int nx, int ny)
{
	if (bfs->mode == 1 && bfs->map->grid[ny][nx] == 'C')
		bfs->collected++;
	if (bfs->mode == 2 && bfs->map->grid[ny][nx] == 'E')
		bfs->exit_found = 1;
	enqueue(&bfs->queue, nx, ny);
	bfs->grid[ny][nx] = 'V';
}

void	explore_node(t_bfs *bfs, t_node *cur)
{
	int	i;
	int	nx;
	int	ny;

	i = 0;
	while (i < 4)
	{
		nx = cur->x + bfs->dx[i];
		ny = cur->y + bfs->dy[i];
		if (!should_skip(bfs, nx, ny))
			visit_node(bfs, nx, ny);
		i++;
	}
	free(cur);
}
