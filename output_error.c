/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:33:47 by oshie             #+#    #+#             */
/*   Updated: 2025/10/02 15:10:57 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_resources(t_game *game, int check)
{
	if (game && game->map.grid)
		free_map(game->map.grid);
	if (check != 1)
		close(check);
	if (game)
		free(game);
}

void	output_error_and_exit(int sign, t_game *game, int check)
{
	cleanup_resources(game, check);
	ft_putstr_fd("Error\n", 1);
	if (sign == ERROR_FILE_ACCESS)
		ft_putstr_fd("File does not exist or cannot be read.\n", 1);
	else if (sign == ERROR_INVALID_EXTENSION)
		ft_putstr_fd("Invalid file extension.\n", 1);
	else if (sign == ERROR_NOT_RECTANGULAR)
		ft_putstr_fd("Map is not a perfect rectangle.\n", 1);
	else if (sign == ERROR_NOT_ENCLOSED)
		ft_putstr_fd("Map is not enclosed by walls.\n", 1);
	else if (sign == ERROR_INVALID_CHAR)
		ft_putstr_fd("Map contains an invalid character.\n", 1);
	else if (sign == ERROR_MISSING_PLAYER)
		ft_putstr_fd("Map must contain exactly one player.\n", 1);
	else if (sign == ERROR_MISSING_EXIT)
		ft_putstr_fd("Map must contain exactly one exit.\n", 1);
	else if (sign == ERROR_MISSING_COLLECTIBLE)
		ft_putstr_fd("Map must contain at least one collectible.\n", 1);
	else if (sign == ERROR_NO_VALID_PATH)
		ft_putstr_fd("There is no valid path.\n", 1);
	else if (sign == ERROR_MALLOC_FAIL)
		ft_putstr_fd("Memory allocation failed.\n", 1);
	else
		ft_putstr_fd("An unknown error occurred.\n", 1);
	exit(1);
}
