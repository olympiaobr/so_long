/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:51:28 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 11:08:39 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_abs(int n)
{
	long	abs_val;

	abs_val = n;
	if (n < 0)
		abs_val = -(long)n;
	return (abs_val);
}

static int	ft_numlen(long n)
{
	int	len_d;

	len_d = 0;
	if (n <= 0)
	{
		len_d = 1;
		n = -n;
	}
	while (n != 0)
	{
		len_d++;
		n /= 10;
	}
	return (len_d);
}

static void	ft_fillstr(char *arr, long abs_val, int len, int n)
{
	if (n == 0)
		arr[0] = '0';
	else if (n < 0)
		arr[0] = '-';
	while (abs_val != 0)
	{
		len--;
		arr[len] = (abs_val % 10) + '0';
		abs_val /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	abs_val;
	int		len;
	char	*r;

	abs_val = ft_abs(n);
	len = ft_numlen(abs_val);
	if (n < 0)
		len++;
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	r[len] = '\0';
	ft_fillstr(r, abs_val, len, n);
	return (r);
}
/*
#include <stdio.h>

int main()
{
    char *str;

    str = ft_itoa(0);
    printf("0: %s\n", str);
    free(str);

    str = ft_itoa(12345);
    printf("12345: %s\n", str);
    free(str);

    str = ft_itoa(-12345);
    printf("-12345: %s\n", str);
    free(str);

    str = ft_itoa(INT_MAX);
    printf("INT_MAX (%d): %s\n", INT_MAX, str);
    free(str);

    str = ft_itoa(INT_MIN);
    printf("INT_MIN (%d): %s\n", INT_MIN, str);
    free(str);

    return (0);
}
*/
