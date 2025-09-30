/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:09:34 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 17:47:36 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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

// リストの最後のノードを返す関数
t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return NULL;
    while (lst->next)
        lst = lst->next;
    return lst;
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

    // ノードを追加
    new_node = create_node(42);
    ft_lstadd_front(&head, new_node);
    new_node = create_node(21);
    ft_lstadd_front(&head, new_node);
    new_node = create_node(84);
    ft_lstadd_front(&head, new_node);

    // リストを表示
    printf("List: ");
    print_list(head);

    // リストの最後のノードを取得
    t_list *last_node = ft_lstlast(head);
    if (last_node)
        printf("Last node content: %d\n", last_node->content);
    else
        printf("The list is empty.\n");

    // メモリ解放
    while (head)
    {
        t_list *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
 */