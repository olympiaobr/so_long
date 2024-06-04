/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:49:12 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 17:37:38 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	char str[] = "First occurrence";
	char ch = 'e';
	char *found;

	found = (char *)ft_memchr(str, ch, strlen(str));

	if (found != NULL)
	{
		printf("Char '%c' found at position %ld\n", ch, (found - str));
	}
	else
	{
		printf("Character '%c' not found in string.\n", ch);
	}

	ch = 'x';
	found = (char *)ft_memchr(str, ch, strlen(str));

	if (found != NULL)
	{
		printf("Char '%c' found at position %ld\n", ch, (found - str));
	}
	else
	{
		printf("Character '%c' not found in string.\n", ch);
	}
	
	return (0);
}
*/
