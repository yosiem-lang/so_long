/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:32:12 by oshie             #+#    #+#             */
/*   Updated: 2025/10/01 15:29:43 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move_to(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	if (game->map.grid[y][x] == '1')
		return (0);
	return (1);
}

static int	handle_exit(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'E')
	{
		if (game->map.collectible_count == 0)
		{
			game->moves++;
			ft_putstr_fd("Moves: ", 1);
			ft_putnbr_fd(game->moves, 1);
			ft_putchar_fd('\n', 1);
			close_window(game);
		}
		return (1);
	}
	return (0);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (!can_move_to(game, new_x, new_y))
		return ;
	if (handle_exit(game, new_x, new_y))
		return ;
	if (game->map.grid[new_y][new_x] == 'C')
		game->map.collectible_count--;
	game->map.grid[game->map.player_y][game->map.player_x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->moves++;
	draw_map(game);
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, game->map.player_x, game->map.player_y - 1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, game->map.player_x - 1, game->map.player_y);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, game->map.player_x, game->map.player_y + 1);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, game->map.player_x + 1, game->map.player_y);
	return (0);
}

int	close_window(t_game *game)
{
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_items)
		mlx_destroy_image(game->mlx, game->img_items);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (!game)
		exit(0);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free (game->mlx);
	}
	if (game->map.grid)
		free_map(game->map.grid);
	free(game);
	exit(0);
	return (0);
}
