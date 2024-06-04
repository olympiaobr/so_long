/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:49:03 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/09 18:09:28 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = str;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (str);
}
/*
#include <stddef.h>
#include <unistd.h>
int main(void)
{
    char buffer[10];
    size_t i;

    ft_memset(buffer, '.', 10);

    // Print buffer after the first memset
    i = 0;
    while (i < 10)
    {
        write(1, &buffer[i], 1);
        i++;
    }
    write(1, "\n", 1);

    ft_memset(buffer, 'A', 5);

    // Print buffer after the second memset
    i = 0;
    while (i < 10)
    {
        write(1, &buffer[i], 1);
        i++;
    }
    write(1, "\n", 1);

    return (0);
}
*/
