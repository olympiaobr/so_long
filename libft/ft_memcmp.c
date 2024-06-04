/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:55:58 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 17:38:15 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n--)
	{
		if (*p1 != *p2)
			return ((int)(*p1 - *p2));
		p1++;
		p2++;
	}
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	char str1[] = "Differ";
    	char str2[] = "Diffe";
    	int result1;
    	int result2;

    	result1 = ft_memcmp(str1, str2, 6);
    	printf("My ft memcmp: %d\n", result1);
    	result2 = memcmp(str1, str2, 6);
    	printf("Standard memcmp: %d\n", result2);

    	return (0);
}
*/
