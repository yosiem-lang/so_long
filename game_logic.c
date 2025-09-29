/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:32:12 by oshie             #+#    #+#             */
/*   Updated: 2025/09/28 13:45:21 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(t_game *game, int new_x, int new_y)
{
	// 境界チェック
	if (new_x < 0 || new_x >= game->map.width || 
		new_y < 0 || new_y >= game->map.height)
		return;
	
	char next_tile = game->map.grid[new_y][new_x];

	// 壁（1）の場合は移動できない
	if (next_tile == '1')
		return;
	
	// 出口（E）の場合
	if (next_tile == 'E')
	{
		if (game->map.collectible_count == 0)
		{
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
			ft_printf("You won! Congratulations!\n");
			close_window(game);
		}
		else
		{
			ft_printf("You need to collect all items first! (%d remaining)\n", game->map.collectible_count);
		}
		return;
	}

	// 収集物（C）を取得
	if (next_tile == 'C')
	{
		game->map.collectible_count--;
		ft_printf("Item collected! (%d remaining)\n", game->map.collectible_count);
	}
	
	// 古いプレイヤー位置を空きスペースに変更
	game->map.grid[game->map.player_y][game->map.player_x] = '0';
	
	// 新しい位置にプレイヤーを配置
	game->map.grid[new_y][new_x] = 'P';
	
	// 古い位置と新しい位置のみを再描画
	draw_map(game);
	
	// プレイヤー位置を更新
	game->map.player_x = new_x;
	game->map.player_y = new_y;

	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

int key_hook(int keycode, t_game *game)
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

int close_window(t_game *game)
{
    if (!game)
        exit(0);
    if (game->win && game->mlx)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
        mlx_destroy_display(game->mlx);
    if (game->map.grid)
        free_map(game->map.grid);
    free(game);
    exit(0);
    return (0);
}
