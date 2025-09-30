/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:06:49 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/10 16:27:36 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (dest < src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	if (dest > src)
	{
		while (len > 0)
		{
			len--;
			((unsigned char *)dest)[len] = ((const unsigned char *)src)[len];
		}
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

        memcpy(buff + 1, buff, 9);

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

        ft_memmove(buff + 1, buff, 9);

        for (i1 = 0; i1 < 10; i1++)
        {
                printf("[%d]", buff[i1]);
        }
}
*/