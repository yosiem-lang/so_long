/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:48:10 by oshie             #+#    #+#             */
/*   Updated: 2025/10/04 19:54:30 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enqueue(t_node **queue, int x, int y)
{
	t_node	*new_node;
	t_node	*cur;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	if (!*queue)
		*queue = new_node;
	else
	{
		cur = *queue;
		while (cur->next)
			cur = cur->next;
		cur->next = new_node;
	}
}

t_node	*dequeue(t_node **queue)
{
	t_node	*first;

	if (!*queue)
		return (NULL);
	first = *queue;
	*queue = (*queue)->next;
	return (first);
}

void	free_grid_copy(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(grid[i++]);
	free(grid);
}

char	**copy_grid(char **grid, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = malloc(ft_strlen(grid[i]) + 1);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		ft_strlcpy(copy[i], grid[i], ft_strlen(grid[i]) + 1);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
