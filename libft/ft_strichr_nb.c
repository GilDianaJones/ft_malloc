/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:11:28 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:10:50 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_strichr_nb(const char *str, char c, int nb)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	if (nb < 0)
		return (0);
	while (str && str[i])
	{
		if (str[i] == c)
			++cnt;
		if (cnt == nb)
			return (i);
		++i;
	}
	return (-1);
}
