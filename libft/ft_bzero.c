/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:44:36 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/14 15:14:12 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr++ = 0;
	}
}
/*
#include <stdio.h>

int main(void) 
{

    char testString[] = "Test this!";
    size_t stringLength = sizeof(testString) - 1;

    printf("Original String: %s\n", testString);

    ft_bzero(testString, stringLength);

    printf("Modified String: %s\n", testString);

    return (0);
}
*/
