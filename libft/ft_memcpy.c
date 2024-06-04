/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:38:06 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/21 11:50:00 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		byte_i;
	char		*dest_str;
	const char	*src_str;

	if (!dest && !src)
		return (NULL);
	dest_str = (char *)dest;
	src_str = (const char *)src;
	byte_i = 0;
	while (byte_i < n)
	{
		dest_str[byte_i] = src_str[byte_i];
		byte_i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stddef.h>

int main() 
{
	const char src[] = "Copied here";
	char dest[50];

	printf("Before memcpy dest = %s\n", dest);

	ft_memcpy(dest, src, sizeof(src));

	printf("After memcpy dest = %s\n", dest);

	return (0);
}
*/
