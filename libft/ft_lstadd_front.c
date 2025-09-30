/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:07:02 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 17:45:00 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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

int main(void)
{
    t_list *head = NULL;
    t_list *new_node;

    // 最初のノードを追加
    new_node = create_node(42);
    ft_lstadd_front(&head, new_node);

    // 新しいノードを先頭に追加
    new_node = create_node(21);
    ft_lstadd_front(&head, new_node);

    // リストを表示
    print_list(head);

    // メモリ解放 (省略可能ですが、実際のプログラムでは重要)
    while (head)
    {
        t_list *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
 */