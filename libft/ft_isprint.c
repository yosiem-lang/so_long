/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:11:25 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/11 15:19:04 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("%d\n", ft_isprint(' ')); //1
	printf("%d\n", ft_isprint('~')); //1
	printf("%d\n", ft_isprint('A')); //1
	printf("%d\n", ft_isprint('0')); //1
	printf("%d\n", ft_isprint('\n'));//0
	printf("%d\n", ft_isprint(127)); //0
	printf("%d\n", ft_isprint(1));   //0
	return ;
}
 */