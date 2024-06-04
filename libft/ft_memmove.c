/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:50:42 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 17:39:16 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*dst;
	const unsigned char		*source;

	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (dst == source)
		return (dest);
	if (source < dst)
	{
		i = n;
		while (i-- > 0)
			dst[i] = source[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = source[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int main() 
{
    	char source[] = "Handle overlap";
	char destination[20];

	memmove(destination, source, strlen(source) + 1);
    	printf("Standard memmove result: %s\n", destination);

    	ft_memmove(destination, source, strlen(source) + 1);
    	printf("Custom ft_memmove result: %s\n", destination);
	
	return (0);
}
*/
