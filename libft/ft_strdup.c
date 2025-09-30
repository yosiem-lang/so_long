/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:49:35 by yomatsud          #+#    #+#             */
/*   Updated: 2025/04/29 17:51:36 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (i <= len)
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}
