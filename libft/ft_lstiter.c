/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:13:09 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 17:47:05 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
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

// リストの各ノードに関数fを適用する関数
void ft_lstiter(t_list *lst, void (*f)(void *))
{
    while (lst && f)
    {
        f(lst->content);
        lst = lst->next;
    }
}

// contentを表示する関数
void print_content(void *content)
{
    printf("%d -> ", *(int *)content);
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
    printf("Original list: ");
    print_list(head);

    // リストの各ノードに関数 print_content を適用
    printf("After ft_lstiter: ");
    ft_lstiter(head, print_content); // 各ノードの content を表示

    // リストを表示
    printf("Original list (again): ");
    print_list(head);

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