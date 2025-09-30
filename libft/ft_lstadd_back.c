/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:10:07 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 17:40:55 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/* 
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ", *(int *)(lst->content));  // ノードの content が整数型であると仮定
		lst = lst->next;
	}
	printf("NULL\n");
}

// 新しいノードを作成する関数
t_list	*new_node(int value)
{
	t_list	*node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = (void *)(size_t)value;  // integer を void* に格納
	node->next = NULL;
	return (node);
}

int main(void)
{
	t_list *list = NULL;  // 初期状態では空のリスト
	t_list *new_node1;
	t_list *new_node2;
	t_list *new_node3;

	// 新しいノードを作成
	new_node1 = new_node(1);
	new_node2 = new_node(2);
	new_node3 = new_node(3);

	// リストが空の時にノードを追加
	ft_lstadd_back(&list, new_node1);
	print_list(list);  // 出力: 1 -> NULL

	// さらにノードを追加
	ft_lstadd_back(&list, new_node2);
	print_list(list);  // 出力: 1 -> 2 -> NULL

	// 最後にさらにノードを追加
	ft_lstadd_back(&list, new_node3);
	print_list(list);  // 出力: 1 -> 2 -> 3 -> NULL

	// メモリ解放
	free(new_node1);
	free(new_node2);
	free(new_node3);

	return 0;
}
 */