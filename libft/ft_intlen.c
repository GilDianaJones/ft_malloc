/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:06:56 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:45:20 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static intmax_t		ft_is_neg(intmax_t nb)
{
	intmax_t		n_cpy;

	if (nb >= 0)
		n_cpy = nb;
	else
		n_cpy = nb * -1;
	return (n_cpy);
}

intmax_t			ft_intlen(intmax_t n)
{
	int				i;
	intmax_t		n_cpy;

	i = 1;
	n_cpy = ft_is_neg(n);
	while (n_cpy > 9)
	{
		n_cpy = n_cpy / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}
