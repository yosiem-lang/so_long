/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:51:23 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 17:06:16 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	c;
	int	n;

	c = 1;
	n = 0;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n' || \
			*nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			c = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = 10 * n + (*nptr - '0');
		nptr++;
	}
	return (c * n);
}
/* 
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	else
	{
		printf("%d", ft_atoi(argv[1]));
		return (0);
	}
}
 */