/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:02:03 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 11:10:16 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	gets_skipws(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
	{
		(*str)++;
	}
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
	{
		(*str)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	r;

	r = 0;
	sign = gets_skipws(&str);
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (r * sign);
}
/*
#include <stdio.h>
int main(void)
{
    char *str1 = "  ---+--+1234ab567";
    char *str2 = "456";
    char *str3 = "   +789";
    char *str4 = "   -0";
    char *str5 = "   00123";

    printf("String: %s, Integer: %d\n", str1, ft_atoi(str1));
    printf("String: %s, Integer: %d\n", str2, ft_atoi(str2));
    printf("String: %s, Integer: %d\n", str3, ft_atoi(str3));
    printf("String: %s, Integer: %d\n", str4, ft_atoi(str4));
    printf("String: %s, Integer: %d\n", str5, ft_atoi(str5));

    return (0);
}
*/
