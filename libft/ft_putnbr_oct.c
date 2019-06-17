/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:18:00 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:51:24 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putnbr_oct(uintmax_t n)
{
	uintmax_t	nbr;

	nbr = n;
	if (nbr < 8)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr_oct(nbr / 8);
		ft_putchar((nbr % 8) + '0');
	}
}
