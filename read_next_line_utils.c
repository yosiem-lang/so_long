/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:12:19 by yomatsud          #+#    #+#             */
/*   Updated: 2025/10/04 19:34:11 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	get_char(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	byte = 0;

	if (byte <= 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
			return ('\0');
		if (byte == 0)
		{
			bufp = NULL;
			byte = 0;
			return (EOF);
		}
		bufp = buf;
	}
	byte--;
	return ((unsigned char)*bufp++);
}

char	*re_malloc(char *str, size_t i, char c)
{
	size_t	len;
	char	*new_str;

	if (i >= SIZE_MAX - BUFFER_SIZE - 1)
		len = SIZE_MAX;
	else
		len = i + BUFFER_SIZE + 1;
	if (c == '\n')
		len = i + 2;
	new_str = (char *)malloc(len);
	if (!new_str)
	{
		free (str);
		return (NULL);
	}
	ft_memcpy(new_str, str, i);
	free(str);
	return (new_str);
}

char	*put_char(char *str, size_t *i, char c)
{
	if (c == EOF || BUFFER_SIZE == 0)
	{
		if (*i == 0)
		{
			free (str);
			return (NULL);
		}
		str[*i] = '\0';
		return (str);
	}
	if (*i % BUFFER_SIZE == 0 || c == '\n')
	{
		str = re_malloc(str, *i, c);
		if (str == NULL)
			return (NULL);
	}
	str[(*i)++] = c;
	str[*i] = '\0';
	return (str);
}
