/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:50:01 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:49:36 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_power(int nb, int pwr)
{
	int i;
	int nbr;

	i = 1;
	nbr = 1;
	if (pwr < 0)
		return (0);
	if (pwr == 0)
		return (1);
	while (i <= pwr)
	{
		nbr = nbr * nb;
		i++;
	}
	return (nbr);
}
