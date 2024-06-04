/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:03:10 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/09 15:06:59 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
	{
		return (8);
	}
	else
	{
		return (0);
	}
}
/*
#include <stdio.h>
int	main(void)
{

	char c = '@';
	printf("%d", ft_isalnum(c));
	return (0);
}
*/
