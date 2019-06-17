/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:58:46 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:14:55 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_charwlen(wchar_t c)
{
	if (c > 0x800)
		return (c > 0x10000 ? 4 : 3);
	return (c > 0x80 ? 2 : 1);
}

int		ft_strwlen(wchar_t *str)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (str[i])
	{
		l += ft_charwlen(str[i]);
		i++;
	}
	return (l);
}

void	ft_putwchar(wchar_t c)
{
	if (c >= 0x10000)
		ft_putchar(((c & 0x1c0000) >> 18) + 0xF0);
	if (c >= 0x800)
		ft_putchar(c >= 0x10000 ? ((c & 0x03F000) >> 12) + 0x80 :
		((c & 0xF000) >> 12) + 0xE0);
	if (c >= 0x80)
		ft_putchar(c >= 0x800 ? ((c & 0x0Fc0) >> 6) + 0x80 :
		((c & 0x07c0) >> 6) + 0xc0);
	ft_putchar(c >= 0x80 ? (c & 0x003F) + 0x80 : c);
}

void	ft_putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		i++;
	}
}
