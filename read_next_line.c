/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:41:20 by oshie             #+#    #+#             */
/*   Updated: 2025/09/30 11:56:53 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_next_line(int fd)
{
	char	*line_str;
	size_t	i;
	char	c;

	i = 0;
	line_str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		c = get_char(fd);
		if (c == '\0')
		{
			if (line_str)
				free (line_str);
			return (NULL);
		}
		line_str = put_char(line_str, &i, c);
		if (line_str == NULL)
			return (NULL);
		if (c == '\n' || c == EOF)
			return (line_str);
	}
}
