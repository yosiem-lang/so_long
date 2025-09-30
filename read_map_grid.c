/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:14:24 by oshie             #+#    #+#             */
/*   Updated: 2025/09/30 12:05:18 by oshie            ###   ########.fr       */
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

char	**read_map_to_grid(const char *path, t_map *map)
{
	int		fd;
	char	**grid;
	char	*line;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		output_error_and_exit(ERROR_FILE_ACCESS);
	grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!grid)
		output_error_and_exit(ERROR_MALLOC_FAIL);
	line = read_next_line(fd);
	while (i < map->height)
	{
		if (!line)
			output_error_and_exit(ERROR_FILE_ACCESS);
		copy_line_to_grid(grid, i++, line);
		line = read_next_line(fd);
	}
	grid[i] = NULL;
	close(fd);
	map->grid = grid;
	return (grid);
}
