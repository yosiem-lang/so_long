/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:34:30 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 17:19:17 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/* 
int	main(void)
{
	char	buffer[10];
	int		i;

	i = 0;
	strlcpy(buffer, "abcdefghi");
	printf("Before ft_bzero: %s\n", buffer);
	ft_bzero(buffer, 5);
	printf("After ft_bzero: ");
	while (i < 10)
	{
		if (buffer[i] == '\0')
			printf("\\0");
		else
			printf("%c", buffer[i]);
		i++;
	}
	printf("\n");
	return ;
}
 */