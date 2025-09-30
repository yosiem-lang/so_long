/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:45:20 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/11 13:58:52 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("%d\n", ft_isdigit('A')); //0
	printf("%d\n", ft_isdigit('0')); //1
	printf("%d\n", ft_isdigit('9')); //1
	printf("%d\n", ft_isdigit('a')); //0
	printf("%d\n", ft_isdigit('*')); //0
	printf("%d\n", ft_isdigit('Z')); //0
	return ;
}
 */