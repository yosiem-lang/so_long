// マップが壁で囲まれているかチェック
int is_enclosed_by_walls(t_map *map)
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

/*
4. 有効な経路チェックの考え方（BFS）
ここがso_longの核心的な部分です。すべてのコレクタブルと出口に到達できることを確認します。**幅優先探索（BFS）**を使うのが一般的です。

BFSの基本的な流れ
初期化: プレイヤーの開始位置をキュー（またはリスト）に追加します。訪れたマスを記録する二次元配列（visitedなど）を初期化し、プレイヤーの位置をvisitedにマークします。

探索:

キューが空になるまでループします。

キューの先頭からマスを取り出します。

そのマスがコレクタブルなら、コレクタブルのカウンターを減らします。

そのマスの上下左右4方向について、まだ訪れておらず、かつ壁ではないマスがあれば、それをキューに追加し、visitedにマークします。

結果判定:

ループが終了した時点で、コレクタブルのカウンターが0になっているかを確認します。0であれば、すべてのコレクタブルに到達可能です。

出口（E）にも到達できるかを確認します。
*/

// キューのノード
typedef struct s_node
{
    int             x;
    int             y;
    struct s_node   *next;
}   t_node;

// 幅優先探索 (BFS) を使って経路を検証する関数
int has_valid_path(t_map *map)
{
    // マップのコピーを作成し、探索に使う
    char    **temp_grid = copy_grid(map->grid, map->height);
    // キューの初期化
    t_node  *queue = NULL;
    // ... キューにプレイヤーの初期位置を追加 ...
    
    int     reachable_collectibles = 0;
    int     exit_reachable = 0;

    while (queue) // キューが空になるまでループ
    {
        t_node *current = dequeue(&queue); // キューからノードを取り出す
        // 現在のマスがコレクタブルか、出口かチェック
        if (temp_grid[current->y][current->x] == 'C')
            reachable_collectibles++;
        if (temp_grid[current->y][current->x] == 'E')
            exit_reachable = 1;
        
        // 訪問済みとしてマーク
        temp_grid[current->y][current->x] = 'V'; // 'V'はVisited

        // 上下左右の隣接マスを探索
        // 例: 上方向
        if (current->y > 0 && temp_grid[current->y - 1][current->x] != '1' && temp_grid[current->y - 1][current->x] != 'V')
        {
            // ... キューに追加 ...
        }
        // ... 他の3方向も同様にチェック ...

        free(current);
    }
    
    // すべてのコレクタブルと出口に到達可能かチェック
    if (reachable_collectibles == map->collectible_count && exit_reachable)
    {
        // ... マップのコピーを解放 ...
        return (1);
    }
    
    // ... マップのコピーを解放 ...
    return (0);
}