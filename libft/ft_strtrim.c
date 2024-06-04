/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:56:39 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/20 16:47:23 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_i;
	size_t	e_i;
	size_t	tr_len;

	if (!s1 || !set)
		return (NULL);
	s_i = 0;
	while (s1[s_i] && ft_strchr(set, s1[s_i]))
		s_i++;
	e_i = ft_strlen(s1);
	while (e_i > s_i && ft_strchr(set, s1[e_i -1]))
		e_i--;
	tr_len = e_i - s_i;
	return (ft_substr(s1, s_i, tr_len));
}
/*
#include <stdio.h>

int main() 
{
    char *result;

    // Test Case 1
    result = ft_strtrim("  Lorem ipsum dolor sit amet  ", " ");
    printf("Test 1: \"%s\"\n", result);
    free(result);

    // Test Case 2
    result = ft_strtrim("!!!---example---!!!", "!-");
    printf("Test 2: \"%s\"\n", result);
    free(result);

    // Test Case 3
    result = ft_strtrim("foobarbaz", "fz");
    printf("Test 3: \"%s\"\n", result);
    free(result);

    // Test Case 4
    result = ft_strtrim("2023-11-15", "1234567890-");
    printf("Test 4: \"%s\"\n", result);
    free(result);

    // Test Case 5
    result = ft_strtrim("ft_strtrim_test", "ft_");
    printf("Test 5: \"%s\"\n", result);
    free(result);

    return 0;
}
*/
