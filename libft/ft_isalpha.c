/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:10:47 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/11 13:55:10 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("%d\n", ft_isalpha('A')); //1
	printf("%d\n", ft_isalpha('z')); //1
	printf("%d\n", ft_isalpha('1')); //0
	printf("%d\n", ft_isalpha('*')); //0
	printf("%d\n", ft_isalpha('m')); //1
	printf("%d\n", ft_isalpha('Z')); //1
	return ;
}
 */