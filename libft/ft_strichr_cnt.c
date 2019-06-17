/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:13:57 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:10:25 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_strichr_cnt(const char *str, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			++cnt;
		++i;
	}
	return (cnt);
}
