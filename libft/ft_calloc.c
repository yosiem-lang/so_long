/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:28:38 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/11 18:34:38 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*calloc;

	if (size != 0 && number > ((size_t)-1) / size)
		return (NULL);
	calloc = (void *)malloc(number * size);
	if (calloc)
		ft_memset(calloc, 0, number * size);
	return (calloc);
}
/* 
int	main(void)
{
	size_t	number;
	size_t	size;
	size_t	i;
	int		*arr;

	number = 5;
	i = 0;
	size = sizeof(int);
	arr = (int *)ft_calloc(number, size);
	if (!arr)
		printf("Memory allocation failed\n");
	else
	{
		while (i < number)
		{
			printf("arr[%zu] = %d\n", i, arr[i]); // すべて 0 であるべき
			i++;
		}
		free(arr);
	}
	return (0);
}
 */