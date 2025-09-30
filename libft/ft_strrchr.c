/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:29:03 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 16:30:08 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	temp = NULL;
	c = (char)c;
	while (*s)
	{
		if (*s == c)
			temp = s;
		s++;
	}
	if (*s == c)
		temp = s;
	return ((char *)temp);
}
