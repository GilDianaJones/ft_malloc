/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:06:56 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:46:15 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static unsigned int	ft_is_neg(int nb)
{
	unsigned int	n_cpy;

	if (nb >= 10)
		n_cpy = nb;
	else
		n_cpy = nb * -1;
	return (n_cpy);
}

static char			*ft_strnbr(int n, char *new, int i)
{
	unsigned int	nbr;

	nbr = 10;
	if (n < 0)
	{
		nbr = n * -1;
		new[0] = '-';
	}
	if (n < 10 && n >= 0)
		new[0] = n + '0';
	if (nbr < 10 && n < 10)
		new[i] = nbr + '0';
	new[i] = '\0';
	if (n > 9)
		nbr = n;
	while (nbr > 0 && i > 0)
	{
		i--;
		if (nbr > 9)
			new[i] = (nbr % 10) + '0';
		else
			new[i] = nbr + '0';
		nbr = nbr / 10;
	}
	return (new);
}

char				*ft_itoa(int n)
{
	char			*new;
	int				i;
	unsigned int	n_cpy;

	i = 1;
	n_cpy = ft_is_neg(n);
	while (n_cpy > 9)
	{
		n_cpy = n_cpy / 10;
		i++;
	}
	if (n < 0)
		i++;
	if (!(new = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	else
	{
		return (ft_strnbr(n, new, i));
	}
	return (NULL);
}
