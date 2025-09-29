/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:48:10 by oshie             #+#    #+#             */
/*   Updated: 2025/09/28 13:44:25 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_enclosed_by_walls(t_map *map)
{
	int i;
	int j;

	// 上端と下端のチェック
	j = 0;
	while (j < map->width)
	{
		if (map->grid[0][j] != '1' || map->grid[map->height - 1][j] != '1')
			return (0); // 壁ではない
		j++;
	}

	// 左端と右端のチェック
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0); // 壁ではない
		i++;
	}
	
	return (1); // 有効な壁
}

// キューにノードを追加
void enqueue(t_node **queue, int x, int y)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return;
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	
	if (!*queue)
		*queue = new_node;
	else
	{
		t_node *current = *queue;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

// キューからノードを取り出し
t_node *dequeue(t_node **queue)
{
	if (!*queue)
		return NULL;
	
	t_node *first = *queue;
	*queue = (*queue)->next;
	return first;
}

// マップのコピーを解放
void free_grid_copy(char **grid, int height)
{
	int i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

// 幅優先探索 (BFS) を使って経路を検証する関数
int has_valid_path(t_map *map)
{
	char    **temp_grid = copy_grid(map->grid, map->height);
	if (!temp_grid)
		return (0);
	
	t_node  *queue = NULL;
	int     reachable_collectibles = 0;
	int     exit_reachable = 0;
	t_node *current;
    int     dx[] = {0, 0, 1, -1}; // x方向の移動 (右, 左)
    int     dy[] = {1, -1, 0, 0}; // y方向の移動 (下, 上)
	
	// プレイヤーの初期位置をキューに追加
	enqueue(&queue, map->player_x, map->player_y);
	temp_grid[map->player_y][map->player_x] = 'V';
	while (queue)
	{
		current = dequeue(&queue);
		// 訪問中のマスがコレクタブルか、出口かチェック
		if (map->grid[current->y][current->x] == 'C')
			reachable_collectibles++;
		if (map->grid[current->y][current->x] == 'E')
			exit_reachable = 1;

		// 上下左右の隣接マスを探索
		for (int i = 0; i < 4; i++)
		{
			int next_x = current->x + dx[i];
			int next_y = current->y + dy[i];

			// 境界チェック
			if (next_x >= 0 && next_x < map->width && 
				next_y >= 0 && next_y < map->height)
			{
				char next_tile = temp_grid[next_y][next_x];
				
				// 壁 ('1') でなく、まだ訪問していないマスの場合
				// 'E'も探索を続ける必要があるため、'V'でないことをチェック
				if (next_tile != '1' && next_tile != 'V')
				{
					// キューに追加
					enqueue(&queue, next_x, next_y);
					// 訪問済みとしてマーク
					temp_grid[next_y][next_x] = 'V';
				}
			}
		}
		free(current);
	}
	
	// すべてのコレクタブルと出口に到達可能かチェック
	int result = (reachable_collectibles == map->collectible_count && exit_reachable);
	
	free_grid_copy(temp_grid, map->height);

    while (queue)
    {
        current = dequeue(&queue);
        free(current);
    }
	return (result);
}

char **copy_grid(char **grid, int height)
{
    char **copy = malloc(sizeof(char *) * (height + 1));
    if (!copy)
        return NULL;

    int i = 0;
    while (i < height)
    {
        copy[i] = malloc(strlen(grid[i]) + 1);
        if (!copy[i])
        {
            while (i > 0)
                free(copy[--i]);
            free(copy);
            return NULL;
        }
        strcpy(copy[i], grid[i]);
        i++;
    }
    copy[i] = NULL;
    return copy;
}
