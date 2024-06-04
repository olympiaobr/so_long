/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:32:05 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/21 11:47:59 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stddef.h>
#include <stdio.h>
int main()
{
	const char *str = "Example sentence";
	char c1 = 's';
	char c2 = 'o';
	char c3 = '\0';

	char *result1 = ft_strchr(str, c1);
	char *result2 = ft_strchr(str, c2);
	char *result3 = ft_strchr(str, c3);
	
	if (result1 != NULL)
		printf("Character '%c' found in \"%s\": \"%s\"\n", c1, str, result1);
	else
		printf("Character '%c' not found in \"%s\"\n", c1, str);

	if (result2 != NULL)
		printf("Character '%c' found in \"%s\": \"%s\"\n", c2, str, result2);
	else
		printf("Character '%c' not found in \"%s\"\n", c2, str);

	printf("Search for null character in \"%s\": \"%s\"\n", str, result3);

	return (0);
}
*/
