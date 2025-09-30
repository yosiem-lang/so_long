/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:52:25 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/11 15:18:48 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("%d\n", ft_isascii('A')); //1
	printf("%d\n", ft_isascii(128)); //0
	printf("%d\n", ft_isascii(127)); //1
	printf("%d\n", ft_isascii(-1));  //0
	return ;
}
 */