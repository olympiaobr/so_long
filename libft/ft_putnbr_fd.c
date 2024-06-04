/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:20:10 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/20 12:15:28 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
/*
int	main(void)
{	
	ft_putnbr_fd(123, 1);
	ft_putchar_fd('\n', 1);
	
	ft_putnbr_fd(-456, 1);
	ft_putchar_fd('\n', 1);
	
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);

	return (0);
}
*/
