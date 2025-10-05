/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:14:24 by oshie             #+#    #+#             */
/*   Updated: 2025/10/05 13:51:24 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_line_to_grid(char **grid, int i, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	grid[i] = line;
}

char	**read_map_to_grid(const char *path, t_map *map, t_game *game)
{
	char	**grid;
	char	*line;
	int		i;

	i = 0;
	game->fd = open(path, O_RDONLY);
	if (game->fd < 0)
		output_error_and_exit(ERROR_FILE_ACCESS, game, 0);
	grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!grid)
		output_error_and_exit(ERROR_MALLOC_FAIL, game, 0);
	line = read_next_line(game->fd);
	while (i < map->height)
	{
		if (!line)
			output_error_and_exit(ERROR_FILE_ACCESS, game, 0);
		copy_line_to_grid(grid, i++, line);
		line = read_next_line(game->fd);
	}
	free(line);
	grid[i] = NULL;
	close(game->fd);
	map->grid = grid;
	return (grid);
}
