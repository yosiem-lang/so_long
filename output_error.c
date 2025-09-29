/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:33:47 by oshie             #+#    #+#             */
/*   Updated: 2025/09/29 13:25:15 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	output_error_and_exit(int sign)
{
	ft_printf("Error\n");
	if (sign == ERROR_FILE_ACCESS)
		ft_printf("File does not exist or cannot be read.\n");
	else if (sign == ERROR_INVALID_EXTENSION)
		ft_printf("Invalid file extension. Map file must end with .ber.\n");
	else if (sign == ERROR_NOT_RECTANGULAR)
		ft_printf("Map is not a perfect rectangle.\n");
	else if (sign == ERROR_NOT_ENCLOSED)
		ft_printf("Map is not enclosed by walls.\n");
	else if (sign == ERROR_INVALID_CHAR)
		ft_printf("Map contains an invalid character.\n");
	else if (sign == ERROR_MISSING_PLAYER)
		ft_printf("Map must contain exactly one player starting position.\n");
	else if (sign == ERROR_MISSING_EXIT)
		ft_printf("Map must contain exactly one exit.\n");
	else if (sign == ERROR_MISSING_COLLECTIBLE)
		ft_printf("Map must contain at least one collectible.\n");
	else if (sign == ERROR_NO_VALID_PATH)
		ft_printf("There is no valid path.\n");
	else if (sign == ERROR_MALLOC_FAIL)
		ft_printf("Memory allocation failed.\n");
	else
		ft_printf("An unknown error occurred.\n");
	exit(1);
}
