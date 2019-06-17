/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:34:56 by gthomas           #+#    #+#             */
/*   Updated: 2019/01/02 15:46:07 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "stdarg.h"

void			ld_parse_str(va_list ap, char *fmt, int i)
{
	if (fmt[i] == 's')
		ft_putstr((const char *)va_arg(ap, char *));
}

void			ld_parse_int(va_list ap, char *fmt, int i)
{
	if (fmt[i] == 'd')
		ft_putnbr(va_arg(ap, int));
	if (fmt[i] == 'x')
		ft_putnbr_hex(va_arg(ap, long int));
}

void			ld_parse_p(va_list ap, char *fmt, int i)
{
	if (fmt[i] == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_hex(va_arg(ap, unsigned long int));
	}
}

void			ft_lparsing(va_list ap, char *fmt)
{
	int i;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] && fmt[i] == '%')
		{
			++i;
			ld_parse_str(ap, fmt, i);
			ld_parse_int(ap, fmt, i);
			ld_parse_p(ap, fmt, i);
		}
		else if (fmt[i] && fmt[i] != '\0' && fmt[i] != '%')
		{
			ft_putchar(fmt[i]);
		}
		++i;
	}
}

void			ft_lprintf(char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ft_lparsing(ap, fmt);
	va_end(ap);
}
