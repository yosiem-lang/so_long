/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:55:25 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 16:25:35 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/* 
int	main()
{
        char    buff[10];
        int     i1;

        for (i1 = 0; i1 < 10; i1++)
        {
                buff[i1] = i1;
        }

        printf("1.");
        for (i1 = 0; i1 < 10; i1++)
        {
                printf("[%d]", buff[i1]);
        }
        printf("\n2.");

        ft_memcpy(buff + 1, buff, 9);

        for (i1 = 0; i1 < 10; i1++)
        {
                printf("[%d]", buff[i1]);
        }

        for (i1 = 0; i1 < 10; i1++)
        {
                buff[i1] = i1;
        }

        printf("\n3.");
        for (i1 = 0; i1 < 10; i1++)
        {
                printf("[%d]", buff[i1]);
        }
        printf("\n4.");

        memmove(buff + 1, buff, 9);

        for (i1 = 0; i1 < 10; i1++)
        {
                printf("[%d]", buff[i1]);
        }
}
 */