/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:51:28 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/21 12:05:57 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (src_len);
}
/*
#include <stddef.h>
#include <stdio.h>
#include <stddef.h>

int main() 
{
    char source[] = "Badumts";
    char destination[50];

    size_t copied = ft_strlcpy(destination, source, sizeof(destination));

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    printf("Number of characters copied: %zu\n", copied);

    return (0);
}
*/
