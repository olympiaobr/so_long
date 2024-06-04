/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:24:17 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 20:08:25 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] 
		&& i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>

int main() 
{
	char *str1 = "Galactic Odyssey";
    	char *str2 = "Galactic Expedition";
    	char *str3 = "Stellar Journey";

    	printf("%d\n", str1, str2, ft_strncmp(str1, str2, 8));

    	printf("%d\n", str1, str3, ft_strncmp(str1, str3, 10));

   	printf("%d\n", str1, emptyStr, ft_strncmp(str1, emptyStr, 5));

    	return (0);
}
*/
