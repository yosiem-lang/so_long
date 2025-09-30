/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:13:47 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 16:53:36 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_and_add_node(t_list **new_list, \
	void *content, void (*del)(void *))
{
	t_list	*new_node;

	new_node = ft_lstnew(content);
	if (!new_node)
	{
		ft_lstclear(new_list, del);
		return (NULL);
	}
	ft_lstadd_back(new_list, new_node);
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		if (!create_and_add_node(&new_list, new_content, del))
			return (NULL);
		lst = lst->next;
	}
	return (new_list);
}
