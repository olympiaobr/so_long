/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:15:46 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 11:59:26 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_s;

	total_s = count * size;
	if (size != 0 && count != total_s / size)
		return (NULL);
	ptr = malloc(total_s);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_s);
	return (ptr);
}
/*
#include <stdio.h>
int main(void)
{
    int     *arr;
    size_t  i;
    size_t  n;

    n = 10;
    arr = (int *)ft_calloc(n, sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return (1);
    }

    i = 0;
    while (i < n)
    {
        if (arr[i] != 0)
        {
            printf("Error: Memory not initialized to zero at index %zu\n", i);
            free(arr);
            return (1);
        }
        i++;
    }
    printf("Success: All memory is initialized to zero\n");
    free(arr);
    return (0);
}
*/
