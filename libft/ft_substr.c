/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:21:15 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/20 16:49:39 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>
int main() {
    char *result;
    char test_str[] = "Example string for testing";

    result = ft_substr(test_str, 8, 6);
    printf("Test 1 - Substring: '%s'\n", result);
    free(result);

    result = ft_substr(test_str, 30, 5);
    printf("Test 2 - Substring: '%s'\n", result);
    free(result);

    result = ft_substr(test_str, 10, 0);
    printf("Test 3 - Substring: '%s'\n", result);
    free(result);

    result = ft_substr(test_str, 15, 50);
    printf("Test 4 - Substring: '%s'\n", result);
    free(result);

    result = ft_substr(NULL, 5, 5);
    printf("Test 5 - Substring: '%s'\n", result);

    return (0);
}
*/
