/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:06:56 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:14:48 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

uintmax_t			ft_uintlen(uintmax_t n, unsigned int base)
{
	int				i;
	uintmax_t		n_cpy;

	n_cpy = n;
	i = 1;
	while (n_cpy > (base - 1))
	{
		n_cpy = n_cpy / base;
		i++;
	}
	return (i);
}
