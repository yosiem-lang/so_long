/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:00:57 by oshie             #+#    #+#             */
/*   Updated: 2025/09/29 10:40:04 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void validate_initial_map(const char *map_path, t_map *map_info)
{
	int     fd;
	char    *line;
	int     len;
	int 	i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		output_error_and_exit(ERROR_FILE_ACCESS);

	map_info->width = 0;
	map_info->height = 0;
	map_info->player_x = -1;
	map_info->player_y = -1;
	map_info->collectible_count = 0;

	while ((line = get_next_line(fd)) != NULL)
	{
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		if (len == 0)
		{
			free(line);
			continue ;
		}
		if (map_info->width == 0)
			map_info->width = len;
		if (len != map_info->width)
		{
			free(line);
			close(fd);
			output_error_and_exit(ERROR_NOT_RECTANGULAR);
		}
		i = 0;
		while (i < len)
		{
			if (line[i] == 'P')
			{
				if (map_info->player_x != -1)
					output_error_and_exit(ERROR_MISSING_PLAYER);
				map_info->player_x = i;
				map_info->player_y = map_info->height;
			}
			else if (line[i] == 'E')
			{
				
			}
			else if (line[i] == 'C')
				map_info->collectible_count++;
			else if (line[i] != '0' && line[i] != '1')
			{
				free(line);
				close(fd);
				output_error_and_exit(ERROR_INVALID_CHAR);
			}
			i++;
		}
		free(line);
		map_info->height++;
	}
	close(fd);

	if (map_info->height == 0)
		output_error_and_exit(ERROR_NOT_RECTANGULAR);
}

static void validate_map_structure(t_map *map)
{
	int i = 0;
	int j;
	int exit_count = 0;

	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			output_error_and_exit(ERROR_NOT_ENCLOSED);
		i++;
	}
	j = 0;
	while (j < map->height)
	{
		if (map->grid[j][0] != '1' || map->grid[j][map->width - 1] != '1')
			output_error_and_exit(ERROR_NOT_ENCLOSED);
		
		if (strchr(map->grid[j], 'E'))
			exit_count++;
		
		j++;
	}

	if (map->player_x == -1)
		output_error_and_exit(ERROR_MISSING_PLAYER);
	if (exit_count != 1)
		output_error_and_exit(ERROR_MISSING_EXIT);
	if (map->collectible_count < 1)
		output_error_and_exit(ERROR_MISSING_COLLECTIBLE);
}

static void validate_path(t_map *map)
{
	if (!has_valid_path(map))
		output_error_and_exit(ERROR_NO_VALID_PATH);
}

char    **read_and_validate_map(const char *map_path, t_map *map_info)
{
	int     fd;
	char    **map;
	int     i = 0;
	char	*line;
	int len;

	validate_initial_map(map_path, map_info);

	map = (char **)malloc(sizeof(char *) * (map_info->height + 1));
	if (!map)
		output_error_and_exit(ERROR_MALLOC_FAIL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	    output_error_and_exit(ERROR_FILE_ACCESS);
	while (i < map_info->height)
	{
		line = get_next_line(fd);
		printf("DEBUG: line = %s\n", line);
		if (!line)
		{
			printf("DEBUG: get_next_line returned NULL at i=%d\n", i);
			while (i > 0)
				free(map[--i]);
			free(map);
			close(fd);
			output_error_and_exit(ERROR_MALLOC_FAIL);
		}
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';

		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	printf("map_info->height = %d, map_info->width = %d\n", map_info->height, map_info->width);
	map_info->grid = map;

	validate_map_structure(map_info);
	validate_path(map_info);
	
	return map;
}

void    free_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
