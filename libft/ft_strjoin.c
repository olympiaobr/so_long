/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:43:11 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/20 17:16:16 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	r = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, l1 + 1);
	ft_strlcpy(r + l1, s2, l2 + 1);
	return (r);
}
/*
#include <stdio.h>
int main() 
{
    char const *s1 = "Please, ";
    char const *s2 = "be correct!";
    char *result;

    result = ft_strjoin(s1, s2);
    if (result != NULL) 
    {
        printf("Test 1: %s\n", result);
        free(result); 
    } else 
    {
        printf("Test 1: Memory allocation failed\n");
    }

    s1 = "";
    result = ft_strjoin(s1, s2);
    if (result != NULL) 
    {
        printf("Test 2: %s\n", result);
        free(result);
    } else 
    {
        printf("Test 2: Memory allocation failed\n");
    }

    result = ft_strjoin(NULL, s2);
    if (result == NULL) 
    {
        printf("Test 3: Passed (NULL input)\n");
    } else 
    {
        printf("Test 3: Failed (should not concatenate NULL)\n");
        free(result);
    }
    return (0);
}
*/
