/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:52:05 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/20 15:53:53 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
/*
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main()
{
    char    dest[50];
    char    *src = " this";
    size_t  result;

    // Test 1: Destination buffer is big enough
    strcpy(dest, "Concatenate");
    result = ft_strlcat(dest, src, 50);
    printf("Test 1 (enough space): '%s', Result: %zu\n", dest, result);

    // Test 2: Destination buffer is exactly enough
    strcpy(dest, "Concatenate");
    result = ft_strlcat(dest, src, 17);
    printf("Test 2 (exact space): '%s', Result: %zu\n", dest, result);

    // Test 3: Destination buffer is not big enough
    strcpy(dest, "Concatenate");
    result = ft_strlcat(dest, src, 10);
    printf("Test 3 (not enough space): '%s', Result: %zu\n", dest, result);

    return 0;
}
*/
