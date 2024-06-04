/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:52:30 by olobresh          #+#    #+#             */
/*   Updated: 2023/12/08 13:02:37 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prtunsint(unsigned int nb, int *len)
{
	if (nb >= 10)
		ft_prtunsint(nb / 10, len);
	ft_prtchar(nb % 10 + '0', len);
}

void	conv_case(char f, va_list args, int *char_sum)
{
	if (f == 'c')
		(ft_prtchar(va_arg(args, int), char_sum));
	else if (f == 's')
		(ft_prtstr(va_arg(args, char*), char_sum));
	else if (f == 'p')
		(ft_prtptr(va_arg(args, void *), char_sum));
	else if (f == 'd' || f == 'i')
		(ft_prtint(va_arg(args, int), char_sum));
	else if (f == 'u')
		(ft_prtunsint(va_arg(args, unsigned int), char_sum));
	else if (f == 'x' || f == 'X')
		(ft_prthex(va_arg(args, unsigned int), f, char_sum));
	else if (f == '%')
	{
		write(1, "%", 1);
		(*char_sum)++;
	}
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		char_sum;
	int		i;

	if (!f)
		return (-1);
	va_start(args, f);
	char_sum = 0;
	i = 0;
	while (f[i])
	{
		if (f[i] == '%' && f[++i])
			conv_case(f[i], args, &char_sum);
		else if (f[i])
		{
			ft_prtchar(f[i], &char_sum);
		}
		i++;
	}
	va_end(args);
	return (char_sum);
}
