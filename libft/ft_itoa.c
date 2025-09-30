/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:24:24 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/11 16:44:27 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(int n)
{
	size_t	len;
	long	nb;

	len = 1;
	nb = n;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	long	nb;

	len = intlen(n);
	str = (char *)malloc(len + 1);
	nb = n;
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
/* 
int main(void)
{
    int test_numbers[] = {123, -456, 0, 987654321, -2147483648};
    size_t num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    // 各整数を文字列に変換して出力
    for (size_t i = 0; i < num_tests; i++)
    {
        int n = test_numbers[i];
        char *str = ft_itoa(n);
        
        if (str)
        {
            printf("ft_itoa(%d) = %s\n", n, str);
            free(str);  // メモリを解放
        }
        else
        {
            printf("ft_itoa(%d) = NULL\n", n);
        }
    }

    return 0;
}
 */