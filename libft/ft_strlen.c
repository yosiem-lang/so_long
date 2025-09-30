/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:17:15 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/11 14:12:57 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (*str)
	{
		str++;
		c++;
	}
	return (c);
}
/* 
int	main(void)
{
	printf("%zu\n", ft_strlen("Hello")); 	  //5
	printf("%zu\n", ft_strlen("")); 		  //0
	printf("%zu\n", ft_strlen("0123456789")); //10
	return ;
}
 */