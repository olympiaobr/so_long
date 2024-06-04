/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:38:07 by olobresh          #+#    #+#             */
/*   Updated: 2023/12/05 12:20:37 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

void	ft_prtchar(char c, int *len);
int		ft_prtstr(char *str, int *len);
void	ft_prtint(int nb, int *len);
void	ft_prtunsint(unsigned int nb, int *len);
int		ft_prthex(unsigned long long hx, char f, int *prt_chrs);
int		ft_prtptr(void *ptr, int *len);

int		ft_printf(const char *f, ...);

#endif
