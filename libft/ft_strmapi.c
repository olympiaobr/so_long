/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:09:52 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 20:07:27 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*nstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
/*
char	my_function(unsigned int index, char c)
{
	(void)index;
    return (c + 1);
}

#include <stdio.h>

int main() 
{
    	char const *original_str = "Hello World!";
    	char *modified_str;

    	modified_str = ft_strmapi(original_str, my_function);
    	if (modified_str) 
    	{
        	printf("Original string: %s\n", original_str);
       		printf("Modified string: %s\n", modified_str);
        	free(modified_str);
    	} 
    	else 
    	{
        	printf("Memory allocation failed.\n");
    	}	

    return (0);
}
*/
