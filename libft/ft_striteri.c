/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:33:10 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 11:28:44 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	my_uppercase(unsigned int i, char *c)
{
	(void)i;
	*c = (char)ft_toupper((unsigned char)*c);
}

#include <stdio.h>

int main(void)
{
    char str[] = "uppercase me";

    printf("Before: %s\n", str);

    ft_striteri(str, my_uppercase);

    printf("After: %s\n", str);

    return (0);
}
*/
