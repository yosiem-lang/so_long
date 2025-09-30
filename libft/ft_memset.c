/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:25:52 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/11 18:11:57 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		((unsigned char *)dest)[i++] = (unsigned char)c;
	return (dest);
}
/*
int main()
{
	char str1[20] = "Hello, world!";
	char str2[20] = "Hello, world!";

	// Print the original strings
	printf("Original str1: %s\n", str1);
	printf("Original str2: %s\n", str2);

	// Using ft_memset to set the first 5 characters of str1 to 'X'
	ft_memset(str1, 'X', 5);

	// Using the standard memset to compare results
	memset(str2, 'X', 5);

	// Print the results after using ft_memset and memset
	printf("After ft_memset, str1: %s\n", str1);
	printf("After memset, str2: %s\n", str2);

	return 0;
}
*/