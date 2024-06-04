/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:50:00 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/21 11:46:49 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occ;

	last_occ = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occ = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		last_occ = s;
	return ((char *)last_occ);
}
/*
#include <stdio.h>

int main()
{
    const char *s = "In midst of, I found there was, an invincible summer";
    char *last_comma;

    last_comma = ft_strrchr(s, ',');
    if (last_comma != NULL)
    {
        printf("The fragment after the last , is: \"%s\"\n", last_comma + 1);
    }
    else
    {
        printf("No comma found in the sentence.\n");
    }

    return (0);
}
*/
