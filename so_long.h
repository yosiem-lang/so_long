#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
    char    **grid;     // マップの二次元配列
    int     width;      // マップの幅
    int     height;     // マップの高さ
    int     player_x;   // プレイヤーの初期X座標
    int     player_y;   // プレイヤーの初期Y座標
    int     collectible_count; // コレクタブルの総数
}   t_map;

#endif