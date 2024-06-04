/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:47:34 by olobresh          #+#    #+#             */
/*   Updated: 2024/02/22 18:47:37 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prtchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

int	ft_prthex(unsigned long long hx, char f, int *prt_chrs)
{
	char	*hx_b;
	int		i;

	if (f == 'x')
		hx_b = "0123456789abcdef";
	else
		hx_b = "0123456789ABCDEF";
	if (hx >= 16)
	{
		ft_prthex(hx / 16, f, prt_chrs);
	}
	i = hx % 16;
	write(1, &hx_b[i], 1);
	(*prt_chrs)++;
	return (*prt_chrs);
}

void	ft_prtint(int nb, int *len)
{
	if (nb == -2147483648)
	{
		ft_prtchar('-', len);
		ft_prtchar('2', len);
		ft_prtint(147483648, len);
	}
	else if (nb < 0)
	{
		nb = -nb;
		ft_prtchar('-', len);
		ft_prtint(nb, len);
	}
	else if (nb > 9)
	{
		ft_prtint(nb / 10, len);
		ft_prtint(nb % 10, len);
	}
	else
	{
		ft_prtchar(nb + '0', len);
	}
}

int	ft_prtptr(void *ptr, int *len)
{
	unsigned long long	ptr_a;

	if (!ptr)
	{
		return (ft_prtstr("(nil)", len));
	}
	ptr_a = (unsigned long long)ptr;
	ft_prtstr("0x", len);
	return (ft_prthex(ptr_a, 'x', len)); 
}

int	ft_prtstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		str = "(null)";
	}
	while (str[i] != '\0')
	{
		ft_prtchar(str[i], len);
		i++;
	}
	return (*len);
}
