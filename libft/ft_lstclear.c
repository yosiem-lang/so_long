/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:12:29 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 17:45:42 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
/* 
typedef struct s_list
{
    int           content;
    struct s_list *next;
} t_list;

// ft_lstadd_front 関数
void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    *lst = new;
}

// ft_lstdelone 関数
void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst || !del)
        return ;
    del(lst->content); // contentを削除する
    free(lst); // ノード自体を解放する
}

// ft_lstclear 関数
void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *tmp;

    if (!lst || !del)
        return ;
    while (*lst)
    {
        tmp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = tmp;
    }
    *lst = NULL;
}

// ノードを新たに作成する関数
t_list *create_node(int content)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// contentを削除する関数（freeを使う）
void del(void *content)
{
    free(content); // メモリ解放
}

// リストの表示用関数
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(void)
{
    t_list *head = NULL;
    t_list *new_node;

    // 最初のノードを追加
    new_node = create_node(42);
    ft_lstadd_front(&head, new_node);

    // さらにノードを追加
    new_node = create_node(21);
    ft_lstadd_front(&head, new_node);

    // リストを表示
    printf("List before clear: ");
    print_list(head);

    // リストのノードをすべて削除
    ft_lstclear(&head, del);

    // リストを表示（空であることを確認）
    printf("List after clear: ");
    print_list(head); // 何も表示されないはずです

    return 0;
}
 */