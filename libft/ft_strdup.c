/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:44:48 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 11:35:22 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>

int main() {
    char *original;
    char *duplicate;

    // Test 1: Normal string
    original = "Hello World";
    duplicate = ft_strdup(original);
    printf("Original: %s\nDuplicate: %s\n\n", original, duplicate);
    free(duplicate);

    // Test 2: Empty string
    original = "";
    duplicate = ft_strdup(original);
    printf("Original: %s\nDuplicate: %s\n\n", original, duplicate);
    free(duplicate);

    original = NULL;
    duplicate = ft_strdup(original);
    if (duplicate == NULL) {
    printf("Handled NULL input correctly.\n");
     } else {
         printf("Duplicate: %s\n", duplicate);
         free(duplicate);
     }

    return 0;
}
*/
