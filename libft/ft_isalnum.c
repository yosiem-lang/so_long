/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:49:00 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/11 14:02:00 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("%d\n", ft_isalnum('A')); //1
	printf("%d\n", ft_isalnum('0')); //1
	printf("%d\n", ft_isalnum('a')); //1
	printf("%d\n", ft_isalnum('Z')); //1
	printf("%d\n", ft_isalnum('*')); //0
	printf("%d\n", ft_isalnum('!')); //0
	printf("%d\n", ft_isalnum('z')); //1
	return ;
}
 */