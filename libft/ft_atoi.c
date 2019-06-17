/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:54:49 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:45:00 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_str_plus_spaces(char const *s)
{
	int i;

	i = 0;
	if ((s[0] == 32 || (s[0] >= 8 && s[0] <= 13)) && s[0] > 0)
	{
		while ((s[i] == 32 || (s[i] >= 8 && s[i] <= 13)) && s[i] > 0)
			i++;
	}
	if ((s[i] == '+' && (s[i - 1] == 32 || (s[i - 1] >= 8 && s[i - 1] <= 13)) \
		&& i > 0) || (s[0] == '+'))
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		res;
	int		i;
	int		neg;

	res = 0;
	i = 0;
	neg = 1;
	i = ft_str_plus_spaces(str);
	if (((str[i - 1] == 32 || (str[i - 1] >= 8 && str[i - 1] <= 13)) \
		&& i > 0 && str[i] == '-') || (str[0] == '-'))
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	res *= neg;
	return (res);
}
