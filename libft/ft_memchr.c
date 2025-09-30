/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:10:24 by yomatsud          #+#    #+#             */
/*   Updated: 2025/04/27 15:47:12 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char *)b;
	while (len > 0)
	{
		if (*s == (unsigned char)c)
			return ((void *)s);
		s++;
		len--;
	}
	return ((void *)0);
}
