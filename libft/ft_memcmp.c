/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:48:05 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 16:52:29 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *)b1;
	m2 = (unsigned char *)b2;
	while (len > 0)
	{
		if (*m1 != *m2)
			return ((int)(*m1 - *m2));
		m1++;
		m2++;
		len--;
	}
	return (0);
}
