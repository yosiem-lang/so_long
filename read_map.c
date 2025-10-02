/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:00:57 by oshie             #+#    #+#             */
/*   Updated: 2025/10/02 15:07:09 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_info(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->collectible_count = 0;
}

void	validate_line_chars(t_map *map, char *line, int len, t_game *game)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (line[i] == 'P')
		{
			if (map->player_x != -1)
				output_error_and_exit(ERROR_MISSING_PLAYER, game, 0);
			map->player_x = i;
			map->player_y = map->height;
		}
		else if (line[i] == 'C')
			map->collectible_count++;
		else if (line[i] != '0' && line[i] != '1' && line[i] != 'E')
			output_error_and_exit(ERROR_INVALID_CHAR, game, 0);
		i++;
	}
}

static void	process_line_dimensions(t_map *map,
	char *line, int len, t_game *game)
{
	if (map->width == 0)
		map->width = len;
	if (len != map->width)
	{
		free(line);
		output_error_and_exit(ERROR_NOT_RECTANGULAR, game, 0);
	}
	validate_line_chars(map, line, len, game);
	map->height++;
}

void	count_map_dimensions(const char *path, t_map *map, t_game *game)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		output_error_and_exit(ERROR_FILE_ACCESS, game, 0);
	init_map_info(map);
	line = read_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		if (len > 0)
			process_line_dimensions(map, line, len, game);
		free(line);
		line = read_next_line(fd);
	}
	free(line);
	close(fd);
	if (map->height == 0)
		output_error_and_exit(ERROR_NOT_RECTANGULAR, game, 1);
}
